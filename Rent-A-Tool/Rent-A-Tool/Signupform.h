#pragma once
#include "../Rent-A-Tool/Data/Dbconfig.h"  // adjust path to wherever you put DbConfig.h
   // adjust path to wherever you put DbConfig.h

namespace RentATool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for signupform
	/// </summary>
	public ref class signupform : public System::Windows::Forms::Form
	{
	public:
		signupform(void)
		{
			InitializeComponent();
		}

	protected:
		~signupform()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Label^ lblFullName;
	private: System::Windows::Forms::Label^ lblUsername;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::Label^ lblConfirm;
	private: System::Windows::Forms::TextBox^ txtFullName;
	private: System::Windows::Forms::TextBox^ txtUsername;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtConfirm;
	private: System::Windows::Forms::CheckBox^ chkShowPassword;
	private: System::Windows::Forms::Button^ btnSignUp;
	private: System::Windows::Forms::Button^ btnBack;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblFullName = (gcnew System::Windows::Forms::Label());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblConfirm = (gcnew System::Windows::Forms::Label());
			this->txtFullName = (gcnew System::Windows::Forms::TextBox());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtConfirm = (gcnew System::Windows::Forms::TextBox());
			this->chkShowPassword = (gcnew System::Windows::Forms::CheckBox());
			this->btnSignUp = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			//
			// lblTitle
			//
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(39, 30);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(170, 32);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"Create Account";
			//
			// lblFullName
			//
			this->lblFullName->AutoSize = true;
			this->lblFullName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
			this->lblFullName->ForeColor = System::Drawing::Color::White;
			this->lblFullName->Location = System::Drawing::Point(39, 95);
			this->lblFullName->Name = L"lblFullName";
			this->lblFullName->Size = System::Drawing::Size(90, 20);
			this->lblFullName->TabIndex = 1;
			this->lblFullName->Text = L"Full Name:";
			//
			// lblUsername
			//
			this->lblUsername->AutoSize = true;
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
			this->lblUsername->ForeColor = System::Drawing::Color::White;
			this->lblUsername->Location = System::Drawing::Point(39, 150);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(92, 20);
			this->lblUsername->TabIndex = 2;
			this->lblUsername->Text = L"Username:";
			//
			// lblPassword
			//
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
			this->lblPassword->ForeColor = System::Drawing::Color::White;
			this->lblPassword->Location = System::Drawing::Point(39, 205);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(90, 20);
			this->lblPassword->TabIndex = 3;
			this->lblPassword->Text = L"Password:";
			//
			// lblConfirm
			//
			this->lblConfirm->AutoSize = true;
			this->lblConfirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
			this->lblConfirm->ForeColor = System::Drawing::Color::White;
			this->lblConfirm->Location = System::Drawing::Point(39, 260);
			this->lblConfirm->Name = L"lblConfirm";
			this->lblConfirm->Size = System::Drawing::Size(140, 20);
			this->lblConfirm->TabIndex = 4;
			this->lblConfirm->Text = L"Confirm Password:";
			//
			// txtFullName
			//
			this->txtFullName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
			this->txtFullName->Location = System::Drawing::Point(190, 93);
			this->txtFullName->Name = L"txtFullName";
			this->txtFullName->Size = System::Drawing::Size(190, 27);
			this->txtFullName->TabIndex = 6;
			//
			// txtUsername
			//
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
			this->txtUsername->Location = System::Drawing::Point(190, 148);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(190, 27);
			this->txtUsername->TabIndex = 7;
			//
			// txtPassword
			//
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
			this->txtPassword->Location = System::Drawing::Point(190, 203);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(190, 27);
			this->txtPassword->TabIndex = 8;
			this->txtPassword->UseSystemPasswordChar = true;
			//
			// txtConfirm
			//
			this->txtConfirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular));
			this->txtConfirm->Location = System::Drawing::Point(190, 258);
			this->txtConfirm->Name = L"txtConfirm";
			this->txtConfirm->Size = System::Drawing::Size(190, 27);
			this->txtConfirm->TabIndex = 9;
			this->txtConfirm->UseSystemPasswordChar = true;
			//
			// chkShowPassword
			//
			this->chkShowPassword->AutoSize = true;
			this->chkShowPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular));
			this->chkShowPassword->ForeColor = System::Drawing::Color::White;
			this->chkShowPassword->Location = System::Drawing::Point(190, 288);
			this->chkShowPassword->Name = L"chkShowPassword";
			this->chkShowPassword->Size = System::Drawing::Size(130, 24);
			this->chkShowPassword->TabIndex = 10;
			this->chkShowPassword->Text = L"Show password";
			this->chkShowPassword->UseVisualStyleBackColor = true;
			this->chkShowPassword->CheckedChanged += gcnew System::EventHandler(this, &signupform::chkShowPassword_CheckedChanged);
			//
			// btnSignUp
			//
			this->btnSignUp->BackColor = System::Drawing::Color::CadetBlue;
			this->btnSignUp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular));
			this->btnSignUp->ForeColor = System::Drawing::Color::Black;
			this->btnSignUp->Location = System::Drawing::Point(39, 325);
			this->btnSignUp->Name = L"btnSignUp";
			this->btnSignUp->Size = System::Drawing::Size(150, 38);
			this->btnSignUp->TabIndex = 11;
			this->btnSignUp->Text = L"Sign Up";
			this->btnSignUp->UseVisualStyleBackColor = false;
			this->btnSignUp->Click += gcnew System::EventHandler(this, &signupform::btnSignUp_Click);
			//
			// btnBack
			//
			this->btnBack->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular));
			this->btnBack->Location = System::Drawing::Point(230, 325);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(150, 38);
			this->btnBack->TabIndex = 12;
			this->btnBack->Text = L"Back to Login";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &signupform::btnBack_Click);
			//
			// signupform
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSlateGray;
			this->ClientSize = System::Drawing::Size(420, 400);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->lblFullName);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblConfirm);
			this->Controls->Add(this->txtFullName);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtConfirm);
			this->Controls->Add(this->chkShowPassword);
			this->Controls->Add(this->btnSignUp);
			this->Controls->Add(this->btnBack);
			this->MaximumSize = System::Drawing::Size(436, 439);
			this->MinimumSize = System::Drawing::Size(436, 439);
			this->Name = L"signupform";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rent-A-Tool - Sign Up";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void btnSignUp_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ fullName = txtFullName->Text->Trim();
		String^ username = txtUsername->Text->Trim();
		String^ password = txtPassword->Text;
		String^ confirm = txtConfirm->Text;
		String^ role = "Cashier";   // only cashiers can self sign-up; admins are created separately

		if (fullName->Length == 0 || username->Length == 0 || password->Length == 0) {
			MessageBox::Show(this, L"Please fill in all fields.", L"Sign up",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (password->Length < 6) {
			MessageBox::Show(this, L"Password must be at least 6 characters.", L"Sign up",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (password != confirm) {
			MessageBox::Show(this, L"Passwords do not match.", L"Sign up",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			txtConfirm->Clear();
			txtConfirm->Focus();
			return;
		}

		btnSignUp->Enabled = false;
		String^ error = Auth::Register(username, password, fullName, role);
		btnSignUp->Enabled = true;

		if (error->Length == 0) {
			MessageBox::Show(this, L"Account created for " + username + L". You can log in now.",
				L"Sign up successful", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
		else {
			MessageBox::Show(this, error, L"Sign up failed",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void chkShowPassword_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		bool show = chkShowPassword->Checked;
		txtPassword->UseSystemPasswordChar = !show;
		txtConfirm->UseSystemPasswordChar = !show;
	}
	};
}