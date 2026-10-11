#pragma once
#include "Data/SettingsService.h"
#include "Data/authresult.h"

namespace RentATool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class settings : public System::Windows::Forms::Form
	{
	public:
		settings(void)
		{
			selectedUserId = -1;
			InitializeComponent();
		}

	protected:
		~settings()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int selectedUserId;
		System::ComponentModel::Container^ components;

		Panel^ pnlHeader;
		Label^ lblTitle;
		Label^ lblSubtitle;
		Button^ btnClose;

		TabControl^ tabControl1;
		TabPage^ tabGeneral;
		TabPage^ tabUsers;

		// Tab 1 General Settings
		Label^ lblGenTitle;
		Label^ lblCompany;
		TextBox^ txtCompany;
		Label^ lblCurrency;
		TextBox^ txtCurrency;
		Label^ lblLateFee;
		NumericUpDown^ numLateFee;
		Label^ lblBackup;
		TextBox^ txtBackup;
		Button^ btnSaveSettings;
		Label^ lblSaveStatus;

		// Tab 2 User Accounts
		DataGridView^ dgvUsers;
		Panel^ pnlUserEditor;
		Label^ lblUserEditorTitle;
		Label^ lblNewUsername;
		TextBox^ txtNewUsername;
		Label^ lblNewPassword;
		TextBox^ txtNewPassword;
		Label^ lblNewFullName;
		TextBox^ txtNewFullName;
		Label^ lblNewRole;
		ComboBox^ cmbNewRole;
		Button^ btnAddUser;
		Button^ btnDeleteUser;
		Button^ btnRefreshUsers;

		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->SuspendLayout();

			// Form properties
			this->Text = L"Rent-A-Tool - Settings & Users";
			this->ClientSize = System::Drawing::Size(1050, 650);
			this->MinimumSize = System::Drawing::Size(900, 580);
			this->StartPosition = FormStartPosition::CenterScreen;
			this->BackColor = Color::FromArgb(244, 246, 249);
			this->Font = gcnew Drawing::Font(L"Segoe UI", 10);

			// Header Panel
			pnlHeader = gcnew Panel();
			pnlHeader->Dock = DockStyle::Top;
			pnlHeader->Height = 70;
			pnlHeader->BackColor = Color::FromArgb(47, 79, 79);

			lblTitle = gcnew Label();
			lblTitle->Text = L"SETTINGS & SYSTEM CONFIGURATION";
			lblTitle->Font = gcnew Drawing::Font(L"Segoe UI", 16, FontStyle::Bold);
			lblTitle->ForeColor = Color::White;
			lblTitle->Location = Point(20, 12);
			lblTitle->AutoSize = true;

			lblSubtitle = gcnew Label();
			lblSubtitle->Text = L"Configure business rules, late fees, currency, and manage user accounts";
			lblSubtitle->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F);
			lblSubtitle->ForeColor = Color::FromArgb(210, 230, 230);
			lblSubtitle->Location = Point(22, 42);
			lblSubtitle->AutoSize = true;

			btnClose = gcnew Button();
			btnClose->Text = L"Back to Dashboard";
			btnClose->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnClose->ForeColor = Color::White;
			btnClose->BackColor = Color::FromArgb(70, 110, 110);
			btnClose->FlatStyle = FlatStyle::Flat;
			btnClose->FlatAppearance->BorderSize = 0;
			btnClose->Location = Point(880, 18);
			btnClose->Size = System::Drawing::Size(150, 35);
			btnClose->Anchor = AnchorStyles::Top | AnchorStyles::Right;
			btnClose->Cursor = Cursors::Hand;
			btnClose->Click += gcnew EventHandler(this, &settings::btnClose_Click);

			pnlHeader->Controls->Add(lblTitle);
			pnlHeader->Controls->Add(lblSubtitle);
			pnlHeader->Controls->Add(btnClose);

			// Tab Control
			tabControl1 = gcnew TabControl();
			tabControl1->Dock = DockStyle::Fill;
			tabControl1->Font = gcnew Drawing::Font(L"Segoe UI", 10.5F);

			tabGeneral = gcnew TabPage();
			tabGeneral->Text = L"  General Settings  ";
			tabGeneral->BackColor = Color::White;
			tabGeneral->Padding = System::Windows::Forms::Padding(40);

			tabUsers = gcnew TabPage();
			tabUsers->Text = L"  User Management  ";
			tabUsers->BackColor = Color::FromArgb(244, 246, 249);

			// ================= TAB 1: GENERAL SETTINGS =================
			lblGenTitle = gcnew Label();
			lblGenTitle->Text = L"Application & Billing Preferences";
			lblGenTitle->Font = gcnew Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
			lblGenTitle->ForeColor = Color::FromArgb(47, 79, 79);
			lblGenTitle->Location = Point(40, 30);
			lblGenTitle->AutoSize = true;

			int y = 80;
			lblCompany = gcnew Label();
			lblCompany->Text = L"Company / Shop Name:";
			lblCompany->Location = Point(40, y);
			lblCompany->AutoSize = true;
			lblCompany->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			txtCompany = gcnew TextBox();
			txtCompany->Location = Point(40, y + 22);
			txtCompany->Size = System::Drawing::Size(400, 25);

			y += 65;
			lblCurrency = gcnew Label();
			lblCurrency->Text = L"Currency Code / Symbol:";
			lblCurrency->Location = Point(40, y);
			lblCurrency->AutoSize = true;
			lblCurrency->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			txtCurrency = gcnew TextBox();
			txtCurrency->Location = Point(40, y + 22);
			txtCurrency->Size = System::Drawing::Size(400, 25);

			y += 65;
			lblLateFee = gcnew Label();
			lblLateFee->Text = L"Default Late Fee per Day (LKR):";
			lblLateFee->Location = Point(40, y);
			lblLateFee->AutoSize = true;
			lblLateFee->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			numLateFee = gcnew NumericUpDown();
			numLateFee->Location = Point(40, y + 22);
			numLateFee->Size = System::Drawing::Size(400, 25);
			numLateFee->Maximum = 100000;
			numLateFee->DecimalPlaces = 2;

			y += 65;
			lblBackup = gcnew Label();
			lblBackup->Text = L"Database Backup Destination Path:";
			lblBackup->Location = Point(40, y);
			lblBackup->AutoSize = true;
			lblBackup->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			txtBackup = gcnew TextBox();
			txtBackup->Location = Point(40, y + 22);
			txtBackup->Size = System::Drawing::Size(400, 25);

			y += 75;
			btnSaveSettings = gcnew Button();
			btnSaveSettings->Text = L"Save Changes";
			btnSaveSettings->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			btnSaveSettings->BackColor = Color::FromArgb(39, 174, 96);
			btnSaveSettings->ForeColor = Color::White;
			btnSaveSettings->FlatStyle = FlatStyle::Flat;
			btnSaveSettings->FlatAppearance->BorderSize = 0;
			btnSaveSettings->Location = Point(40, y);
			btnSaveSettings->Size = System::Drawing::Size(200, 42);
			btnSaveSettings->Cursor = Cursors::Hand;
			btnSaveSettings->Click += gcnew EventHandler(this, &settings::btnSaveSettings_Click);

			lblSaveStatus = gcnew Label();
			lblSaveStatus->Location = Point(255, y + 10);
			lblSaveStatus->AutoSize = true;
			lblSaveStatus->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Italic);
			lblSaveStatus->ForeColor = Color::DarkGreen;

			tabGeneral->Controls->Add(lblGenTitle);
			tabGeneral->Controls->Add(lblCompany);
			tabGeneral->Controls->Add(txtCompany);
			tabGeneral->Controls->Add(lblCurrency);
			tabGeneral->Controls->Add(txtCurrency);
			tabGeneral->Controls->Add(lblLateFee);
			tabGeneral->Controls->Add(numLateFee);
			tabGeneral->Controls->Add(lblBackup);
			tabGeneral->Controls->Add(txtBackup);
			tabGeneral->Controls->Add(btnSaveSettings);
			tabGeneral->Controls->Add(lblSaveStatus);

			// ================= TAB 2: USER MANAGEMENT =================
			pnlUserEditor = gcnew Panel();
			pnlUserEditor->Dock = DockStyle::Right;
			pnlUserEditor->Width = 340;
			pnlUserEditor->BackColor = Color::White;
			pnlUserEditor->Padding = System::Windows::Forms::Padding(20);

			lblUserEditorTitle = gcnew Label();
			lblUserEditorTitle->Text = L"Add New User";
			lblUserEditorTitle->Font = gcnew Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblUserEditorTitle->ForeColor = Color::FromArgb(47, 79, 79);
			lblUserEditorTitle->Location = Point(20, 15);
			lblUserEditorTitle->AutoSize = true;

			int uy = 55;
			lblNewUsername = gcnew Label();
			lblNewUsername->Text = L"Username:";
			lblNewUsername->Location = Point(20, uy);
			lblNewUsername->AutoSize = true;
			txtNewUsername = gcnew TextBox();
			txtNewUsername->Location = Point(20, uy + 20);
			txtNewUsername->Size = System::Drawing::Size(295, 25);

			uy += 55;
			lblNewPassword = gcnew Label();
			lblNewPassword->Text = L"Password:";
			lblNewPassword->Location = Point(20, uy);
			lblNewPassword->AutoSize = true;
			txtNewPassword = gcnew TextBox();
			txtNewPassword->UseSystemPasswordChar = true;
			txtNewPassword->Location = Point(20, uy + 20);
			txtNewPassword->Size = System::Drawing::Size(295, 25);

			uy += 55;
			lblNewFullName = gcnew Label();
			lblNewFullName->Text = L"Full Name:";
			lblNewFullName->Location = Point(20, uy);
			lblNewFullName->AutoSize = true;
			txtNewFullName = gcnew TextBox();
			txtNewFullName->Location = Point(20, uy + 20);
			txtNewFullName->Size = System::Drawing::Size(295, 25);

			uy += 55;
			lblNewRole = gcnew Label();
			lblNewRole->Text = L"Role:";
			lblNewRole->Location = Point(20, uy);
			lblNewRole->AutoSize = true;
			cmbNewRole = gcnew ComboBox();
			cmbNewRole->DropDownStyle = ComboBoxStyle::DropDownList;
			cmbNewRole->Items->AddRange(gcnew cli::array<Object^>{ L"Cashier", L"Admin" });
			cmbNewRole->SelectedIndex = 0;
			cmbNewRole->Location = Point(20, uy + 20);
			cmbNewRole->Size = System::Drawing::Size(295, 25);

			uy += 65;
			btnAddUser = gcnew Button();
			btnAddUser->Text = L"+ Create Account";
			btnAddUser->Location = Point(20, uy);
			btnAddUser->Size = System::Drawing::Size(295, 38);
			btnAddUser->BackColor = Color::FromArgb(39, 174, 96);
			btnAddUser->ForeColor = Color::White;
			btnAddUser->FlatStyle = FlatStyle::Flat;
			btnAddUser->FlatAppearance->BorderSize = 0;
			btnAddUser->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnAddUser->Cursor = Cursors::Hand;
			btnAddUser->Click += gcnew EventHandler(this, &settings::btnAddUser_Click);

			uy += 50;
			btnDeleteUser = gcnew Button();
			btnDeleteUser->Text = L"Delete Selected User";
			btnDeleteUser->Location = Point(20, uy);
			btnDeleteUser->Size = System::Drawing::Size(295, 34);
			btnDeleteUser->BackColor = Color::FromArgb(231, 76, 60);
			btnDeleteUser->ForeColor = Color::White;
			btnDeleteUser->FlatStyle = FlatStyle::Flat;
			btnDeleteUser->FlatAppearance->BorderSize = 0;
			btnDeleteUser->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			btnDeleteUser->Cursor = Cursors::Hand;
			btnDeleteUser->Click += gcnew EventHandler(this, &settings::btnDeleteUser_Click);

			uy += 44;
			btnRefreshUsers = gcnew Button();
			btnRefreshUsers->Text = L"Refresh User List";
			btnRefreshUsers->Location = Point(20, uy);
			btnRefreshUsers->Size = System::Drawing::Size(295, 32);
			btnRefreshUsers->BackColor = Color::FromArgb(52, 152, 219);
			btnRefreshUsers->ForeColor = Color::White;
			btnRefreshUsers->FlatStyle = FlatStyle::Flat;
			btnRefreshUsers->FlatAppearance->BorderSize = 0;
			btnRefreshUsers->Cursor = Cursors::Hand;
			btnRefreshUsers->Click += gcnew EventHandler(this, &settings::btnRefreshUsers_Click);

			pnlUserEditor->Controls->Add(lblUserEditorTitle);
			pnlUserEditor->Controls->Add(lblNewUsername);
			pnlUserEditor->Controls->Add(txtNewUsername);
			pnlUserEditor->Controls->Add(lblNewPassword);
			pnlUserEditor->Controls->Add(txtNewPassword);
			pnlUserEditor->Controls->Add(lblNewFullName);
			pnlUserEditor->Controls->Add(txtNewFullName);
			pnlUserEditor->Controls->Add(lblNewRole);
			pnlUserEditor->Controls->Add(cmbNewRole);
			pnlUserEditor->Controls->Add(btnAddUser);
			pnlUserEditor->Controls->Add(btnDeleteUser);
			pnlUserEditor->Controls->Add(btnRefreshUsers);

			dgvUsers = gcnew DataGridView();
			dgvUsers->Dock = DockStyle::Fill;
			dgvUsers->BackgroundColor = Color::FromArgb(244, 246, 249);
			dgvUsers->BorderStyle = BorderStyle::None;
			dgvUsers->AllowUserToAddRows = false;
			dgvUsers->AllowUserToDeleteRows = false;
			dgvUsers->ReadOnly = true;
			dgvUsers->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dgvUsers->MultiSelect = false;
			dgvUsers->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dgvUsers->RowHeadersVisible = false;
			dgvUsers->CellClick += gcnew DataGridViewCellEventHandler(this, &settings::dgvUsers_CellClick);
			dgvUsers->DataError += gcnew DataGridViewDataErrorEventHandler(this, &settings::dgvUsers_DataError);

			tabUsers->Controls->Add(dgvUsers);
			tabUsers->Controls->Add(pnlUserEditor);

			tabControl1->TabPages->Add(tabGeneral);
			tabControl1->TabPages->Add(tabUsers);

			this->Controls->Add(tabControl1);
			this->Controls->Add(pnlHeader);

			this->Load += gcnew EventHandler(this, &settings::settings_Load);
			this->ResumeLayout(false);
		}

		void dgvUsers_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e)
		{
			e->ThrowException = false;
		}

		void settings_Load(System::Object^ sender, System::EventArgs^ e)
		{
			LoadAppSettings();
			LoadUserAccounts();
		}

		void LoadAppSettings()
		{
			txtCompany->Text = Data::SettingsService::GetSetting("company_name", "Rent A Tool");
			txtCurrency->Text = Data::SettingsService::GetSetting("currency", "LKR");
			String^ lateStr = Data::SettingsService::GetSetting("late_fee_per_day", "200.00");
			Decimal fee = Decimal(200);
			Decimal::TryParse(lateStr, fee);
			numLateFee->Value = fee;
			txtBackup->Text = Data::SettingsService::GetSetting("backup_path", "C:\\RentATool\\Backups");
		}

		void LoadUserAccounts()
		{
			DataTable^ dt = Data::SettingsService::GetAllUsers();
			dgvUsers->DataSource = dt;

			if (dgvUsers->Columns->Contains("id")) {
				dgvUsers->Columns["id"]->HeaderText = L"ID";
				dgvUsers->Columns["id"]->FillWeight = 40;
			}
			if (dgvUsers->Columns->Contains("username")) dgvUsers->Columns["username"]->HeaderText = L"Username";
			if (dgvUsers->Columns->Contains("full_name")) dgvUsers->Columns["full_name"]->HeaderText = L"Full Name";
			if (dgvUsers->Columns->Contains("role")) dgvUsers->Columns["role"]->HeaderText = L"Role";
			if (dgvUsers->Columns->Contains("created_at")) dgvUsers->Columns["created_at"]->HeaderText = L"Created";

			// Restrict modifying users if not Admin
			if (!CurrentUser::IsAdmin()) {
				btnAddUser->Enabled = false;
				btnDeleteUser->Enabled = false;
				lblUserEditorTitle->Text = L"Users (Admin Only to Edit)";
			}
		}

		void btnSaveSettings_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (!CurrentUser::IsAdmin()) {
				MessageBox::Show(this, L"Only Administrators can modify system preferences.", L"Access Denied", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			Data::SettingsService::SaveSetting("company_name", txtCompany->Text->Trim());
			Data::SettingsService::SaveSetting("currency", txtCurrency->Text->Trim());
			Data::SettingsService::SaveSetting("late_fee_per_day", numLateFee->Value.ToString("F2"));
			Data::SettingsService::SaveSetting("backup_path", txtBackup->Text->Trim());

			lblSaveStatus->Text = L"Settings saved successfully at " + DateTime::Now.ToShortTimeString();
		}

		void dgvUsers_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0 && e->RowIndex < dgvUsers->Rows->Count) {
				selectedUserId = Convert::ToInt32(dgvUsers->Rows[e->RowIndex]->Cells["id"]->Value);
			}
		}

		void btnAddUser_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ username = txtNewUsername->Text->Trim();
			String^ password = txtNewPassword->Text;
			String^ fullName = txtNewFullName->Text->Trim();
			String^ role = cmbNewRole->SelectedItem->ToString();

			if (username->Length == 0 || password->Length == 0 || fullName->Length == 0) {
				MessageBox::Show(this, L"Please fill in all user fields.", L"Validation", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			if (password->Length < 6) {
				MessageBox::Show(this, L"Password must be at least 6 characters.", L"Validation", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ err = Data::SettingsService::AddUser(username, password, fullName, role);
			if (err->Length == 0) {
				MessageBox::Show(this, L"User account created successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				txtNewUsername->Clear();
				txtNewPassword->Clear();
				txtNewFullName->Clear();
				LoadUserAccounts();
			}
			else {
				MessageBox::Show(this, err, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void btnDeleteUser_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedUserId <= 0) {
				MessageBox::Show(this, L"Please select a user to delete.", L"Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			if (MessageBox::Show(this, L"Are you sure you want to delete this user account?", L"Confirm Delete", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				String^ err = Data::SettingsService::DeleteUser(selectedUserId, CurrentUser::Username);
				if (err->Length == 0) {
					MessageBox::Show(this, L"User deleted successfully.", L"Deleted", MessageBoxButtons::OK, MessageBoxIcon::Information);
					selectedUserId = -1;
					LoadUserAccounts();
				}
				else {
					MessageBox::Show(this, err, L"Cannot Delete", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}

		void btnRefreshUsers_Click(System::Object^ sender, System::EventArgs^ e)
		{
			LoadUserAccounts();
		}

		void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}
	};
}
