#pragma once
#include "Data/CodeGenerator.h"
#include "Data/CustomerService.h"
#include "Data/authresult.h"

namespace RentATool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class customers : public System::Windows::Forms::Form
	{
	public:
		customers(void)
		{
			selectedCustomerId = -1;
			InitializeComponent();
		}

	protected:
		~customers()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int selectedCustomerId;
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;
		System::Windows::Forms::Button^ btnClose;
		System::Windows::Forms::Panel^ pnlFilter;
		System::Windows::Forms::Label^ lblSearch;
		System::Windows::Forms::TextBox^ txtSearch;
		System::Windows::Forms::Button^ btnRefresh;
		System::Windows::Forms::DataGridView^ dgvCustomers;
		System::Windows::Forms::Panel^ pnlEditor;
		System::Windows::Forms::Label^ lblEditorTitle;
		System::Windows::Forms::Label^ lblCode;
		System::Windows::Forms::TextBox^ txtCode;
		System::Windows::Forms::Label^ lblName;
		System::Windows::Forms::TextBox^ txtName;
		System::Windows::Forms::Label^ lblNIC;
		System::Windows::Forms::TextBox^ txtNIC;
		System::Windows::Forms::Label^ lblPhone;
		System::Windows::Forms::TextBox^ txtPhone;
		System::Windows::Forms::Label^ lblEmail;
		System::Windows::Forms::TextBox^ txtEmail;
		System::Windows::Forms::Label^ lblAddress;
		System::Windows::Forms::TextBox^ txtAddress;
		System::Windows::Forms::CheckBox^ chkBlacklist;
		System::Windows::Forms::Button^ btnAdd;
		System::Windows::Forms::Button^ btnUpdate;
		System::Windows::Forms::Button^ btnToggleBlacklist;
		System::Windows::Forms::Button^ btnDelete;
		System::Windows::Forms::Button^ btnClear;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(customers::typeid));
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->pnlFilter = (gcnew System::Windows::Forms::Panel());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->pnlEditor = (gcnew System::Windows::Forms::Panel());
			this->lblEditorTitle = (gcnew System::Windows::Forms::Label());
			this->lblCode = (gcnew System::Windows::Forms::Label());
			this->txtCode = (gcnew System::Windows::Forms::TextBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblNIC = (gcnew System::Windows::Forms::Label());
			this->txtNIC = (gcnew System::Windows::Forms::TextBox());
			this->lblPhone = (gcnew System::Windows::Forms::Label());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->lblAddress = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->chkBlacklist = (gcnew System::Windows::Forms::CheckBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnToggleBlacklist = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->dgvCustomers = (gcnew System::Windows::Forms::DataGridView());
			this->pnlHeader->SuspendLayout();
			this->pnlFilter->SuspendLayout();
			this->pnlEditor->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomers))->BeginInit();
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
			this->pnlHeader->Size = System::Drawing::Size(1150, 70);
			this->pnlHeader->TabIndex = 0;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(20, 12);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(427, 30);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"CUSTOMER MANAGEMENT & DIRECTORY";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->lblSubtitle->Location = System::Drawing::Point(22, 42);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(417, 17);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"Manage customer profiles, contact info, rental history, and blacklisting";
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
			this->btnClose->Location = System::Drawing::Point(980, 18);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(150, 35);
			this->btnClose->TabIndex = 2;
			this->btnClose->Text = L"Back to Dashboard";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &customers::btnClose_Click);
			// 
			// pnlFilter
			// 
			this->pnlFilter->BackColor = System::Drawing::Color::White;
			this->pnlFilter->Controls->Add(this->lblSearch);
			this->pnlFilter->Controls->Add(this->txtSearch);
			this->pnlFilter->Controls->Add(this->btnRefresh);
			this->pnlFilter->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlFilter->Location = System::Drawing::Point(0, 70);
			this->pnlFilter->Name = L"pnlFilter";
			this->pnlFilter->Padding = System::Windows::Forms::Padding(20, 10, 20, 10);
			this->pnlFilter->Size = System::Drawing::Size(1150, 55);
			this->pnlFilter->TabIndex = 1;
			// 
			// lblSearch
			// 
			this->lblSearch->AutoSize = true;
			this->lblSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblSearch->Location = System::Drawing::Point(20, 16);
			this->lblSearch->Name = L"lblSearch";
			this->lblSearch->Size = System::Drawing::Size(281, 17);
			this->lblSearch->TabIndex = 0;
			this->lblSearch->Text = L"Search Customer (Name, NIC, Phone, Code):";
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(330, 13);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(280, 24);
			this->txtSearch->TabIndex = 1;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &customers::txtSearch_TextChanged);
			// 
			// btnRefresh
			// 
			this->btnRefresh->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->btnRefresh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRefresh->FlatAppearance->BorderSize = 0;
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->ForeColor = System::Drawing::Color::White;
			this->btnRefresh->Location = System::Drawing::Point(625, 12);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(90, 28);
			this->btnRefresh->TabIndex = 2;
			this->btnRefresh->Text = L"Refresh";
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &customers::btnRefresh_Click);
			// 
			// pnlEditor
			// 
			this->pnlEditor->BackColor = System::Drawing::Color::White;
			this->pnlEditor->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlEditor->Controls->Add(this->lblEditorTitle);
			this->pnlEditor->Controls->Add(this->lblCode);
			this->pnlEditor->Controls->Add(this->txtCode);
			this->pnlEditor->Controls->Add(this->lblName);
			this->pnlEditor->Controls->Add(this->txtName);
			this->pnlEditor->Controls->Add(this->lblNIC);
			this->pnlEditor->Controls->Add(this->txtNIC);
			this->pnlEditor->Controls->Add(this->lblPhone);
			this->pnlEditor->Controls->Add(this->txtPhone);
			this->pnlEditor->Controls->Add(this->lblEmail);
			this->pnlEditor->Controls->Add(this->txtEmail);
			this->pnlEditor->Controls->Add(this->lblAddress);
			this->pnlEditor->Controls->Add(this->txtAddress);
			this->pnlEditor->Controls->Add(this->chkBlacklist);
			this->pnlEditor->Controls->Add(this->btnAdd);
			this->pnlEditor->Controls->Add(this->btnUpdate);
			this->pnlEditor->Controls->Add(this->btnToggleBlacklist);
			this->pnlEditor->Controls->Add(this->btnClear);
			this->pnlEditor->Controls->Add(this->btnDelete);
			this->pnlEditor->Dock = System::Windows::Forms::DockStyle::Right;
			this->pnlEditor->Location = System::Drawing::Point(815, 125);
			this->pnlEditor->Name = L"pnlEditor";
			this->pnlEditor->Padding = System::Windows::Forms::Padding(20);
			this->pnlEditor->Size = System::Drawing::Size(335, 555);
			this->pnlEditor->TabIndex = 2;
			// 
			// lblEditorTitle
			// 
			this->lblEditorTitle->AutoSize = true;
			this->lblEditorTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblEditorTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->lblEditorTitle->Location = System::Drawing::Point(20, 15);
			this->lblEditorTitle->Name = L"lblEditorTitle";
			this->lblEditorTitle->Size = System::Drawing::Size(138, 21);
			this->lblEditorTitle->TabIndex = 0;
			this->lblEditorTitle->Text = L"Customer Profile";
			// 
			// lblCode
			// 
			this->lblCode->AutoSize = true;
			this->lblCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblCode->Location = System::Drawing::Point(20, 48);
			this->lblCode->Name = L"lblCode";
			this->lblCode->Size = System::Drawing::Size(95, 15);
			this->lblCode->TabIndex = 1;
			this->lblCode->Text = L"Customer Code:";
			// 
			// txtCode
			// 
			this->txtCode->BackColor = System::Drawing::SystemColors::Control;
			this->txtCode->Location = System::Drawing::Point(20, 66);
			this->txtCode->Name = L"txtCode";
			this->txtCode->ReadOnly = true;
			this->txtCode->Size = System::Drawing::Size(295, 24);
			this->txtCode->TabIndex = 2;
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblName->Location = System::Drawing::Point(20, 96);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(65, 15);
			this->lblName->TabIndex = 3;
			this->lblName->Text = L"Full Name:";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(20, 114);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(295, 24);
			this->txtName->TabIndex = 4;
			// 
			// lblNIC
			// 
			this->lblNIC->AutoSize = true;
			this->lblNIC->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblNIC->Location = System::Drawing::Point(20, 144);
			this->lblNIC->Name = L"lblNIC";
			this->lblNIC->Size = System::Drawing::Size(84, 15);
			this->lblNIC->TabIndex = 5;
			this->lblNIC->Text = L"NIC / ID Num:";
			// 
			// txtNIC
			// 
			this->txtNIC->Location = System::Drawing::Point(20, 162);
			this->txtNIC->Name = L"txtNIC";
			this->txtNIC->Size = System::Drawing::Size(295, 24);
			this->txtNIC->TabIndex = 6;
			// 
			// lblPhone
			// 
			this->lblPhone->AutoSize = true;
			this->lblPhone->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblPhone->Location = System::Drawing::Point(20, 192);
			this->lblPhone->Name = L"lblPhone";
			this->lblPhone->Size = System::Drawing::Size(45, 15);
			this->lblPhone->TabIndex = 7;
			this->lblPhone->Text = L"Phone:";
			// 
			// txtPhone
			// 
			this->txtPhone->Location = System::Drawing::Point(20, 210);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->Size = System::Drawing::Size(295, 24);
			this->txtPhone->TabIndex = 8;
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblEmail->Location = System::Drawing::Point(20, 240);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(39, 15);
			this->lblEmail->TabIndex = 9;
			this->lblEmail->Text = L"Email:";
			// 
			// txtEmail
			// 
			this->txtEmail->Location = System::Drawing::Point(20, 258);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(295, 24);
			this->txtEmail->TabIndex = 10;
			// 
			// lblAddress
			// 
			this->lblAddress->AutoSize = true;
			this->lblAddress->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblAddress->Location = System::Drawing::Point(20, 288);
			this->lblAddress->Name = L"lblAddress";
			this->lblAddress->Size = System::Drawing::Size(54, 15);
			this->lblAddress->TabIndex = 11;
			this->lblAddress->Text = L"Address:";
			// 
			// txtAddress
			// 
			this->txtAddress->Location = System::Drawing::Point(20, 306);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(295, 24);
			this->txtAddress->TabIndex = 12;
			// 
			// chkBlacklist
			// 
			this->chkBlacklist->AutoSize = true;
			this->chkBlacklist->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->chkBlacklist->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->chkBlacklist->Location = System::Drawing::Point(20, 338);
			this->chkBlacklist->Name = L"chkBlacklist";
			this->chkBlacklist->Size = System::Drawing::Size(189, 19);
			this->chkBlacklist->TabIndex = 13;
			this->chkBlacklist->Text = L"Blacklisted / Block from Rent";
			this->chkBlacklist->UseVisualStyleBackColor = true;
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->btnAdd->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAdd->FlatAppearance->BorderSize = 0;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->btnAdd->ForeColor = System::Drawing::Color::White;
			this->btnAdd->Location = System::Drawing::Point(20, 368);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(140, 34);
			this->btnAdd->TabIndex = 14;
			this->btnAdd->Text = L"Add Customer";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &customers::btnAdd_Click);
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->btnUpdate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnUpdate->FlatAppearance->BorderSize = 0;
			this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->btnUpdate->ForeColor = System::Drawing::Color::White;
			this->btnUpdate->Location = System::Drawing::Point(175, 368);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(140, 34);
			this->btnUpdate->TabIndex = 15;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &customers::btnUpdate_Click);
			// 
			// btnToggleBlacklist
			// 
			this->btnToggleBlacklist->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(126)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->btnToggleBlacklist->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnToggleBlacklist->FlatAppearance->BorderSize = 0;
			this->btnToggleBlacklist->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnToggleBlacklist->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnToggleBlacklist->ForeColor = System::Drawing::Color::White;
			this->btnToggleBlacklist->Location = System::Drawing::Point(20, 410);
			this->btnToggleBlacklist->Name = L"btnToggleBlacklist";
			this->btnToggleBlacklist->Size = System::Drawing::Size(140, 34);
			this->btnToggleBlacklist->TabIndex = 16;
			this->btnToggleBlacklist->Text = L"Toggle Blacklist";
			this->btnToggleBlacklist->UseVisualStyleBackColor = false;
			this->btnToggleBlacklist->Click += gcnew System::EventHandler(this, &customers::btnToggleBlacklist_Click);
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnClear->FlatAppearance->BorderSize = 0;
			this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClear->ForeColor = System::Drawing::Color::White;
			this->btnClear->Location = System::Drawing::Point(175, 410);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(140, 34);
			this->btnClear->TabIndex = 17;
			this->btnClear->Text = L"Clear Form";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &customers::btnClear_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->btnDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDelete->FlatAppearance->BorderSize = 0;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnDelete->ForeColor = System::Drawing::Color::White;
			this->btnDelete->Location = System::Drawing::Point(20, 452);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(295, 32);
			this->btnDelete->TabIndex = 18;
			this->btnDelete->Text = L"Delete Customer";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &customers::btnDelete_Click);
			// 
			// dgvCustomers
			// 
			this->dgvCustomers->AllowUserToAddRows = false;
			this->dgvCustomers->AllowUserToDeleteRows = false;
			this->dgvCustomers->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvCustomers->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dgvCustomers->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgvCustomers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCustomers->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvCustomers->Location = System::Drawing::Point(0, 125);
			this->dgvCustomers->MultiSelect = false;
			this->dgvCustomers->Name = L"dgvCustomers";
			this->dgvCustomers->ReadOnly = true;
			this->dgvCustomers->RowHeadersVisible = false;
			this->dgvCustomers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvCustomers->Size = System::Drawing::Size(815, 555);
			this->dgvCustomers->TabIndex = 3;
			this->dgvCustomers->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &customers::dgvCustomers_CellClick);
			this->dgvCustomers->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &customers::dgvCustomers_CellFormatting);
			this->dgvCustomers->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &customers::dgvCustomers_DataError);
			// 
			// customers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->ClientSize = System::Drawing::Size(1150, 680);
			this->Controls->Add(this->dgvCustomers);
			this->Controls->Add(this->pnlEditor);
			this->Controls->Add(this->pnlFilter);
			this->Controls->Add(this->pnlHeader);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1000, 600);
			this->Name = L"customers";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rent-A-Tool - Customer Management";
			this->Load += gcnew System::EventHandler(this, &customers::customers_Load);
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlFilter->ResumeLayout(false);
			this->pnlFilter->PerformLayout();
			this->pnlEditor->ResumeLayout(false);
			this->pnlEditor->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomers))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

