#pragma once
#include "Data/CodeGenerator.h"
#include "Data/ToolService.h"
#include "Data/authresult.h"

namespace RentATool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class inventory : public System::Windows::Forms::Form
	{
	public:
		inventory(void)
		{
			selectedToolId = -1;
			InitializeComponent();
		}

	protected:
		~inventory()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int selectedToolId;
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;
		System::Windows::Forms::Panel^ pnlFilter;
		System::Windows::Forms::Label^ lblSearch;
		System::Windows::Forms::TextBox^ txtSearch;
		System::Windows::Forms::Label^ lblCatFilter;
		System::Windows::Forms::ComboBox^ cmbCatFilter;
		System::Windows::Forms::Label^ lblStatFilter;
		System::Windows::Forms::ComboBox^ cmbStatFilter;
		System::Windows::Forms::Button^ btnRefresh;
		System::Windows::Forms::DataGridView^ dgvTools;
		System::Windows::Forms::Panel^ pnlEditor;
		System::Windows::Forms::Label^ lblEditorTitle;
		System::Windows::Forms::Label^ lblCode;
		System::Windows::Forms::TextBox^ txtCode;
		System::Windows::Forms::Label^ lblName;
		System::Windows::Forms::TextBox^ txtName;
		System::Windows::Forms::Label^ lblCategory;
		System::Windows::Forms::ComboBox^ cmbCategory;
		System::Windows::Forms::Label^ lblDailyRate;
		System::Windows::Forms::NumericUpDown^ numDailyRate;
		System::Windows::Forms::Label^ lblDeposit;
		System::Windows::Forms::NumericUpDown^ numDeposit;
		System::Windows::Forms::Label^ lblStatus;
		System::Windows::Forms::ComboBox^ cmbStatus;
		System::Windows::Forms::Label^ lblBrand;
		System::Windows::Forms::TextBox^ txtBrand;
		System::Windows::Forms::Label^ lblModel;
		System::Windows::Forms::TextBox^ txtModel;
		System::Windows::Forms::Button^ btnAdd;
		System::Windows::Forms::Button^ btnUpdate;
		System::Windows::Forms::Button^ btnDelete;
		System::Windows::Forms::Button^ btnClear;
		System::Windows::Forms::Button^ btnClose;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(inventory::typeid));
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->pnlFilter = (gcnew System::Windows::Forms::Panel());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->lblCatFilter = (gcnew System::Windows::Forms::Label());
			this->cmbCatFilter = (gcnew System::Windows::Forms::ComboBox());
			this->lblStatFilter = (gcnew System::Windows::Forms::Label());
			this->cmbStatFilter = (gcnew System::Windows::Forms::ComboBox());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->pnlEditor = (gcnew System::Windows::Forms::Panel());
			this->lblEditorTitle = (gcnew System::Windows::Forms::Label());
			this->lblCode = (gcnew System::Windows::Forms::Label());
			this->txtCode = (gcnew System::Windows::Forms::TextBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblCategory = (gcnew System::Windows::Forms::Label());
			this->cmbCategory = (gcnew System::Windows::Forms::ComboBox());
			this->lblDailyRate = (gcnew System::Windows::Forms::Label());
			this->numDailyRate = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblDeposit = (gcnew System::Windows::Forms::Label());
			this->numDeposit = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->cmbStatus = (gcnew System::Windows::Forms::ComboBox());
			this->lblBrand = (gcnew System::Windows::Forms::Label());
			this->txtBrand = (gcnew System::Windows::Forms::TextBox());
			this->lblModel = (gcnew System::Windows::Forms::Label());
			this->txtModel = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->dgvTools = (gcnew System::Windows::Forms::DataGridView());
			this->pnlHeader->SuspendLayout();
			this->pnlFilter->SuspendLayout();
			this->pnlEditor->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDailyRate))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDeposit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTools))->BeginInit();
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
			this->lblTitle->Size = System::Drawing::Size(365, 30);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"TOOL INVENTORY MANAGEMENT";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->lblSubtitle->Location = System::Drawing::Point(22, 42);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(377, 17);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"Add, edit, track and manage rental tools, daily rates, and status";
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
			this->btnClose->Click += gcnew System::EventHandler(this, &inventory::btnClose_Click);
			// 
			// pnlFilter
			// 
			this->pnlFilter->BackColor = System::Drawing::Color::White;
			this->pnlFilter->Controls->Add(this->lblSearch);
			this->pnlFilter->Controls->Add(this->txtSearch);
			this->pnlFilter->Controls->Add(this->lblCatFilter);
			this->pnlFilter->Controls->Add(this->cmbCatFilter);
			this->pnlFilter->Controls->Add(this->lblStatFilter);
			this->pnlFilter->Controls->Add(this->cmbStatFilter);
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
			this->lblSearch->Size = System::Drawing::Size(52, 17);
			this->lblSearch->TabIndex = 0;
			this->lblSearch->Text = L"Search:";
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(75, 13);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(200, 24);
			this->txtSearch->TabIndex = 1;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &inventory::FilterChanged);
			// 
			// lblCatFilter
			// 
			this->lblCatFilter->AutoSize = true;
			this->lblCatFilter->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblCatFilter->Location = System::Drawing::Point(295, 16);
			this->lblCatFilter->Name = L"lblCatFilter";
			this->lblCatFilter->Size = System::Drawing::Size(68, 17);
			this->lblCatFilter->TabIndex = 2;
			this->lblCatFilter->Text = L"Category:";
			// 
			// cmbCatFilter
			// 
			this->cmbCatFilter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCatFilter->FormattingEnabled = true;
			this->cmbCatFilter->Location = System::Drawing::Point(370, 13);
			this->cmbCatFilter->Name = L"cmbCatFilter";
			this->cmbCatFilter->Size = System::Drawing::Size(150, 25);
			this->cmbCatFilter->TabIndex = 3;
			this->cmbCatFilter->SelectedIndexChanged += gcnew System::EventHandler(this, &inventory::FilterChanged);
			// 
			// lblStatFilter
			// 
			this->lblStatFilter->AutoSize = true;
			this->lblStatFilter->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblStatFilter->Location = System::Drawing::Point(540, 16);
			this->lblStatFilter->Name = L"lblStatFilter";
			this->lblStatFilter->Size = System::Drawing::Size(50, 17);
			this->lblStatFilter->TabIndex = 4;
			this->lblStatFilter->Text = L"Status:";
			// 
			// cmbStatFilter
			// 
			this->cmbStatFilter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbStatFilter->FormattingEnabled = true;
			this->cmbStatFilter->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"All", L"Available", L"Rented", L"Maintenance",
					L"Lost"
			});
			this->cmbStatFilter->Location = System::Drawing::Point(595, 13);
			this->cmbStatFilter->Name = L"cmbStatFilter";
			this->cmbStatFilter->Size = System::Drawing::Size(130, 25);
			this->cmbStatFilter->TabIndex = 5;
			this->cmbStatFilter->SelectedIndexChanged += gcnew System::EventHandler(this, &inventory::FilterChanged);
			// 
			// btnRefresh
			// 
			this->btnRefresh->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->btnRefresh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRefresh->FlatAppearance->BorderSize = 0;
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->ForeColor = System::Drawing::Color::White;
			this->btnRefresh->Location = System::Drawing::Point(745, 12);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(90, 28);
			this->btnRefresh->TabIndex = 6;
			this->btnRefresh->Text = L"Refresh";
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &inventory::btnRefresh_Click);
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
			this->pnlEditor->Controls->Add(this->lblCategory);
			this->pnlEditor->Controls->Add(this->cmbCategory);
			this->pnlEditor->Controls->Add(this->lblDailyRate);
			this->pnlEditor->Controls->Add(this->numDailyRate);
			this->pnlEditor->Controls->Add(this->lblDeposit);
			this->pnlEditor->Controls->Add(this->numDeposit);
			this->pnlEditor->Controls->Add(this->lblStatus);
			this->pnlEditor->Controls->Add(this->cmbStatus);
			this->pnlEditor->Controls->Add(this->lblBrand);
			this->pnlEditor->Controls->Add(this->txtBrand);
			this->pnlEditor->Controls->Add(this->lblModel);
			this->pnlEditor->Controls->Add(this->txtModel);
			this->pnlEditor->Controls->Add(this->btnAdd);
			this->pnlEditor->Controls->Add(this->btnUpdate);
			this->pnlEditor->Controls->Add(this->btnDelete);
			this->pnlEditor->Controls->Add(this->btnClear);
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
			this->lblEditorTitle->Size = System::Drawing::Size(139, 21);
			this->lblEditorTitle->TabIndex = 0;
			this->lblEditorTitle->Text = L"Tool Information";
			// 
			// lblCode
			// 
			this->lblCode->AutoSize = true;
			this->lblCode->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblCode->Location = System::Drawing::Point(20, 48);
			this->lblCode->Name = L"lblCode";
			this->lblCode->Size = System::Drawing::Size(64, 15);
			this->lblCode->TabIndex = 1;
			this->lblCode->Text = L"Tool Code:";
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
			this->lblName->Size = System::Drawing::Size(69, 15);
			this->lblName->TabIndex = 3;
			this->lblName->Text = L"Tool Name:";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(20, 114);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(295, 24);
			this->txtName->TabIndex = 4;
			// 
			// lblCategory
			// 
			this->lblCategory->AutoSize = true;
			this->lblCategory->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblCategory->Location = System::Drawing::Point(20, 144);
			this->lblCategory->Name = L"lblCategory";
			this->lblCategory->Size = System::Drawing::Size(60, 15);
			this->lblCategory->TabIndex = 5;
			this->lblCategory->Text = L"Category:";
			// 
			// cmbCategory
			// 
			this->cmbCategory->FormattingEnabled = true;
			this->cmbCategory->Location = System::Drawing::Point(20, 162);
			this->cmbCategory->Name = L"cmbCategory";
			this->cmbCategory->Size = System::Drawing::Size(295, 25);
			this->cmbCategory->TabIndex = 6;
			// 
			// lblDailyRate
			// 
			this->lblDailyRate->AutoSize = true;
			this->lblDailyRate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblDailyRate->Location = System::Drawing::Point(20, 194);
			this->lblDailyRate->Name = L"lblDailyRate";
			this->lblDailyRate->Size = System::Drawing::Size(99, 15);
			this->lblDailyRate->TabIndex = 7;
			this->lblDailyRate->Text = L"Daily Rate (LKR):";
			// 
			// numDailyRate
			// 
			this->numDailyRate->DecimalPlaces = 2;
			this->numDailyRate->Location = System::Drawing::Point(20, 212);
			this->numDailyRate->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numDailyRate->Name = L"numDailyRate";
			this->numDailyRate->Size = System::Drawing::Size(295, 24);
			this->numDailyRate->TabIndex = 8;
			// 
			// lblDeposit
			// 
			this->lblDeposit->AutoSize = true;
			this->lblDeposit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblDeposit->Location = System::Drawing::Point(20, 242);
			this->lblDeposit->Name = L"lblDeposit";
			this->lblDeposit->Size = System::Drawing::Size(135, 15);
			this->lblDeposit->TabIndex = 9;
			this->lblDeposit->Text = L"Security Deposit (LKR):";
			// 
			// numDeposit
			// 
			this->numDeposit->DecimalPlaces = 2;
			this->numDeposit->Location = System::Drawing::Point(20, 260);
			this->numDeposit->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numDeposit->Name = L"numDeposit";
			this->numDeposit->Size = System::Drawing::Size(295, 24);
			this->numDeposit->TabIndex = 10;
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblStatus->Location = System::Drawing::Point(20, 290);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(45, 15);
			this->lblStatus->TabIndex = 11;
			this->lblStatus->Text = L"Status:";
			// 
			// cmbStatus
			// 
			this->cmbStatus->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbStatus->FormattingEnabled = true;
			this->cmbStatus->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Available", L"Rented", L"Maintenance", L"Lost" });
			this->cmbStatus->Location = System::Drawing::Point(20, 308);
			this->cmbStatus->Name = L"cmbStatus";
			this->cmbStatus->Size = System::Drawing::Size(295, 25);
			this->cmbStatus->TabIndex = 12;
			// 
			// lblBrand
			// 
			this->lblBrand->AutoSize = true;
			this->lblBrand->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblBrand->Location = System::Drawing::Point(20, 338);
			this->lblBrand->Name = L"lblBrand";
			this->lblBrand->Size = System::Drawing::Size(43, 15);
			this->lblBrand->TabIndex = 13;
			this->lblBrand->Text = L"Brand:";
			// 
			// txtBrand
			// 
			this->txtBrand->Location = System::Drawing::Point(20, 356);
			this->txtBrand->Name = L"txtBrand";
			this->txtBrand->Size = System::Drawing::Size(140, 24);
			this->txtBrand->TabIndex = 14;
			// 
			// lblModel
			// 
			this->lblModel->AutoSize = true;
			this->lblModel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Bold));
			this->lblModel->Location = System::Drawing::Point(175, 338);
			this->lblModel->Name = L"lblModel";
			this->lblModel->Size = System::Drawing::Size(45, 15);
			this->lblModel->TabIndex = 15;
			this->lblModel->Text = L"Model:";
			// 
			// txtModel
			// 
			this->txtModel->Location = System::Drawing::Point(175, 356);
			this->txtModel->Name = L"txtModel";
			this->txtModel->Size = System::Drawing::Size(140, 24);
			this->txtModel->TabIndex = 16;
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
			this->btnAdd->Location = System::Drawing::Point(20, 396);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(140, 34);
			this->btnAdd->TabIndex = 17;
			this->btnAdd->Text = L"Add Tool";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &inventory::btnAdd_Click);
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
			this->btnUpdate->Location = System::Drawing::Point(175, 396);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(140, 34);
			this->btnUpdate->TabIndex = 18;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &inventory::btnUpdate_Click);
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
			this->btnDelete->Location = System::Drawing::Point(20, 440);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(140, 34);
			this->btnDelete->TabIndex = 19;
			this->btnDelete->Text = L"Delete Tool";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &inventory::btnDelete_Click);
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnClear->FlatAppearance->BorderSize = 0;
			this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClear->ForeColor = System::Drawing::Color::White;
			this->btnClear->Location = System::Drawing::Point(175, 440);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(140, 34);
			this->btnClear->TabIndex = 20;
			this->btnClear->Text = L"Clear Form";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &inventory::btnClear_Click);
			// 
			// dgvTools
			// 
			this->dgvTools->AllowUserToAddRows = false;
			this->dgvTools->AllowUserToDeleteRows = false;
			this->dgvTools->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvTools->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dgvTools->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgvTools->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTools->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvTools->Location = System::Drawing::Point(0, 125);
			this->dgvTools->MultiSelect = false;
			this->dgvTools->Name = L"dgvTools";
			this->dgvTools->ReadOnly = true;
			this->dgvTools->RowHeadersVisible = false;
			this->dgvTools->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvTools->Size = System::Drawing::Size(815, 555);
			this->dgvTools->TabIndex = 3;
			this->dgvTools->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &inventory::dgvTools_CellClick);
			this->dgvTools->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &inventory::dgvTools_CellContentClick);
			this->dgvTools->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &inventory::dgvTools_CellFormatting);
			this->dgvTools->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &inventory::dgvTools_DataError);
			// 
			// inventory
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->ClientSize = System::Drawing::Size(1150, 680);
			this->Controls->Add(this->dgvTools);
			this->Controls->Add(this->pnlEditor);
			this->Controls->Add(this->pnlFilter);
			this->Controls->Add(this->pnlHeader);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1000, 600);
			this->Name = L"inventory";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rent-A-Tool - Inventory Management";
			this->Load += gcnew System::EventHandler(this, &inventory::inventory_Load);
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlFilter->ResumeLayout(false);
			this->pnlFilter->PerformLayout();
			this->pnlEditor->ResumeLayout(false);
			this->pnlEditor->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDailyRate))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDeposit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTools))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

