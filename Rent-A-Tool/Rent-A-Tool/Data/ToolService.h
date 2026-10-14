#pragma once
#include "Dbconfig.h"
#include "CodeGenerator.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace RentATool {
namespace Data {

    public ref class ToolService abstract sealed {
    public:
        // Retrieve tools with optional filters
        static DataTable^ GetAllTools(String^ searchQuery, String^ categoryFilter, String^ statusFilter) {
            DataTable^ table = gcnew DataTable();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ query = "SELECT id, tool_code, name, category, daily_rate, deposit, status, "
                                "brand, model_serial, condition_status, created_at "
                                "FROM tools WHERE 1=1 ";

                if (!String::IsNullOrWhiteSpace(searchQuery)) {
                    query += " AND (tool_code LIKE @search OR name LIKE @search OR brand LIKE @search) ";
                }
                if (!String::IsNullOrWhiteSpace(categoryFilter) && categoryFilter != "All") {
                    query += " AND category = @category ";
                }
                if (!String::IsNullOrWhiteSpace(statusFilter) && statusFilter != "All") {
                    query += " AND status = @status ";
                }

                query += " ORDER BY id DESC";

                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                if (!String::IsNullOrWhiteSpace(searchQuery)) {
                    cmd->Parameters->AddWithValue("@search", "%" + searchQuery->Trim() + "%");
                }
                if (!String::IsNullOrWhiteSpace(categoryFilter) && categoryFilter != "All") {
                    cmd->Parameters->AddWithValue("@category", categoryFilter);
                }
                if (!String::IsNullOrWhiteSpace(statusFilter) && statusFilter != "All") {
                    cmd->Parameters->AddWithValue("@status", statusFilter);
                }

                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
                adapter->Fill(table);
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error loading tools: " + ex->Message);
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
            return table;
        }

        // Retrieve only tools available for rental
        static DataTable^ GetAvailableTools() {
            DataTable^ table = gcnew DataTable();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ query = "SELECT id, tool_code, name, category, daily_rate, deposit "
                                "FROM tools WHERE status = 'Available' ORDER BY name ASC";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
                adapter->Fill(table);
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error loading available tools: " + ex->Message);
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
            return table;
        }

        // Get list of unique tool categories
        static List<String^>^ GetCategories() {
            List<String^>^ categories = gcnew List<String^>();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ query = "SELECT DISTINCT category FROM tools WHERE category IS NOT NULL AND category != '' ORDER BY category ASC";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                MySqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    categories->Add(reader->GetString(0));
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error loading categories: " + ex->Message);
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
            return categories;
        }

        // Add a new tool with auto-generated code and retry mechanism on concurrency conflict (MySQL 1062).
        // Returns empty string on success and outputs the assigned code; returns error message on failure.
        static String^ AddTool([Runtime::InteropServices::Out] String^% assignedCode,
                               String^ name, String^ category, Decimal dailyRate, Decimal deposit,
                               String^ status, String^ brand, String^ modelSerial, String^ notes) {
            const int maxRetries = 5;
            for (int attempt = 1; attempt <= maxRetries; attempt++) {
                MySqlConnection^ conn = nullptr;
                try {
                    conn = Db::GetConnection();
                    String^ code = CodeGenerator::GetNextToolCode(conn);
                    assignedCode = code;

                    String^ insertQuery = "INSERT INTO tools (tool_code, name, category, daily_rate, deposit, status, brand, model_serial, notes) "
                                          "VALUES (@code, @name, @cat, @rate, @dep, @stat, @brand, @model, @notes)";
                    MySqlCommand^ cmd = gcnew MySqlCommand(insertQuery, conn);
                    cmd->Parameters->AddWithValue("@code", code);
                    cmd->Parameters->AddWithValue("@name", name ? name->Trim() : "");
                    cmd->Parameters->AddWithValue("@cat", category);
                    cmd->Parameters->AddWithValue("@rate", dailyRate);
                    cmd->Parameters->AddWithValue("@dep", deposit);
                    cmd->Parameters->AddWithValue("@stat", status);
                    cmd->Parameters->AddWithValue("@brand", brand ? brand->Trim() : "");
                    cmd->Parameters->AddWithValue("@model", modelSerial ? modelSerial->Trim() : "");
                    cmd->Parameters->AddWithValue("@notes", notes ? notes->Trim() : "");

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
            return "Failed to assign a unique tool code after multiple attempts. Please try again.";
        }

        // Overload for manual or legacy code specification
        static String^ AddToolWithCode(String^ code, String^ name, String^ category, Decimal dailyRate, Decimal deposit,
                                       String^ status, String^ brand, String^ modelSerial, String^ notes) {
            String^ assigned = code;
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ insertQuery = "INSERT INTO tools (tool_code, name, category, daily_rate, deposit, status, brand, model_serial, notes) "
                                      "VALUES (@code, @name, @cat, @rate, @dep, @stat, @brand, @model, @notes)";
                MySqlCommand^ cmd = gcnew MySqlCommand(insertQuery, conn);
                cmd->Parameters->AddWithValue("@code", code ? code->Trim() : "");
                cmd->Parameters->AddWithValue("@name", name ? name->Trim() : "");
                cmd->Parameters->AddWithValue("@cat", category);
                cmd->Parameters->AddWithValue("@rate", dailyRate);
                cmd->Parameters->AddWithValue("@dep", deposit);
                cmd->Parameters->AddWithValue("@stat", status);
                cmd->Parameters->AddWithValue("@brand", brand ? brand->Trim() : "");
                cmd->Parameters->AddWithValue("@model", modelSerial ? modelSerial->Trim() : "");
                cmd->Parameters->AddWithValue("@notes", notes ? notes->Trim() : "");

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

        // Update an existing tool
        static String^ UpdateTool(int id, String^ code, String^ name, String^ category, Decimal dailyRate, Decimal deposit,
                                  String^ status, String^ brand, String^ modelSerial, String^ notes) {
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();

                // Check duplicate code
                MySqlCommand^ checkCmd = gcnew MySqlCommand("SELECT COUNT(*) FROM tools WHERE tool_code=@code AND id != @id", conn);
                checkCmd->Parameters->AddWithValue("@code", code->Trim());
                checkCmd->Parameters->AddWithValue("@id", id);
                int count = Convert::ToInt32(checkCmd->ExecuteScalar());
                if (count > 0) return "Another tool with code '" + code + "' already exists.";

                String^ updateQuery = "UPDATE tools SET tool_code=@code, name=@name, category=@cat, daily_rate=@rate, "
                                      "deposit=@dep, status=@stat, brand=@brand, model_serial=@model, notes=@notes WHERE id=@id";
                MySqlCommand^ cmd = gcnew MySqlCommand(updateQuery, conn);
                cmd->Parameters->AddWithValue("@code", code->Trim());
                cmd->Parameters->AddWithValue("@name", name->Trim());
                cmd->Parameters->AddWithValue("@cat", category);
                cmd->Parameters->AddWithValue("@rate", dailyRate);
                cmd->Parameters->AddWithValue("@dep", deposit);
                cmd->Parameters->AddWithValue("@stat", status);
                cmd->Parameters->AddWithValue("@brand", brand ? brand->Trim() : "");
                cmd->Parameters->AddWithValue("@model", modelSerial ? modelSerial->Trim() : "");
                cmd->Parameters->AddWithValue("@notes", notes ? notes->Trim() : "");
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

        // Delete a tool
        static String^ DeleteTool(int id) {
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();

                // Verify tool is not active in any rental
                MySqlCommand^ checkCmd = gcnew MySqlCommand("SELECT COUNT(*) FROM rentals WHERE tool_id=@id AND status IN ('Active','Overdue')", conn);
                checkCmd->Parameters->AddWithValue("@id", id);
                int activeRentals = Convert::ToInt32(checkCmd->ExecuteScalar());
                if (activeRentals > 0) {
                    return "Cannot delete this tool because it is currently linked to an active or overdue rental.";
                }

                MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM tools WHERE id=@id", conn);
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
