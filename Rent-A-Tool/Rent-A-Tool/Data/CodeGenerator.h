#pragma once
#include "Dbconfig.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace RentATool {
namespace Data {

    /// <summary>
    /// Helper to safely compute next unique Tool Code (T-0001...) and Customer Code (C-0001...)
    /// by querying the highest existing numeric suffix from the database.
    /// Handles empty tables, existing prefix conventions, and irregular legacy codes without crashing.
    /// </summary>
    public ref class CodeGenerator abstract sealed {
    public:
        /// <summary>
        /// Computes the highest numeric suffix in tools + 1.
        /// Extracts digits using REGEXP_SUBSTR so formats like 'T-001', 'T-0001', 'T0001' are all handled cleanly.
        /// If the table is empty or has no numeric codes, defaults safely to 1.
        /// </summary>
        static int GetNextToolNumber(MySqlConnection^ conn) {
            bool openedHere = false;
            if (conn == nullptr) {
                conn = Db::GetConnection();
                openedHere = true;
            }
            try {
                String^ query = "SELECT IFNULL(MAX(CAST(REGEXP_SUBSTR(tool_code, '[0-9]+') AS UNSIGNED)), 0) + 1 "
                                "FROM tools WHERE tool_code IS NOT NULL AND tool_code != ''";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                Object^ result = cmd->ExecuteScalar();
                if (result != nullptr && result != DBNull::Value) {
                    return Convert::ToInt32(result);
                }
                return 1;
            }
            catch (Exception^) {
                return 1;
            }
            finally {
                if (openedHere && conn != nullptr) {
                    conn->Close();
                }
            }
        }

        static String^ GetNextToolCode(MySqlConnection^ conn) {
            int nextNum = GetNextToolNumber(conn);
            return String::Format("T-{0:D4}", nextNum);
        }

        static String^ GetNextToolCode() {
            return GetNextToolCode(nullptr);
        }

        /// <summary>
        /// Computes the highest numeric suffix in customers + 1.
        /// Extracts digits using REGEXP_SUBSTR so formats like 'C-001', 'C-0001', 'C0001' are all handled cleanly.
        /// If the table is empty or has no numeric codes, defaults safely to 1.
        /// </summary>
        static int GetNextCustomerNumber(MySqlConnection^ conn) {
            bool openedHere = false;
            if (conn == nullptr) {
                conn = Db::GetConnection();
                openedHere = true;
            }
            try {
                String^ query = "SELECT IFNULL(MAX(CAST(REGEXP_SUBSTR(cust_code, '[0-9]+') AS UNSIGNED)), 0) + 1 "
                                "FROM customers WHERE cust_code IS NOT NULL AND cust_code != ''";
                MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
                Object^ result = cmd->ExecuteScalar();
                if (result != nullptr && result != DBNull::Value) {
                    return Convert::ToInt32(result);
                }
                return 1;
            }
            catch (Exception^) {
                return 1;
            }
            finally {
                if (openedHere && conn != nullptr) {
                    conn->Close();
                }
            }
        }

        static String^ GetNextCustomerCode(MySqlConnection^ conn) {
            int nextNum = GetNextCustomerNumber(conn);
            return String::Format("C-{0:D4}", nextNum);
        }

        static String^ GetNextCustomerCode() {
            return GetNextCustomerCode(nullptr);
        }
    };

}
}
