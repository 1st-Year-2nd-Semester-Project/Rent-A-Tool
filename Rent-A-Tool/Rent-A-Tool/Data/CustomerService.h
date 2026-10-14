#pragma once
#include "Dbconfig.h"
#include "CodeGenerator.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace RentATool {
namespace Data {

    public ref class CustomerService abstract sealed {
    public:
        // Get all customers with search filter
        static DataTable^ GetAllCustomers(String^ searchQuery) {
            DataTable^ table = gcnew DataTable();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ query = "SELECT c.id, c.cust_code, c.name, c.nic, c.phone, c.email, c.address, "
                                "CASE WHEN c.is_blacklisted = 1 THEN 'Blacklisted' ELSE 'Clear' END AS blacklist_status, "
                                "c.is_blacklisted, c.created_at, "
                                "(SELECT COUNT(*) FROM rentals r WHERE r.customer_id = c.id) AS total_rentals "
                                "FROM customers c WHERE 1=1 ";

                if (!String::IsNullOrWhiteSpace(searchQuery)) {
                    query += " AND (c.cust_code LIKE @search OR c.name LIKE @search OR c.nic LIKE @search OR c.phone LIKE @search) ";
                }

                query += " ORDER BY c.id DESC";

                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                if (!String::IsNullOrWhiteSpace(searchQuery)) {
                    cmd->Parameters->AddWithValue("@search", "%" + searchQuery->Trim() + "%");
                }

                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
                adapter->Fill(table);
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error loading customers: " + ex->Message);
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
            return table;
        }

        // Get customers allowed to rent tools (not blacklisted)
        static DataTable^ GetEligibleCustomers() {
            DataTable^ table = gcnew DataTable();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ query = "SELECT id, cust_code, name, nic, phone "
                                "FROM customers WHERE is_blacklisted = 0 ORDER BY name ASC";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
                adapter->Fill(table);
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error loading eligible customers: " + ex->Message);
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
            return table;
        }

        // Add a customer with auto-generated code and retry mechanism on concurrency conflict (MySQL 1062).
        // Returns empty string on success and outputs assignedCode; returns error message on failure.
        static String^ AddCustomer([Runtime::InteropServices::Out] String^% assignedCode,
                                   String^ name, String^ nic, String^ phone,
                                   String^ email, String^ address, bool isBlacklisted) {
            const int maxRetries = 5;
            for (int attempt = 1; attempt <= maxRetries; attempt++) {
                MySqlConnection^ conn = nullptr;
                try {
                    conn = Db::GetConnection();
                    String^ code = CodeGenerator::GetNextCustomerCode(conn);
                    assignedCode = code;

                    String^ insertQuery = "INSERT INTO customers (cust_code, name, nic, phone, email, address, is_blacklisted) "
                                          "VALUES (@code, @name, @nic, @phone, @email, @address, @bl)";
                    MySqlCommand^ cmd = gcnew MySqlCommand(insertQuery, conn);
                    cmd->Parameters->AddWithValue("@code", code);
                    cmd->Parameters->AddWithValue("@name", name ? name->Trim() : "");
                    cmd->Parameters->AddWithValue("@nic", nic ? nic->Trim() : "");
                    cmd->Parameters->AddWithValue("@phone", phone ? phone->Trim() : "");
                    cmd->Parameters->AddWithValue("@email", email ? email->Trim() : "");
                    cmd->Parameters->AddWithValue("@address", address ? address->Trim() : "");
                    cmd->Parameters->AddWithValue("@bl", isBlacklisted ? 1 : 0);

                    cmd->ExecuteNonQuery();
                    return "";
                }
                catch (MySqlException^ sqlEx) {
                    if (sqlEx->Number == 1062 && attempt < maxRetries) {
                        System::Threading::Thread::Sleep(50 * attempt);
                        continue;
                    }
                    return "DB Error: " + sqlEx->Message;
                }
                catch (Exception^ ex) {
                    return "DB Error: " + ex->Message;
                }
                finally {
                    if (conn != nullptr) conn->Close();
                }
            }
            return "Failed to assign a unique customer code after multiple attempts. Please try again.";
        }

        // Overload for manual or legacy customer code specification
        static String^ AddCustomerWithCode(String^ code, String^ name, String^ nic, String^ phone,
                                           String^ email, String^ address, bool isBlacklisted) {
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ insertQuery = "INSERT INTO customers (cust_code, name, nic, phone, email, address, is_blacklisted) "
                                      "VALUES (@code, @name, @nic, @phone, @email, @address, @bl)";
                MySqlCommand^ cmd = gcnew MySqlCommand(insertQuery, conn);
                cmd->Parameters->AddWithValue("@code", code ? code->Trim() : "");
                cmd->Parameters->AddWithValue("@name", name ? name->Trim() : "");
                cmd->Parameters->AddWithValue("@nic", nic ? nic->Trim() : "");
                cmd->Parameters->AddWithValue("@phone", phone ? phone->Trim() : "");
                cmd->Parameters->AddWithValue("@email", email ? email->Trim() : "");
                cmd->Parameters->AddWithValue("@address", address ? address->Trim() : "");
                cmd->Parameters->AddWithValue("@bl", isBlacklisted ? 1 : 0);

                cmd->ExecuteNonQuery();
                return "";
            }
            catch (Exception^ ex) {
                return "DB Error: " + ex->Message;
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
        }

        // Update a customer
        static String^ UpdateCustomer(int id, String^ code, String^ name, String^ nic, String^ phone,
                                      String^ email, String^ address, bool isBlacklisted) {
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();

                // Check duplicate customer code
                MySqlCommand^ checkCmd = gcnew MySqlCommand("SELECT COUNT(*) FROM customers WHERE cust_code=@code AND id != @id", conn);
                checkCmd->Parameters->AddWithValue("@code", code->Trim());
                checkCmd->Parameters->AddWithValue("@id", id);
                int count = Convert::ToInt32(checkCmd->ExecuteScalar());
                if (count > 0) return "Another customer with code '" + code + "' already exists.";

                String^ updateQuery = "UPDATE customers SET cust_code=@code, name=@name, nic=@nic, phone=@phone, "
                                      "email=@email, address=@address, is_blacklisted=@bl WHERE id=@id";
                MySqlCommand^ cmd = gcnew MySqlCommand(updateQuery, conn);
                cmd->Parameters->AddWithValue("@code", code->Trim());
                cmd->Parameters->AddWithValue("@name", name->Trim());
                cmd->Parameters->AddWithValue("@nic", nic ? nic->Trim() : "");
                cmd->Parameters->AddWithValue("@phone", phone ? phone->Trim() : "");
                cmd->Parameters->AddWithValue("@email", email ? email->Trim() : "");
                cmd->Parameters->AddWithValue("@address", address ? address->Trim() : "");
                cmd->Parameters->AddWithValue("@bl", isBlacklisted ? 1 : 0);
                cmd->Parameters->AddWithValue("@id", id);

                cmd->ExecuteNonQuery();
                return "";
            }
            catch (Exception^ ex) {
                return "DB Error: " + ex->Message;
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
        }

        // Toggle blacklist status
        static String^ ToggleBlacklist(int id, bool isBlacklisted) {
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                MySqlCommand^ cmd = gcnew MySqlCommand("UPDATE customers SET is_blacklisted=@bl WHERE id=@id", conn);
                cmd->Parameters->AddWithValue("@bl", isBlacklisted ? 1 : 0);
                cmd->Parameters->AddWithValue("@id", id);
                cmd->ExecuteNonQuery();
                return "";
            }
            catch (Exception^ ex) {
                return "DB Error: " + ex->Message;
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
        }

        // Delete customer
        static String^ DeleteCustomer(int id) {
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();

                MySqlCommand^ checkCmd = gcnew MySqlCommand("SELECT COUNT(*) FROM rentals WHERE customer_id=@id", conn);
                checkCmd->Parameters->AddWithValue("@id", id);
                int count = Convert::ToInt32(checkCmd->ExecuteScalar());
                if (count > 0) {
                    return "Cannot delete this customer because rental history records are linked to them.";
                }

                MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM customers WHERE id=@id", conn);
                cmd->Parameters->AddWithValue("@id", id);
                cmd->ExecuteNonQuery();
                return "";
            }
            catch (Exception^ ex) {
                return "DB Error: " + ex->Message;
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
        }
    };
}
}
