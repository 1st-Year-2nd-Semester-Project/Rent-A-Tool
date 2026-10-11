#pragma once
#include "Dbconfig.h"

using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

namespace RentATool {
namespace Data {

    public ref class SettingsService abstract sealed {
    public:
        static String^ GetSetting(String^ key, String^ defaultValue) {
            String^ val = defaultValue;
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                MySqlCommand^ cmd = gcnew MySqlCommand("SELECT `value` FROM settings WHERE `key`=@k", conn);
                cmd->Parameters->AddWithValue("@k", key);
                Object^ result = cmd->ExecuteScalar();
                if (result != nullptr && result != DBNull::Value) {
                    val = result->ToString();
                }
            }
            catch (Exception^) {}
            finally {
                if (conn != nullptr) conn->Close();
            }
            return val;
        }

        static bool SaveSetting(String^ key, String^ value) {
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "INSERT INTO settings (`key`, `value`) VALUES (@k, @v) ON DUPLICATE KEY UPDATE `value`=@v", conn);
                cmd->Parameters->AddWithValue("@k", key);
                cmd->Parameters->AddWithValue("@v", value);
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^) {
                return false;
            }
            finally {
                if (conn != nullptr) conn->Close();
            }
        }

        static DataTable^ GetAllUsers() {
            DataTable^ dt = gcnew DataTable();
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                MySqlCommand^ cmd = gcnew MySqlCommand("SELECT id, username, full_name, role, created_at FROM users ORDER BY id ASC", conn);
                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(cmd);
                adapter->Fill(dt);
            }
            catch (Exception^) {}
            finally {
                if (conn != nullptr) conn->Close();
            }
            return dt;
        }

        static String^ AddUser(String^ username, String^ password, String^ fullName, String^ role) {
            return Auth::Register(username, password, fullName, role);
        }

        static String^ DeleteUser(int userId, String^ currentLoggedInUser) {
            MySqlConnection^ conn = nullptr;
            try {
                conn = Db::GetConnection();
                // Check if deleting oneself
                MySqlCommand^ uCmd = gcnew MySqlCommand("SELECT username FROM users WHERE id=@id", conn);
                uCmd->Parameters->AddWithValue("@id", userId);
                Object^ un = uCmd->ExecuteScalar();
                if (un != nullptr && String::Compare(un->ToString(), currentLoggedInUser, true) == 0) {
                    return "You cannot delete your own account.";
                }

                MySqlCommand^ cmd = gcnew MySqlCommand("DELETE FROM users WHERE id=@id", conn);
                cmd->Parameters->AddWithValue("@id", userId);
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