void dgvTools_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e)
		{
			e->ThrowException = false;
		}

		void inventory_Load(System::Object^ sender, System::EventArgs^ e)
		{
			if (this->DesignMode) return;
			try {
				LoadCategories();
				LoadTools();
			} catch (Exception^) {}
		}

		void LoadCategories()
		{
			cmbCatFilter->Items->Clear();
			cmbCatFilter->Items->Add(L"All");
			List<String^>^ cats = Data::ToolService::GetCategories();
			for each (String^ c in cats) {
				cmbCatFilter->Items->Add(c);
			}
			cmbCatFilter->SelectedIndex = 0;
		}

		void LoadTools()
		{
			String^ search = txtSearch->Text;
			String^ cat = cmbCatFilter->SelectedItem != nullptr ? cmbCatFilter->SelectedItem->ToString() : "All";
			String^ stat = cmbStatFilter->SelectedItem != nullptr ? cmbStatFilter->SelectedItem->ToString() : "All";

			DataTable^ dt = Data::ToolService::GetAllTools(search, cat, stat);
			dgvTools->DataSource = dt;

			// Format headers
			if (dgvTools->Columns->Contains("id")) {
				dgvTools->Columns["id"]->HeaderText = L"ID";
				dgvTools->Columns["id"]->FillWeight = 40;
			}
			if (dgvTools->Columns->Contains("tool_code")) dgvTools->Columns["tool_code"]->HeaderText = L"Code";
			if (dgvTools->Columns->Contains("name")) dgvTools->Columns["name"]->HeaderText = L"Tool Name";
			if (dgvTools->Columns->Contains("category")) dgvTools->Columns["category"]->HeaderText = L"Category";
			if (dgvTools->Columns->Contains("daily_rate")) dgvTools->Columns["daily_rate"]->HeaderText = L"Daily Rate (LKR)";
			if (dgvTools->Columns->Contains("deposit")) dgvTools->Columns["deposit"]->HeaderText = L"Deposit (LKR)";
			if (dgvTools->Columns->Contains("status")) dgvTools->Columns["status"]->HeaderText = L"Status";
			if (dgvTools->Columns->Contains("brand")) dgvTools->Columns["brand"]->HeaderText = L"Brand";
			if (dgvTools->Columns->Contains("model_serial")) dgvTools->Columns["model_serial"]->HeaderText = L"Model/Serial";
			if (dgvTools->Columns->Contains("condition_status")) dgvTools->Columns["condition_status"]->HeaderText = L"Condition";
			if (dgvTools->Columns->Contains("created_at")) dgvTools->Columns["created_at"]->Visible = false;
		}

		void FilterChanged(System::Object^ sender, System::EventArgs^ e)
		{
			LoadTools();
		}

		void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e)
		{
			LoadCategories();
			LoadTools();
			ClearForm();
		}

		void ClearForm()
		{
			selectedToolId = -1;
			try {
				txtCode->Text = Data::CodeGenerator::GetNextToolCode();
			} catch (Exception^) {
				txtCode->Text = L"T-0001";
			}
			txtName->Clear();
			if (cmbCategory->Items->Count > 0) cmbCategory->SelectedIndex = 0;
			numDailyRate->Value = 0;
			numDeposit->Value = 0;
			if (cmbStatus->Items->Count > 0) cmbStatus->SelectedIndex = 0;
			txtBrand->Clear();
			txtModel->Clear();
			lblEditorTitle->Text = L"Tool Details";
		}

		void btnClear_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ClearForm();
			txtName->Focus();
		}

		void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		void dgvTools_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0 && e->RowIndex < dgvTools->Rows->Count) {
				DataGridViewRow^ row = dgvTools->Rows[e->RowIndex];
				selectedToolId = Convert::ToInt32(row->Cells["id"]->Value);
				txtCode->Text = row->Cells["tool_code"]->Value->ToString();
				txtName->Text = row->Cells["name"]->Value->ToString();

				String^ cat = row->Cells["category"]->Value != nullptr ? row->Cells["category"]->Value->ToString() : "";
				if (cmbCategory->Items->Contains(cat)) cmbCategory->SelectedItem = cat;
				else cmbCategory->Text = cat;

				numDailyRate->Value = Convert::ToDecimal(row->Cells["daily_rate"]->Value);
				numDeposit->Value = Convert::ToDecimal(row->Cells["deposit"]->Value);

				String^ stat = row->Cells["status"]->Value->ToString();
				if (cmbStatus->Items->Contains(stat)) cmbStatus->SelectedItem = stat;

				txtBrand->Text = row->Cells["brand"]->Value != nullptr ? row->Cells["brand"]->Value->ToString() : "";
				txtModel->Text = row->Cells["model_serial"]->Value != nullptr ? row->Cells["model_serial"]->Value->ToString() : "";

				lblEditorTitle->Text = L"Edit Tool: #" + selectedToolId;
			}
		}

		void dgvTools_CellFormatting(System::Object^ sender, DataGridViewCellFormattingEventArgs^ e)
		{
			if (dgvTools->Columns[e->ColumnIndex]->Name == "status" && e->Value != nullptr) {
				String^ val = e->Value->ToString();
				if (val == "Available") {
					e->CellStyle->ForeColor = Color::DarkGreen;
					e->CellStyle->Font = gcnew Drawing::Font(dgvTools->Font, FontStyle::Bold);
				}
				else if (val == "Rented") {
					e->CellStyle->ForeColor = Color::FromArgb(192, 57, 43); // Dark red
					e->CellStyle->Font = gcnew Drawing::Font(dgvTools->Font, FontStyle::Bold);
				}
				else if (val == "Maintenance") {
					e->CellStyle->ForeColor = Color::FromArgb(211, 84, 0); // Orange
				}
			}
		}

		void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ name = txtName->Text->Trim();
			String^ cat = cmbCategory->Text->Trim();
			Decimal rate = numDailyRate->Value;
			Decimal dep = numDeposit->Value;
			String^ stat = cmbStatus->SelectedItem != nullptr ? cmbStatus->SelectedItem->ToString() : "Available";
			String^ brand = txtBrand->Text->Trim();
			String^ model = txtModel->Text->Trim();

			if (name->Length == 0) {
				MessageBox::Show(this, L"Please enter tool name.", L"Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				txtName->Focus();
				return;
			}

			String^ assignedCode = nullptr;
			String^ err = Data::ToolService::AddTool(assignedCode, name, cat, rate, dep, stat, brand, model, L"");
			if (err->Length == 0) {
				MessageBox::Show(this, String::Format(L"Tool added successfully!\nAssigned Code: {0}", assignedCode),
					L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadCategories();
				LoadTools();
				ClearForm();
				txtName->Focus();
			}
			else {
				MessageBox::Show(this, err, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedToolId <= 0) {
				MessageBox::Show(this, L"Please select a tool from the table to update.", L"Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			String^ code = txtCode->Text->Trim();
			String^ name = txtName->Text->Trim();
			String^ cat = cmbCategory->Text->Trim();
			Decimal rate = numDailyRate->Value;
			Decimal dep = numDeposit->Value;
			String^ stat = cmbStatus->SelectedItem != nullptr ? cmbStatus->SelectedItem->ToString() : "Available";
			String^ brand = txtBrand->Text->Trim();
			String^ model = txtModel->Text->Trim();

			if (name->Length == 0) {
				MessageBox::Show(this, L"Please enter tool name.", L"Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				txtName->Focus();
				return;
			}

			String^ err = Data::ToolService::UpdateTool(selectedToolId, code, name, cat, rate, dep, stat, brand, model, L"");
			if (err->Length == 0) {
				MessageBox::Show(this, L"Tool updated successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadTools();
				ClearForm();
				txtName->Focus();
			}
			else {
				MessageBox::Show(this, err, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedToolId <= 0) {
				MessageBox::Show(this, L"Please select a tool to delete.", L"Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			if (MessageBox::Show(this, L"Are you sure you want to delete this tool?", L"Confirm Delete", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				String^ err = Data::ToolService::DeleteTool(selectedToolId);
				if (err->Length == 0) {
					MessageBox::Show(this, L"Tool deleted successfully.", L"Deleted", MessageBoxButtons::OK, MessageBoxIcon::Information);
					LoadCategories();
					LoadTools();
					ClearForm();
				}
				else {
					MessageBox::Show(this, err, L"Cannot Delete", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
		}
	private: System::Void dgvTools_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
};
}
