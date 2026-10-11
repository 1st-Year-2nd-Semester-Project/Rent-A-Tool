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
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;
		System::Windows::Forms::Button^ btnClose;
		System::Windows::Forms::TabControl^ tabControl1;
		System::Windows::Forms::TabPage^ tabGeneral;
		System::Windows::Forms::TabPage^ tabUsers;
		System::Windows::Forms::Label^ lblGenTitle;
		System::Windows::Forms::Label^ lblCompany;
		System::Windows::Forms::TextBox^ txtCompany;
		System::Windows::Forms::Label^ lblCurrency;
		System::Windows::Forms::TextBox^ txtCurrency;
		System::Windows::Forms::Label^ lblLateFee;
		System::Windows::Forms::NumericUpDown^ numLateFee;
		System::Windows::Forms::Label^ lblBackup;
		System::Windows::Forms::TextBox^ txtBackup;
		System::Windows::Forms::Button^ btnSaveSettings;
		System::Windows::Forms::Label^ lblSaveStatus;
		System::Windows::Forms::DataGridView^ dgvUsers;
		System::Windows::Forms::Panel^ pnlUserEditor;
		System::Windows::Forms::Label^ lblUserEditorTitle;
		System::Windows::Forms::Label^ lblNewUsername;
		System::Windows::Forms::TextBox^ txtNewUsername;
		System::Windows::Forms::Label^ lblNewPassword;
		System::Windows::Forms::TextBox^ txtNewPassword;
		System::Windows::Forms::Label^ lblNewFullName;
		System::Windows::Forms::TextBox^ txtNewFullName;
		System::Windows::Forms::Label^ lblNewRole;
		System::Windows::Forms::ComboBox^ cmbNewRole;
		System::Windows::Forms::Button^ btnAddUser;
		System::Windows::Forms::Button^ btnDeleteUser;
		System::Windows::Forms::Button^ btnRefreshUsers;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(settings::typeid));
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabGeneral = (gcnew System::Windows::Forms::TabPage());
			this->lblGenTitle = (gcnew System::Windows::Forms::Label());
			this->lblCompany = (gcnew System::Windows::Forms::Label());
			this->txtCompany = (gcnew System::Windows::Forms::TextBox());
			this->lblCurrency = (gcnew System::Windows::Forms::Label());
			this->txtCurrency = (gcnew System::Windows::Forms::TextBox());
			this->lblLateFee = (gcnew System::Windows::Forms::Label());
			this->numLateFee = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblBackup = (gcnew System::Windows::Forms::Label());
			this->txtBackup = (gcnew System::Windows::Forms::TextBox());
			this->btnSaveSettings = (gcnew System::Windows::Forms::Button());
			this->lblSaveStatus = (gcnew System::Windows::Forms::Label());
			this->tabUsers = (gcnew System::Windows::Forms::TabPage());
			this->dgvUsers = (gcnew System::Windows::Forms::DataGridView());
			this->pnlUserEditor = (gcnew System::Windows::Forms::Panel());
			this->lblUserEditorTitle = (gcnew System::Windows::Forms::Label());
			this->lblNewUsername = (gcnew System::Windows::Forms::Label());
			this->txtNewUsername = (gcnew System::Windows::Forms::TextBox());
			this->lblNewPassword = (gcnew System::Windows::Forms::Label());
			this->txtNewPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblNewFullName = (gcnew System::Windows::Forms::Label());
			this->txtNewFullName = (gcnew System::Windows::Forms::TextBox());
			this->lblNewRole = (gcnew System::Windows::Forms::Label());
			this->cmbNewRole = (gcnew System::Windows::Forms::ComboBox());
			this->btnAddUser = (gcnew System::Windows::Forms::Button());
			this->btnDeleteUser = (gcnew System::Windows::Forms::Button());
			this->btnRefreshUsers = (gcnew System::Windows::Forms::Button());
			this->pnlHeader->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabGeneral->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numLateFee))->BeginInit();
			this->tabUsers->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->BeginInit();
			this->pnlUserEditor->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlHeader
			// 
			this->pnlHeader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->pnlHeader->Controls->Add(this->lblTitle);
			this->pnlHeader->Controls->Add(this->lblSubtitle);
			this->pnlHeader->Controls->Add(this->btnClose);
			this->pnlHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlHeader->Location = System::Drawing::Point(0, 0);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Size = System::Drawing::Size(1050, 70);
			this->pnlHeader->TabIndex = 0;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(20, 12);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(395, 30);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"SETTINGS & SYSTEM CONFIGURATION";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->lblSubtitle->Location = System::Drawing::Point(22, 42);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(427, 17);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"Configure business rules, late fees, currency, and manage user accounts";
			// 
			// btnClose
			// 
			this->btnClose->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnClose->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(110)),
				static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->btnClose->ForeColor = System::Drawing::Color::White;
			this->btnClose->Location = System::Drawing::Point(880, 18);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(150, 35);
			this->btnClose->TabIndex = 2;
			this->btnClose->Text = L"Back to Dashboard";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &settings::btnClose_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabGeneral);
			this->tabControl1->Controls->Add(this->tabUsers);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.5F));
			this->tabControl1->Location = System::Drawing::Point(0, 70);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1050, 580);
			this->tabControl1->TabIndex = 1;
			// 
			// tabGeneral
			// 
			this->tabGeneral->BackColor = System::Drawing::Color::White;
			this->tabGeneral->Controls->Add(this->lblGenTitle);
			this->tabGeneral->Controls->Add(this->lblCompany);
			this->tabGeneral->Controls->Add(this->txtCompany);
			this->tabGeneral->Controls->Add(this->lblCurrency);
			this->tabGeneral->Controls->Add(this->txtCurrency);
			this->tabGeneral->Controls->Add(this->lblLateFee);
			this->tabGeneral->Controls->Add(this->numLateFee);
			this->tabGeneral->Controls->Add(this->lblBackup);
			this->tabGeneral->Controls->Add(this->txtBackup);
			this->tabGeneral->Controls->Add(this->btnSaveSettings);
			this->tabGeneral->Controls->Add(this->lblSaveStatus);
			this->tabGeneral->Location = System::Drawing::Point(4, 28);
			this->tabGeneral->Name = L"tabGeneral";
			this->tabGeneral->Padding = System::Windows::Forms::Padding(30);
			this->tabGeneral->Size = System::Drawing::Size(1042, 548);
			this->tabGeneral->TabIndex = 0;
			this->tabGeneral->Text = L"  General Settings  ";
			// 
			// lblGenTitle
			// 
			this->lblGenTitle->AutoSize = true;
			this->lblGenTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->lblGenTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->lblGenTitle->Location = System::Drawing::Point(30, 20);
			this->lblGenTitle->Name = L"lblGenTitle";
			this->lblGenTitle->Size = System::Drawing::Size(230, 25);
			this->lblGenTitle->TabIndex = 0;
			this->lblGenTitle->Text = L"Business & System Policies";
			// 
			// lblCompany
			// 
			this->lblCompany->AutoSize = true;
			this->lblCompany->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblCompany->Location = System::Drawing::Point(30, 65);
			this->lblCompany->Name = L"lblCompany";
			this->lblCompany->Size = System::Drawing::Size(110, 17);
			this->lblCompany->TabIndex = 1;
			this->lblCompany->Text = L"Company Name:";
			// 
			// txtCompany
			// 
			this->txtCompany->Location = System::Drawing::Point(30, 87);
			this->txtCompany->Name = L"txtCompany";
			this->txtCompany->Size = System::Drawing::Size(450, 26);
			this->txtCompany->TabIndex = 2;
			// 
			// lblCurrency
			// 
			this->lblCurrency->AutoSize = true;
			this->lblCurrency->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblCurrency->Location = System::Drawing::Point(30, 130);
			this->lblCurrency->Name = L"lblCurrency";
			this->lblCurrency->Size = System::Drawing::Size(116, 17);
			this->lblCurrency->TabIndex = 3;
			this->lblCurrency->Text = L"Currency Symbol:";
			// 
			// txtCurrency
			// 
			this->txtCurrency->Location = System::Drawing::Point(30, 152);
			this->txtCurrency->Name = L"txtCurrency";
			this->txtCurrency->Size = System::Drawing::Size(200, 26);
			this->txtCurrency->TabIndex = 4;
			// 
			// lblLateFee
			// 
			this->lblLateFee->AutoSize = true;
			this->lblLateFee->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblLateFee->Location = System::Drawing::Point(30, 195);
			this->lblLateFee->Name = L"lblLateFee";
			this->lblLateFee->Size = System::Drawing::Size(151, 17);
			this->lblLateFee->TabIndex = 5;
			this->lblLateFee->Text = L"Default Late Fee / Day:";
			// 
			// numLateFee
			// 
			this->numLateFee->DecimalPlaces = 2;
			this->numLateFee->Location = System::Drawing::Point(30, 217);
			this->numLateFee->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numLateFee->Name = L"numLateFee";
			this->numLateFee->Size = System::Drawing::Size(200, 26);
			this->numLateFee->TabIndex = 6;
			// 
			// lblBackup
			// 
			this->lblBackup->AutoSize = true;
			this->lblBackup->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblBackup->Location = System::Drawing::Point(30, 260);
			this->lblBackup->Name = L"lblBackup";
			this->lblBackup->Size = System::Drawing::Size(128, 17);
			this->lblBackup->TabIndex = 7;
			this->lblBackup->Text = L"Database Host / IP:";
			// 
			// txtBackup
			// 
			this->txtBackup->Location = System::Drawing::Point(30, 282);
			this->txtBackup->Name = L"txtBackup";
			this->txtBackup->ReadOnly = true;
			this->txtBackup->Size = System::Drawing::Size(450, 26);
			this->txtBackup->TabIndex = 8;
			// 
			// btnSaveSettings
			// 
			this->btnSaveSettings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->btnSaveSettings->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSaveSettings->FlatAppearance->BorderSize = 0;
			this->btnSaveSettings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSaveSettings->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnSaveSettings->ForeColor = System::Drawing::Color::White;
			this->btnSaveSettings->Location = System::Drawing::Point(30, 335);
			this->btnSaveSettings->Name = L"btnSaveSettings";
			this->btnSaveSettings->Size = System::Drawing::Size(240, 42);
			this->btnSaveSettings->TabIndex = 9;
			this->btnSaveSettings->Text = L"Save System Settings";
			this->btnSaveSettings->UseVisualStyleBackColor = false;
			this->btnSaveSettings->Click += gcnew System::EventHandler(this, &settings::btnSaveSettings_Click);
			// 
			// lblSaveStatus
			// 
			this->lblSaveStatus->AutoSize = true;
			this->lblSaveStatus->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->lblSaveStatus->Location = System::Drawing::Point(285, 348);
			this->lblSaveStatus->Name = L"lblSaveStatus";
			this->lblSaveStatus->Size = System::Drawing::Size(0, 19);
			this->lblSaveStatus->TabIndex = 10;
			// 
			// tabUsers
			// 
			this->tabUsers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->tabUsers->Controls->Add(this->dgvUsers);
			this->tabUsers->Controls->Add(this->pnlUserEditor);
			this->tabUsers->Location = System::Drawing::Point(4, 28);
			this->tabUsers->Name = L"tabUsers";
			this->tabUsers->Padding = System::Windows::Forms::Padding(3);
			this->tabUsers->Size = System::Drawing::Size(1042, 548);
			this->tabUsers->TabIndex = 1;
			this->tabUsers->Text = L"  User Accounts & Roles  ";
			// 
			// dgvUsers
			// 
			this->dgvUsers->AllowUserToAddRows = false;
			this->dgvUsers->AllowUserToDeleteRows = false;
			this->dgvUsers->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvUsers->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dgvUsers->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgvUsers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvUsers->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvUsers->Location = System::Drawing::Point(3, 3);
			this->dgvUsers->MultiSelect = false;
			this->dgvUsers->Name = L"dgvUsers";
			this->dgvUsers->ReadOnly = true;
			this->dgvUsers->RowHeadersVisible = false;
			this->dgvUsers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvUsers->Size = System::Drawing::Size(701, 542);
			this->dgvUsers->TabIndex = 1;
			this->dgvUsers->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &settings::dgvUsers_CellClick);
			this->dgvUsers->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &settings::dgvUsers_DataError);
			// 
			// pnlUserEditor
			// 
			this->pnlUserEditor->BackColor = System::Drawing::Color::White;
			this->pnlUserEditor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlUserEditor->Controls->Add(this->lblUserEditorTitle);
			this->pnlUserEditor->Controls->Add(this->lblNewUsername);
			this->pnlUserEditor->Controls->Add(this->txtNewUsername);
			this->pnlUserEditor->Controls->Add(this->lblNewPassword);
			this->pnlUserEditor->Controls->Add(this->txtNewPassword);
			this->pnlUserEditor->Controls->Add(this->lblNewFullName);
			this->pnlUserEditor->Controls->Add(this->txtNewFullName);
			this->pnlUserEditor->Controls->Add(this->lblNewRole);
			this->pnlUserEditor->Controls->Add(this->cmbNewRole);
			this->pnlUserEditor->Controls->Add(this->btnAddUser);
			this->pnlUserEditor->Controls->Add(this->btnDeleteUser);
			this->pnlUserEditor->Controls->Add(this->btnRefreshUsers);
			this->pnlUserEditor->Dock = System::Windows::Forms::DockStyle::Right;
			this->pnlUserEditor->Location = System::Drawing::Point(704, 3);
			this->pnlUserEditor->Name = L"pnlUserEditor";
			this->pnlUserEditor->Padding = System::Windows::Forms::Padding(20);
			this->pnlUserEditor->Size = System::Drawing::Size(335, 542);
			this->pnlUserEditor->TabIndex = 0;
			// 
			// lblUserEditorTitle
			// 
			this->lblUserEditorTitle->AutoSize = true;
			this->lblUserEditorTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblUserEditorTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)), static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->lblUserEditorTitle->Location = System::Drawing::Point(20, 15);
			this->lblUserEditorTitle->Name = L"lblUserEditorTitle";
			this->lblUserEditorTitle->Size = System::Drawing::Size(164, 21);
			this->lblUserEditorTitle->TabIndex = 0;
			this->lblUserEditorTitle->Text = L"Create User Account";
			// 
			// lblNewUsername
			// 
			this->lblNewUsername->AutoSize = true;
			this->lblNewUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblNewUsername->Location = System::Drawing::Point(20, 48);
			this->lblNewUsername->Name = L"lblNewUsername";
			this->lblNewUsername->Size = System::Drawing::Size(67, 15);
			this->lblNewUsername->TabIndex = 1;
			this->lblNewUsername->Text = L"Username:";
			// 
			// txtNewUsername
			// 
			this->txtNewUsername->Location = System::Drawing::Point(20, 66);
			this->txtNewUsername->Name = L"txtNewUsername";
			this->txtNewUsername->Size = System::Drawing::Size(295, 26);
			this->txtNewUsername->TabIndex = 2;
			// 
			// lblNewPassword
			// 
			this->lblNewPassword->AutoSize = true;
			this->lblNewPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblNewPassword->Location = System::Drawing::Point(20, 101);
			this->lblNewPassword->Name = L"lblNewPassword";
			this->lblNewPassword->Size = System::Drawing::Size(62, 15);
			this->lblNewPassword->TabIndex = 3;
			this->lblNewPassword->Text = L"Password:";
			// 
			// txtNewPassword
			// 
			this->txtNewPassword->Location = System::Drawing::Point(20, 119);
			this->txtNewPassword->Name = L"txtNewPassword";
			this->txtNewPassword->Size = System::Drawing::Size(295, 26);
			this->txtNewPassword->TabIndex = 4;
			this->txtNewPassword->UseSystemPasswordChar = true;
			// 
			// lblNewFullName
			// 
			this->lblNewFullName->AutoSize = true;
			this->lblNewFullName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblNewFullName->Location = System::Drawing::Point(20, 154);
			this->lblNewFullName->Name = L"lblNewFullName";
			this->lblNewFullName->Size = System::Drawing::Size(65, 15);
			this->lblNewFullName->TabIndex = 5;
			this->lblNewFullName->Text = L"Full Name:";
			// 
			// txtNewFullName
			// 
			this->txtNewFullName->Location = System::Drawing::Point(20, 172);
			this->txtNewFullName->Name = L"txtNewFullName";
			this->txtNewFullName->Size = System::Drawing::Size(295, 26);
			this->txtNewFullName->TabIndex = 6;
			// 
			// lblNewRole
			// 
			this->lblNewRole->AutoSize = true;
			this->lblNewRole->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblNewRole->Location = System::Drawing::Point(20, 207);
			this->lblNewRole->Name = L"lblNewRole";
			this->lblNewRole->Size = System::Drawing::Size(64, 15);
			this->lblNewRole->TabIndex = 7;
			this->lblNewRole->Text = L"User Role:";
			// 
			// cmbNewRole
			// 
			this->cmbNewRole->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbNewRole->FormattingEnabled = true;
			this->cmbNewRole->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Cashier", L"Admin" });
			this->cmbNewRole->Location = System::Drawing::Point(20, 227);
			this->cmbNewRole->Name = L"cmbNewRole";
			this->cmbNewRole->Size = System::Drawing::Size(295, 27);
			this->cmbNewRole->TabIndex = 8;
			// 
			// btnAddUser
			// 
			this->btnAddUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->btnAddUser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAddUser->FlatAppearance->BorderSize = 0;
			this->btnAddUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->btnAddUser->ForeColor = System::Drawing::Color::White;
			this->btnAddUser->Location = System::Drawing::Point(20, 272);
			this->btnAddUser->Name = L"btnAddUser";
			this->btnAddUser->Size = System::Drawing::Size(295, 38);
			this->btnAddUser->TabIndex = 9;
			this->btnAddUser->Text = L"+ Create Account";
			this->btnAddUser->UseVisualStyleBackColor = false;
			this->btnAddUser->Click += gcnew System::EventHandler(this, &settings::btnAddUser_Click);
			// 
			// btnDeleteUser
			// 
			this->btnDeleteUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->btnDeleteUser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDeleteUser->FlatAppearance->BorderSize = 0;
			this->btnDeleteUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnDeleteUser->ForeColor = System::Drawing::Color::White;
			this->btnDeleteUser->Location = System::Drawing::Point(20, 322);
			this->btnDeleteUser->Name = L"btnDeleteUser";
			this->btnDeleteUser->Size = System::Drawing::Size(295, 34);
			this->btnDeleteUser->TabIndex = 10;
			this->btnDeleteUser->Text = L"Delete Selected User";
			this->btnDeleteUser->UseVisualStyleBackColor = false;
			this->btnDeleteUser->Click += gcnew System::EventHandler(this, &settings::btnDeleteUser_Click);
			// 
			// btnRefreshUsers
			// 
			this->btnRefreshUsers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->btnRefreshUsers->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRefreshUsers->FlatAppearance->BorderSize = 0;
			this->btnRefreshUsers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefreshUsers->ForeColor = System::Drawing::Color::White;
			this->btnRefreshUsers->Location = System::Drawing::Point(20, 366);
			this->btnRefreshUsers->Name = L"btnRefreshUsers";
			this->btnRefreshUsers->Size = System::Drawing::Size(295, 32);
			this->btnRefreshUsers->TabIndex = 11;
			this->btnRefreshUsers->Text = L"Refresh User List";
			this->btnRefreshUsers->UseVisualStyleBackColor = false;
			this->btnRefreshUsers->Click += gcnew System::EventHandler(this, &settings::btnRefreshUsers_Click);
			// 
			// settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->ClientSize = System::Drawing::Size(1050, 650);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->pnlHeader);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(900, 580);
			this->Name = L"settings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rent-A-Tool - Settings & Users";
			this->Load += gcnew System::EventHandler(this, &settings::settings_Load);
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabGeneral->ResumeLayout(false);
			this->tabGeneral->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numLateFee))->EndInit();
			this->tabUsers->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvUsers))->EndInit();
			this->pnlUserEditor->ResumeLayout(false);
			this->pnlUserEditor->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

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
