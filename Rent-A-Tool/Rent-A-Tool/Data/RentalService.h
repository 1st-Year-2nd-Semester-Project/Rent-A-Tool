#pragma once
#include "Dbconfig.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace RentATool {
namespace Data {

    public ref class RentalService abstract sealed {
    public:
        // Update any overdue active rentals
        static void UpdateOverdueStatuses() {
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "UPDATE rentals SET status='Overdue' WHERE status='Active' AND due_date < CURDATE()", conn);
                cmd->ExecuteNonQuery();
            }
            catch (Exception^) {
                // Silently handle or log
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
        }

        // Retrieve all rentals with joined customer and tool details
        static DataTable^ GetAllRentals(String^ statusFilter, String^ searchQuery) {
            UpdateOverdueStatuses();
            DataTable^ table = gcnew DataTable();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ query = "SELECT r.id, r.rental_code, r.customer_id, r.tool_id, "
                                "c.name AS customer_name, c.phone AS customer_phone, c.nic AS customer_nic, "
                                "t.name AS tool_name, t.tool_code, t.daily_rate, "
                                "r.rent_date, r.due_date, r.return_date, "
                                "r.deposit_paid, r.total_amount, r.status, r.notes "
                                "FROM rentals r "
                                "JOIN customers c ON r.customer_id = c.id "
                                "JOIN tools t ON r.tool_id = t.id "
                                "WHERE 1=1 ";

                if (!String::IsNullOrWhiteSpace(statusFilter) && statusFilter != "All") {
                    query += " AND r.status = @status ";
                }
                if (!String::IsNullOrWhiteSpace(searchQuery)) {
                    query += " AND (r.rental_code LIKE @search OR c.name LIKE @search OR t.name LIKE @search OR c.nic LIKE @search) ";
                }

                query += " ORDER BY r.id DESC";

                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                if (!String::IsNullOrWhiteSpace(statusFilter) && statusFilter != "All") {
                    cmd->Parameters->AddWithValue("@status", statusFilter);
                }
                if (!String::IsNullOrWhiteSpace(searchQuery)) {
                    cmd->Parameters->AddWithValue("@search", "%" + searchQuery->Trim() + "%");
                }

                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
                adapter->Fill(table);
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error loading rentals: " + ex->Message);
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
            return table;
        }

        // Get configured late fee per day from settings
        static Decimal GetLateFeePerDay() {
            Decimal fee = Decimal(200);
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                MySqlCommand^ cmd = gcnew MySqlCommand("SELECT `value` FROM settings WHERE `key`='late_fee_per_day'", conn);
                Object^ val = cmd->ExecuteScalar();
                if (val != nullptr && val != DBNull::Value) {
                    Decimal parsed;
                    if (Decimal::TryParse(val->ToString(), parsed)) {
                        fee = parsed;
                    }
                }
            }
            catch (Exception^) {
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
            return fee;
        }

