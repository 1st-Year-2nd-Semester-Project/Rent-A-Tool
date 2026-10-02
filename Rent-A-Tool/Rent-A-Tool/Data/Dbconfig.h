#pragma once
// Requires: MySql.Data.dll (MySQL Connector/NET) added as a project Reference
// NuGet: Install-Package MySql.Data
#include "authresult.h"
using namespace System;
using namespace MySql::Data::MySqlClient;

public ref class Db abstract sealed {
public:
    // Update these for your local MySQL server
    static String^ Server = "localhost";
    static String^ Database = "rent_a_tool";
    static String^ User = "root";
    static String^ Password = "root";

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
    static AuthResult^ TryLogin(String^ username, String^ password) {
        AuthResult^ result = gcnew AuthResult();
        result->Success = false;

        MySqlConnection^ conn = nullptr;
        try {
            conn = Db::GetConnection();
            MySqlCommand^ cmd = gcnew MySqlCommand(
                "SELECT role, full_name FROM users WHERE username=@u AND password=@p", conn);
            cmd->Parameters->AddWithValue("@u", username);
            cmd->Parameters->AddWithValue("@p", password);

            MySqlDataReader^ reader = cmd->ExecuteReader();
            if (reader->Read()) {
                result->Success = true;
                result->Role = reader["role"]->ToString();
                result->FullName = reader["full_name"]->ToString();
            }
            reader->Close();

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

            MySqlCommand^ cmd = gcnew MySqlCommand(
                "INSERT INTO users (username, password, role, full_name) VALUES (@u, @p, @r, @f)", conn);
            cmd->Parameters->AddWithValue("@u", username);
            cmd->Parameters->AddWithValue("@p", password);   // plain text for test DB only
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