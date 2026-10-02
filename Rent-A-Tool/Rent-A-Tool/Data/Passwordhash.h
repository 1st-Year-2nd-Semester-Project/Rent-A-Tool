#pragma once
// Salted SHA-256 password hashing.
// Stored format: "<saltHex>$<hashHex>"  (both lowercase hex)
// No external dependency — uses System::Security::Cryptography, built into .NET Framework.
using namespace System;
using namespace System::Text;
using namespace System::Security::Cryptography;

public ref class PasswordHash abstract sealed {
public:
    // Creates a new random salt + hash for a freshly chosen password (e.g. on sign-up).
    static String^ Hash(String^ password) {
        array<Byte>^ saltBytes = gcnew array<Byte>(16);
        RandomNumberGenerator^ rng = RandomNumberGenerator::Create();
        rng->GetBytes(saltBytes);
        String^ saltHex = ToHex(saltBytes);
        String^ hashHex = ComputeHash(password, saltHex);
        return saltHex + "$" + hashHex;
    }

    // Verifies a password attempt against a stored "<salt>$<hash>" value.
    static bool Verify(String^ password, String^ stored) {
        if (String::IsNullOrEmpty(stored)) return false;
        array<String^>^ parts = stored->Split('$');
        if (parts->Length != 2) return false;

        String^ saltHex = parts[0];
        String^ expectedHash = parts[1];
        String^ actualHash = ComputeHash(password, saltHex);

        // Simple constant-time-ish compare (good enough for a desktop app; not public-facing)
        if (actualHash->Length != expectedHash->Length) return false;
        int diff = 0;
        for (int i = 0; i < actualHash->Length; i++)
            diff |= (int)actualHash[i] ^ (int)expectedHash[i];
        return diff == 0;
    }

private:
    static String^ ComputeHash(String^ password, String^ saltHex) {
        array<Byte>^ saltBytes = FromHex(saltHex);
        array<Byte>^ pwBytes = Encoding::UTF8->GetBytes(password);

        array<Byte>^ combined = gcnew array<Byte>(saltBytes->Length + pwBytes->Length);
        Array::Copy(saltBytes, 0, combined, 0, saltBytes->Length);
        Array::Copy(pwBytes, 0, combined, saltBytes->Length, pwBytes->Length);

        SHA256^ sha = SHA256::Create();
        array<Byte>^ hashBytes = sha->ComputeHash(combined);
        return ToHex(hashBytes);
    }

    static String^ ToHex(array<Byte>^ bytes) {
        StringBuilder^ sb = gcnew StringBuilder(bytes->Length * 2);
        for each(Byte b in bytes) sb->AppendFormat("{0:x2}", b);
        return sb->ToString();
    }

    static array<Byte>^ FromHex(String^ hex) {
        array<Byte>^ bytes = gcnew array<Byte>(hex->Length / 2);
        for (int i = 0; i < bytes->Length; i++)
            bytes[i] = Convert::ToByte(hex->Substring(i * 2, 2), 16);
        return bytes;
    }
};