        // Create a new rental and mark tool as Rented
        static String^ CreateRental(int customerId, int toolId, DateTime rentDate, DateTime dueDate,
                                    Decimal depositPaid, Decimal totalAmount, String^ notes) {
            MySqlConnection^ conn = nullptr;
            MySqlTransaction^ trans = nullptr;
            try {
                conn = Db::GetConnection();
                trans = conn->BeginTransaction();

                // 1. Verify customer is not blacklisted
                MySqlCommand^ custCheck = gcnew MySqlCommand("SELECT is_blacklisted FROM customers WHERE id=@cid", conn, trans);
                custCheck->Parameters->AddWithValue("@cid", customerId);
                Object^ blVal = custCheck->ExecuteScalar();
                if (blVal != nullptr && Convert::ToBoolean(blVal)) {
                    trans->Rollback();
                    return "Cannot issue rental: This customer is currently blacklisted.";
                }

                // 2. Verify tool is Available
                MySqlCommand^ toolCheck = gcnew MySqlCommand("SELECT status FROM tools WHERE id=@tid", conn, trans);
                toolCheck->Parameters->AddWithValue("@tid", toolId);
                Object^ statVal = toolCheck->ExecuteScalar();
                if (statVal == nullptr || statVal->ToString() != "Available") {
                    trans->Rollback();
                    return "Cannot issue rental: Selected tool is currently " + (statVal != nullptr ? statVal->ToString() : "Unavailable") + ".";
                }

                // 3. Generate unique rental code
                MySqlCommand^ maxIdCmd = gcnew MySqlCommand("SELECT IFNULL(MAX(id), 0) + 1 FROM rentals", conn, trans);
                int nextId = Convert::ToInt32(maxIdCmd->ExecuteScalar());
                String^ rentalCode = String::Format("R-{0:D4}", 1000 + nextId);

                // 4. Insert rental record
                String^ insertSql = "INSERT INTO rentals (rental_code, customer_id, tool_id, rent_date, due_date, deposit_paid, total_amount, status, notes) "
                                    "VALUES (@code, @cid, @tid, @rdate, @ddate, @dep, @total, 'Active', @notes)";
                MySqlCommand^ insCmd = gcnew MySqlCommand(insertSql, conn, trans);
                insCmd->Parameters->AddWithValue("@code", rentalCode);
                insCmd->Parameters->AddWithValue("@cid", customerId);
                insCmd->Parameters->AddWithValue("@tid", toolId);
                insCmd->Parameters->AddWithValue("@rdate", rentDate.ToString("yyyy-MM-dd"));
                insCmd->Parameters->AddWithValue("@ddate", dueDate.ToString("yyyy-MM-dd"));
                insCmd->Parameters->AddWithValue("@dep", depositPaid);
                insCmd->Parameters->AddWithValue("@total", totalAmount);
                insCmd->Parameters->AddWithValue("@notes", notes ? notes->Trim() : "");
                insCmd->ExecuteNonQuery();

                // 5. Update tool status to 'Rented'
                MySqlCommand^ updToolCmd = gcnew MySqlCommand("UPDATE tools SET status='Rented' WHERE id=@tid", conn, trans);
                updToolCmd->Parameters->AddWithValue("@tid", toolId);
                updToolCmd->ExecuteNonQuery();

                trans->Commit();
                return "";
            }
            catch (Exception^ ex) {
                if (trans != nullptr) trans->Rollback();
                return "DB Error: " + ex->Message;
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
        }

        // Return a rental, adjust totals, and restore tool to Available
        static String^ ProcessReturn(int rentalId, int toolId, DateTime returnDate, Decimal finalTotal, String^ notes) {
            MySqlConnection^ conn = nullptr;
            MySqlTransaction^ trans = nullptr;
            try {
                conn = Db::GetConnection();
                trans = conn->BeginTransaction();

                // Update rental record
                String^ updateRental = "UPDATE rentals SET return_date=@retdate, total_amount=@tot, status='Returned', notes=@notes WHERE id=@rid";
                MySqlCommand^ rCmd = gcnew MySqlCommand(updateRental, conn, trans);
                rCmd->Parameters->AddWithValue("@retdate", returnDate.ToString("yyyy-MM-dd"));
                rCmd->Parameters->AddWithValue("@tot", finalTotal);
                rCmd->Parameters->AddWithValue("@notes", notes ? notes->Trim() : "");
                rCmd->Parameters->AddWithValue("@rid", rentalId);
                rCmd->ExecuteNonQuery();

                // Set tool status back to Available
                MySqlCommand^ tCmd = gcnew MySqlCommand("UPDATE tools SET status='Available' WHERE id=@tid", conn, trans);
                tCmd->Parameters->AddWithValue("@tid", toolId);
                tCmd->ExecuteNonQuery();

                trans->Commit();
                return "";
            }
            catch (Exception^ ex) {
                if (trans != nullptr) trans->Rollback();
                return "DB Error: " + ex->Message;
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
        }
    };
}
}
