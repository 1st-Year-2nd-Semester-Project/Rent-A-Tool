#pragma once
#include "Dbconfig.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace RentATool {
namespace Data {

    public ref class DashboardSummary {
    public:
        int ActiveRentals;
        int OverdueRentals;
        int RentalsToday;
        int AvailableTools;
        int RentedTools;
        int MaintenanceTools;
        int TotalTools;
        int TotalCustomers;
        Decimal TotalRevenue;
        Decimal DepositsHeld;

        DashboardSummary() {
            ActiveRentals = 0;
            OverdueRentals = 0;
            RentalsToday = 0;
            AvailableTools = 0;
            RentedTools = 0;
            MaintenanceTools = 0;
            TotalTools = 0;
            TotalCustomers = 0;
            TotalRevenue = Decimal(0);
            DepositsHeld = Decimal(0);
        }
    };

    public ref class DashboardService abstract sealed {
    public:
        static DashboardSummary^ GetSummary() {
            DashboardSummary^ summary = gcnew DashboardSummary();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();

                // 1. Update any overdue status first
                MySqlCommand^ updCmd = gcnew MySqlCommand(
                    "UPDATE rentals SET status='Overdue' WHERE status='Active' AND due_date < CURDATE()", conn);
                updCmd->ExecuteNonQuery();

                // 2. Rental stats
                MySqlCommand^ rCmd = gcnew MySqlCommand(
                    "SELECT "
                    "SUM(CASE WHEN status='Active' THEN 1 ELSE 0 END) AS active_cnt, "
                    "SUM(CASE WHEN status='Overdue' THEN 1 ELSE 0 END) AS overdue_cnt, "
                    "SUM(CASE WHEN rent_date = CURDATE() THEN 1 ELSE 0 END) AS today_cnt, "
                    "SUM(CASE WHEN status='Returned' THEN total_amount ELSE 0 END) AS revenue, "
                    "SUM(CASE WHEN status IN ('Active','Overdue') THEN deposit_paid ELSE 0 END) AS deposits_held "
                    "FROM rentals", conn);
                MySqlDataReader^ rReader = rCmd->ExecuteReader();
                if (rReader->Read()) {
                    summary->ActiveRentals = rReader->IsDBNull(0) ? 0 : Convert::ToInt32(rReader[0]);
                    summary->OverdueRentals = rReader->IsDBNull(1) ? 0 : Convert::ToInt32(rReader[1]);
                    summary->RentalsToday = rReader->IsDBNull(2) ? 0 : Convert::ToInt32(rReader[2]);
                    summary->TotalRevenue = rReader->IsDBNull(3) ? Decimal(0) : Convert::ToDecimal(rReader[3]);
                    summary->DepositsHeld = rReader->IsDBNull(4) ? Decimal(0) : Convert::ToDecimal(rReader[4]);
                }
                rReader->Close();

                // 3. Tool stats
                MySqlCommand^ tCmd = gcnew MySqlCommand(
                    "SELECT "
                    "SUM(CASE WHEN status='Available' THEN 1 ELSE 0 END) AS avail_cnt, "
                    "SUM(CASE WHEN status='Rented' THEN 1 ELSE 0 END) AS rented_cnt, "
                    "SUM(CASE WHEN status='Maintenance' THEN 1 ELSE 0 END) AS maint_cnt, "
                    "COUNT(*) AS total_cnt "
                    "FROM tools", conn);
                MySqlDataReader^ tReader = tCmd->ExecuteReader();
                if (tReader->Read()) {
                    summary->AvailableTools = tReader->IsDBNull(0) ? 0 : Convert::ToInt32(tReader[0]);
                    summary->RentedTools = tReader->IsDBNull(1) ? 0 : Convert::ToInt32(tReader[1]);
                    summary->MaintenanceTools = tReader->IsDBNull(2) ? 0 : Convert::ToInt32(tReader[2]);
                    summary->TotalTools = tReader->IsDBNull(3) ? 0 : Convert::ToInt32(tReader[3]);
                }
                tReader->Close();

                // 4. Customer stats
                MySqlCommand^ cCmd = gcnew MySqlCommand("SELECT COUNT(*) FROM customers", conn);
                Object^ cCount = cCmd->ExecuteScalar();
                if (cCount != nullptr && cCount != DBNull::Value) {
                    summary->TotalCustomers = Convert::ToInt32(cCount);
                }
            }
            catch (Exception^ ex) {
                System::Windows::Forms::MessageBox::Show("Error loading dashboard data: " + ex->Message);
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
            return summary;
        }

        // Category breakdown for chart
        static DataTable^ GetCategoryStats() {
            DataTable^ dt = gcnew DataTable();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ query = "SELECT IFNULL(category, 'Other') AS Category, COUNT(*) AS ToolCount FROM tools GROUP BY category";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
                adapter->Fill(dt);
            }
            catch (Exception^) {}
            finally {
                if (conn != nullptr) conn->Close();
            }
            return dt;
        }

        // Recent rentals list for dashboard table
        static DataTable^ GetRecentRentals(int limit) {
            DataTable^ dt = gcnew DataTable();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                String^ query = "SELECT r.rental_code, c.name AS customer_name, t.name AS tool_name, "
                                "r.rent_date, r.due_date, r.status, r.deposit_paid, r.total_amount "
                                "FROM rentals r "
                                "JOIN customers c ON r.customer_id = c.id "
                                "JOIN tools t ON r.tool_id = t.id "
                                "ORDER BY r.id DESC LIMIT " + limit;
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
                adapter->Fill(dt);
            }
            catch (Exception^) {}
            finally {
                if (conn != nullptr) conn->Close();
            }
            return dt;
        }
    };
}
}
