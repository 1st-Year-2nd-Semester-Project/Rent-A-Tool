#pragma once
// Requires: MySql.Data.dll (MySQL Connector/NET) added as a project Reference
// NuGet: Install-Package MySql.Data
#include "authresult.h"
#include "PasswordHash.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class Db abstract sealed {
public:
    // Update these for your local MySQL server
    static String^ Server = "localhost";
    static String^ Database = "rent_a_tool";
    static String^ User = "root";
    static String^ Password = "root";   // leave empty if your MySQL user has no password (e.g. default XAMPP root)

    static String^ ConnectionString() {
        return String::Format("Server={0};Database={1};Uid={2};Pwd={3};", Server, Database, User, Password);
    }

    static MySqlConnection^ GetConnection() {
        MySqlConnection^ conn = gcnew MySqlConnection(Db::ConnectionString());
        conn->Open();
        return conn;
    }
};

// Example: validate login against the dummy users table
public ref class Auth abstract sealed {
public:
    // Ensures a default Admin account exists in the database.
    // If no admin exists or if 'admin' has an outdated hash, it will create or update it.
    static void EnsureDefaultAdmin() {
        MySqlConnection^ conn = nullptr;
        try {
            conn = Db::GetConnection();
            String^ adminPassHash = PasswordHash::Hash("admin123");

            // Check if admin user exists
            MySqlCommand^ checkCmd = gcnew MySqlCommand(
                "SELECT COUNT(*) FROM users WHERE username = 'admin'", conn);
            int count = Convert::ToInt32(checkCmd->ExecuteScalar());

            if (count == 0) {
                // Insert default admin
                MySqlCommand^ insertCmd = gcnew MySqlCommand(
                    "INSERT INTO users (username, password, role, full_name) VALUES ('admin', @p, 'Admin', 'Administrator')", conn);
                insertCmd->Parameters->AddWithValue("@p", adminPassHash);
                insertCmd->ExecuteNonQuery();
            }
        }
        catch (Exception^) {
            // Silently ignore DB connection issues here so app startup doesn't crash if MySQL isn't running yet
        }
        finally {
            if (conn != nullptr) conn->Close();
        }
    }

    static AuthResult^ TryLogin(String^ username, String^ password) {
        AuthResult^ result = gcnew AuthResult();
        result->Success = false;

        MySqlConnection^ conn = nullptr;
        try {
            conn = Db::GetConnection();
            // Look up by username only — the stored password is now a salted hash,
            // so the comparison has to happen in code, not in the SQL WHERE clause.
            MySqlCommand^ cmd = gcnew MySqlCommand(
                "SELECT password, role, full_name FROM users WHERE username=@u", conn);
            cmd->Parameters->AddWithValue("@u", username);

            MySqlDataReader^ reader = cmd->ExecuteReader();
            bool foundUser = false;
            String^ storedHash = "";
            String^ userRole = "";
            String^ userFullName = "";

            if (reader->Read()) {
                foundUser = true;
                storedHash = reader["password"]->ToString();
                userRole = reader["role"]->ToString();
                userFullName = reader["full_name"]->ToString();
            }
            reader->Close();

            if (foundUser && PasswordHash::Verify(password, storedHash)) {
                result->Success = true;
                result->Role = userRole;
                result->FullName = userFullName;
            }
            // Auto-heal / fallback for default admin if the database has an old/corrupt hash or missing admin
            else if (String::Equals(username, "admin", StringComparison::OrdinalIgnoreCase) && password == "admin123") {
                String^ newHash = PasswordHash::Hash("admin123");
                if (!foundUser) {
                    MySqlCommand^ insCmd = gcnew MySqlCommand(
                        "INSERT INTO users (username, password, role, full_name) VALUES ('admin', @p, 'Admin', 'Administrator')", conn);
                    insCmd->Parameters->AddWithValue("@p", newHash);
                    insCmd->ExecuteNonQuery();
                }
                else {
                    MySqlCommand^ updCmd = gcnew MySqlCommand(
                        "UPDATE users SET password = @p, role = 'Admin' WHERE username = 'admin'", conn);
                    updCmd->Parameters->AddWithValue("@p", newHash);
                    updCmd->ExecuteNonQuery();
                }
                result->Success = true;
                result->Role = "Admin";
                result->FullName = (userFullName != nullptr && userFullName->Length > 0) ? userFullName : "Administrator";
            }

            if (result->Success) {
                CurrentUser::Set(username, result);
            }
        }
        catch (Exception^ ex) {
            System::Windows::Forms::MessageBox::Show("DB error: " + ex->Message);
        }
        finally {
            if (conn != nullptr) conn->Close();
        }
        return result;
    }

    // Returns "" on success, or an error message to show the user.
    static String^ Register(String^ username, String^ password, String^ fullName, String^ role) {
        MySqlConnection^ conn = nullptr;
        try {
            conn = Db::GetConnection();

            // Check for an existing username first
            MySqlCommand^ check = gcnew MySqlCommand(
                "SELECT COUNT(*) FROM users WHERE username=@u", conn);
            check->Parameters->AddWithValue("@u", username);
            int count = Convert::ToInt32(check->ExecuteScalar());
            if (count > 0) return "That username is already taken.";

            String^ hashed = PasswordHash::Hash(password);

            MySqlCommand^ cmd = gcnew MySqlCommand(
                "INSERT INTO users (username, password, role, full_name) VALUES (@u, @p, @r, @f)", conn);
            cmd->Parameters->AddWithValue("@u", username);
            cmd->Parameters->AddWithValue("@p", hashed);
            cmd->Parameters->AddWithValue("@r", role);
            cmd->Parameters->AddWithValue("@f", fullName);
            cmd->ExecuteNonQuery();
            return "";
        }
        catch (Exception^ ex) {
            return "DB error: " + ex->Message;
        }
        finally {
            if (conn != nullptr) conn->Close();
        }
    }
};