void dgvCustomers_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e)
		{
			e->ThrowException = false;
		}

		void customers_Load(System::Object^ sender, System::EventArgs^ e)
		{
			if (this->DesignMode) return;
			try {
				LoadCustomers();
			} catch (Exception^) {}
		}

		void LoadCustomers()
		{
			DataTable^ dt = Data::CustomerService::GetAllCustomers(txtSearch->Text);
			dgvCustomers->DataSource = dt;

			if (dgvCustomers->Columns->Contains("id")) {
				dgvCustomers->Columns["id"]->HeaderText = L"ID";
				dgvCustomers->Columns["id"]->FillWeight = 40;
			}
			if (dgvCustomers->Columns->Contains("cust_code")) dgvCustomers->Columns["cust_code"]->HeaderText = L"Code";
			if (dgvCustomers->Columns->Contains("name")) dgvCustomers->Columns["name"]->HeaderText = L"Full Name";
			if (dgvCustomers->Columns->Contains("nic")) dgvCustomers->Columns["nic"]->HeaderText = L"NIC";
			if (dgvCustomers->Columns->Contains("phone")) dgvCustomers->Columns["phone"]->HeaderText = L"Phone";
			if (dgvCustomers->Columns->Contains("email")) dgvCustomers->Columns["email"]->HeaderText = L"Email";
			if (dgvCustomers->Columns->Contains("address")) dgvCustomers->Columns["address"]->HeaderText = L"Address";
			if (dgvCustomers->Columns->Contains("blacklist_status")) dgvCustomers->Columns["blacklist_status"]->HeaderText = L"Status";
			if (dgvCustomers->Columns->Contains("is_blacklisted")) dgvCustomers->Columns["is_blacklisted"]->Visible = false;
			if (dgvCustomers->Columns->Contains("total_rentals")) dgvCustomers->Columns["total_rentals"]->HeaderText = L"Total Rentals";
			if (dgvCustomers->Columns->Contains("created_at")) dgvCustomers->Columns["created_at"]->Visible = false;
		}

		void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			LoadCustomers();
		}

		void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e)
		{
			LoadCustomers();
			ClearForm();
		}

		void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		void ClearForm()
		{
			selectedCustomerId = -1;
			try {
				txtCode->Text = Data::CodeGenerator::GetNextCustomerCode();
			} catch (Exception^) {
				txtCode->Text = L"C-0001";
			}
			txtName->Clear();
			txtNIC->Clear();
			txtPhone->Clear();
			txtEmail->Clear();
			txtAddress->Clear();
			chkBlacklist->Checked = false;
			lblEditorTitle->Text = L"Customer Details";
		}

		void btnClear_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ClearForm();
			txtName->Focus();
		}

		void dgvCustomers_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0 && e->RowIndex < dgvCustomers->Rows->Count) {
				DataGridViewRow^ row = dgvCustomers->Rows[e->RowIndex];
				selectedCustomerId = Convert::ToInt32(row->Cells["id"]->Value);
				txtCode->Text = row->Cells["cust_code"]->Value->ToString();
				txtName->Text = row->Cells["name"]->Value->ToString();
				txtNIC->Text = row->Cells["nic"]->Value != nullptr ? row->Cells["nic"]->Value->ToString() : "";
				txtPhone->Text = row->Cells["phone"]->Value != nullptr ? row->Cells["phone"]->Value->ToString() : "";
				txtEmail->Text = row->Cells["email"]->Value != nullptr ? row->Cells["email"]->Value->ToString() : "";
				txtAddress->Text = row->Cells["address"]->Value != nullptr ? row->Cells["address"]->Value->ToString() : "";
				chkBlacklist->Checked = Convert::ToBoolean(row->Cells["is_blacklisted"]->Value);

				lblEditorTitle->Text = L"Edit Customer: #" + selectedCustomerId;
			}
		}

		void dgvCustomers_CellFormatting(System::Object^ sender, DataGridViewCellFormattingEventArgs^ e)
		{
			if (dgvCustomers->Columns[e->ColumnIndex]->Name == "blacklist_status" && e->Value != nullptr) {
				String^ val = e->Value->ToString();
				if (val == "Blacklisted") {
					e->CellStyle->ForeColor = Color::FromArgb(192, 57, 43);
					e->CellStyle->Font = gcnew Drawing::Font(dgvCustomers->Font, FontStyle::Bold);
				}
				else {
					e->CellStyle->ForeColor = Color::FromArgb(39, 174, 96);
				}
			}
		}

		void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ name = txtName->Text->Trim();
			String^ nic = txtNIC->Text->Trim();
			String^ phone = txtPhone->Text->Trim();
			String^ email = txtEmail->Text->Trim();
			String^ address = txtAddress->Text->Trim();
			bool bl = chkBlacklist->Checked;

			if (name->Length == 0) {
				MessageBox::Show(this, L"Please enter customer full name.", L"Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				txtName->Focus();
				return;
			}

			String^ assignedCode = nullptr;
			String^ err = Data::CustomerService::AddCustomer(assignedCode, name, nic, phone, email, address, bl);
			if (err->Length == 0) {
				MessageBox::Show(this, String::Format(L"Customer added successfully!\nAssigned Code: {0}", assignedCode),
					L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadCustomers();
				ClearForm();
				txtName->Focus();
			}
			else {
				MessageBox::Show(this, err, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedCustomerId <= 0) {
				MessageBox::Show(this, L"Please select a customer to update.", L"Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			String^ code = txtCode->Text->Trim();
			String^ name = txtName->Text->Trim();
			String^ nic = txtNIC->Text->Trim();
			String^ phone = txtPhone->Text->Trim();
			String^ email = txtEmail->Text->Trim();
			String^ address = txtAddress->Text->Trim();
			bool bl = chkBlacklist->Checked;

			if (name->Length == 0) {
				MessageBox::Show(this, L"Please enter customer full name.", L"Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				txtName->Focus();
				return;
			}

			String^ err = Data::CustomerService::UpdateCustomer(selectedCustomerId, code, name, nic, phone, email, address, bl);
			if (err->Length == 0) {
				MessageBox::Show(this, L"Customer updated successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadCustomers();
				ClearForm();
				txtName->Focus();
			}
			else {
				MessageBox::Show(this, err, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void btnToggleBlacklist_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedCustomerId <= 0) {
				MessageBox::Show(this, L"Please select a customer to toggle blacklist status.", L"Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			bool newStatus = !chkBlacklist->Checked;
			String^ action = newStatus ? L"blacklist" : L"remove from blacklist";
			if (MessageBox::Show(this, L"Are you sure you want to " + action + L" this customer?", L"Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				String^ err = Data::CustomerService::ToggleBlacklist(selectedCustomerId, newStatus);
				if (err->Length == 0) {
					chkBlacklist->Checked = newStatus;
					LoadCustomers();
				}
				else {
					MessageBox::Show(this, err, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedCustomerId <= 0) {
				MessageBox::Show(this, L"Please select a customer to delete.", L"Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			if (MessageBox::Show(this, L"Are you sure you want to delete this customer profile?", L"Confirm Delete", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				String^ err = Data::CustomerService::DeleteCustomer(selectedCustomerId);
				if (err->Length == 0) {
					MessageBox::Show(this, L"Customer deleted successfully.", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
					LoadCustomers();
					ClearForm();
				}
				else {
					MessageBox::Show(this, err, L"Cannot Delete", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}
	};
}
