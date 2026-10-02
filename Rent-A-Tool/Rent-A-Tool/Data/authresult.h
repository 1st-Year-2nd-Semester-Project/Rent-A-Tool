#pragma once
using namespace System;

// Holds the outcome of a login attempt, plus the logged-in user's info.
// No MySQL dependency here, so any form (dashboard, inventory, etc.)
// can include just this header to check who's logged in.
public ref class AuthResult
{
public:
    bool Success;
    String^ Role;       // "Admin" or "Cashier"
    String^ FullName;

    AuthResult() {
        Success = false;
        Role = L"";
        FullName = L"";
    }
};

// Simple global holder for the currently logged-in user,
// so other forms can read it after loginform closes.
public ref class CurrentUser abstract sealed
{
public:
    static String^ Username;
    static String^ Role;
    static String^ FullName;

    static void Set(String^ username, AuthResult^ result) {
        CurrentUser::Username = username;
        CurrentUser::Role = result->Role;
        CurrentUser::FullName = result->FullName;
    }

    static bool IsAdmin() {
        return Role != nullptr && Role == L"Admin";
    }
};