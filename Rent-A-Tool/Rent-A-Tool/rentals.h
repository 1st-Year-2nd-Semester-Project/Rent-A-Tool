#pragma once
#include "Data/RentalService.h"
#include "Data/CustomerService.h"
#include "Data/ToolService.h"
#include "Data/authresult.h"

namespace RentATool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class rentals : public System::Windows::Forms::Form
	{
	public:
		rentals(void)
		{
			selectedRentalId = -1;
			selectedToolId = -1;
			selectedDeposit = Decimal(0);
			selectedDailyRate = Decimal(0);
			lateFeePerDay = Decimal(0);

			InitializeComponent();
		}

	protected:
		~rentals()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int selectedRentalId;
		int selectedToolId;
		Decimal selectedDeposit;
		Decimal selectedDailyRate;
		DateTime selectedRentDate;
		DateTime selectedDueDate;
		Decimal lateFeePerDay;

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblTitle;
		System::Windows::Forms::Label^ lblSubtitle;
		System::Windows::Forms::Button^ btnClose;
		System::Windows::Forms::TabControl^ tabControl1;
		System::Windows::Forms::TabPage^ tabRentalsList;
		System::Windows::Forms::TabPage^ tabNewRental;
		System::Windows::Forms::Panel^ pnlListFilter;
		System::Windows::Forms::Label^ lblFilterStatus;
		System::Windows::Forms::ComboBox^ cmbFilterStatus;
		System::Windows::Forms::Label^ lblSearch;
		System::Windows::Forms::TextBox^ txtSearch;
		System::Windows::Forms::Button^ btnRefresh;
		System::Windows::Forms::DataGridView^ dgvRentals;
		System::Windows::Forms::Panel^ pnlReturnAction;
		System::Windows::Forms::Label^ lblReturnTitle;
		System::Windows::Forms::Label^ lblReturnInfo;
		System::Windows::Forms::Label^ lblReturnDate;
		System::Windows::Forms::DateTimePicker^ dtpReturnDate;
		System::Windows::Forms::Label^ lblLateFeeCalc;
		System::Windows::Forms::Label^ lblTotalCalc;
		System::Windows::Forms::Label^ lblRefundCalc;
		System::Windows::Forms::Button^ btnProcessReturn;
		System::Windows::Forms::Panel^ pnlNewRental;
		System::Windows::Forms::Label^ lblNewTitle;
		System::Windows::Forms::Label^ lblCustomer;
		System::Windows::Forms::ComboBox^ cmbCustomer;
		System::Windows::Forms::Label^ lblTool;
		System::Windows::Forms::ComboBox^ cmbTool;
		System::Windows::Forms::Label^ lblRentDate;
		System::Windows::Forms::DateTimePicker^ dtpRentDate;
		System::Windows::Forms::Label^ lblDueDate;
		System::Windows::Forms::DateTimePicker^ dtpDueDate;
		System::Windows::Forms::Label^ lblDeposit;
		System::Windows::Forms::NumericUpDown^ numDeposit;
		System::Windows::Forms::Label^ lblNotes;
		System::Windows::Forms::TextBox^ txtNotes;
		System::Windows::Forms::Panel^ pnlSummaryCard;
		System::Windows::Forms::Label^ lblSummaryTitle;
		System::Windows::Forms::Label^ lblSumDays;
		System::Windows::Forms::Label^ lblSumDailyRate;
		System::Windows::Forms::Label^ lblSumTotalRent;
		System::Windows::Forms::Label^ lblSumDeposit;
		System::Windows::Forms::Button^ btnIssueRental;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(rentals::typeid));
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabRentalsList = (gcnew System::Windows::Forms::TabPage());
			this->dgvRentals = (gcnew System::Windows::Forms::DataGridView());
			this->pnlReturnAction = (gcnew System::Windows::Forms::Panel());
			this->lblReturnTitle = (gcnew System::Windows::Forms::Label());
			this->lblReturnInfo = (gcnew System::Windows::Forms::Label());
			this->lblReturnDate = (gcnew System::Windows::Forms::Label());
			this->dtpReturnDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblLateFeeCalc = (gcnew System::Windows::Forms::Label());
			this->lblTotalCalc = (gcnew System::Windows::Forms::Label());
			this->lblRefundCalc = (gcnew System::Windows::Forms::Label());
			this->btnProcessReturn = (gcnew System::Windows::Forms::Button());
			this->pnlListFilter = (gcnew System::Windows::Forms::Panel());
			this->lblFilterStatus = (gcnew System::Windows::Forms::Label());
			this->cmbFilterStatus = (gcnew System::Windows::Forms::ComboBox());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->tabNewRental = (gcnew System::Windows::Forms::TabPage());
			this->pnlNewRental = (gcnew System::Windows::Forms::Panel());
			this->lblNewTitle = (gcnew System::Windows::Forms::Label());
			this->lblCustomer = (gcnew System::Windows::Forms::Label());
			this->cmbCustomer = (gcnew System::Windows::Forms::ComboBox());
			this->lblTool = (gcnew System::Windows::Forms::Label());
			this->cmbTool = (gcnew System::Windows::Forms::ComboBox());
			this->lblRentDate = (gcnew System::Windows::Forms::Label());
			this->dtpRentDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblDueDate = (gcnew System::Windows::Forms::Label());
			this->dtpDueDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblDeposit = (gcnew System::Windows::Forms::Label());
			this->numDeposit = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblNotes = (gcnew System::Windows::Forms::Label());
			this->txtNotes = (gcnew System::Windows::Forms::TextBox());
			this->pnlSummaryCard = (gcnew System::Windows::Forms::Panel());
			this->lblSummaryTitle = (gcnew System::Windows::Forms::Label());
			this->lblSumDays = (gcnew System::Windows::Forms::Label());
			this->lblSumDailyRate = (gcnew System::Windows::Forms::Label());
			this->lblSumTotalRent = (gcnew System::Windows::Forms::Label());
			this->lblSumDeposit = (gcnew System::Windows::Forms::Label());
			this->btnIssueRental = (gcnew System::Windows::Forms::Button());
			this->pnlHeader->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabRentalsList->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRentals))->BeginInit();
			this->pnlReturnAction->SuspendLayout();
			this->pnlListFilter->SuspendLayout();
			this->tabNewRental->SuspendLayout();
			this->pnlNewRental->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDeposit))->BeginInit();
			this->pnlSummaryCard->SuspendLayout();
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
			this->pnlHeader->Size = System::Drawing::Size(1180, 70);
			this->pnlHeader->TabIndex = 0;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(20, 12);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(436, 30);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"RENTAL MANAGEMENT & TRANSACTIONS";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->lblSubtitle->Location = System::Drawing::Point(22, 42);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(413, 17);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"Issue tool rentals, calculate fees, track due dates, and process returns";
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
			this->btnClose->Location = System::Drawing::Point(1000, 18);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(155, 35);
			this->btnClose->TabIndex = 2;
			this->btnClose->Text = L"Back to Dashboard";
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &rentals::btnClose_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabRentalsList);
			this->tabControl1->Controls->Add(this->tabNewRental);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.5F));
			this->tabControl1->Location = System::Drawing::Point(0, 70);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1180, 650);
			this->tabControl1->TabIndex = 1;
			// 
			// tabRentalsList
			// 
			this->tabRentalsList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->tabRentalsList->Controls->Add(this->dgvRentals);
			this->tabRentalsList->Controls->Add(this->pnlReturnAction);
			this->tabRentalsList->Controls->Add(this->pnlListFilter);
			this->tabRentalsList->Location = System::Drawing::Point(4, 28);
			this->tabRentalsList->Name = L"tabRentalsList";
			this->tabRentalsList->Padding = System::Windows::Forms::Padding(3);
			this->tabRentalsList->Size = System::Drawing::Size(1172, 618);
			this->tabRentalsList->TabIndex = 0;
			this->tabRentalsList->Text = L"  Active & All Rentals  ";
			// 
			// dgvRentals
			// 
			this->dgvRentals->AllowUserToAddRows = false;
			this->dgvRentals->AllowUserToDeleteRows = false;
			this->dgvRentals->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvRentals->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dgvRentals->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgvRentals->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvRentals->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvRentals->Location = System::Drawing::Point(3, 58);
			this->dgvRentals->MultiSelect = false;
			this->dgvRentals->Name = L"dgvRentals";
			this->dgvRentals->ReadOnly = true;
			this->dgvRentals->RowHeadersVisible = false;
			this->dgvRentals->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvRentals->Size = System::Drawing::Size(1166, 437);
			this->dgvRentals->TabIndex = 1;
			this->dgvRentals->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &rentals::dgvRentals_CellClick);
			this->dgvRentals->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &rentals::dgvRentals_CellFormatting);
			this->dgvRentals->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &rentals::dgvRentals_DataError);
			// 
			// pnlReturnAction
			// 
			this->pnlReturnAction->BackColor = System::Drawing::Color::White;
			this->pnlReturnAction->Controls->Add(this->lblReturnTitle);
			this->pnlReturnAction->Controls->Add(this->lblReturnInfo);
			this->pnlReturnAction->Controls->Add(this->lblReturnDate);
			this->pnlReturnAction->Controls->Add(this->dtpReturnDate);
			this->pnlReturnAction->Controls->Add(this->lblLateFeeCalc);
			this->pnlReturnAction->Controls->Add(this->lblTotalCalc);
			this->pnlReturnAction->Controls->Add(this->lblRefundCalc);
			this->pnlReturnAction->Controls->Add(this->btnProcessReturn);
			this->pnlReturnAction->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pnlReturnAction->Location = System::Drawing::Point(3, 495);
			this->pnlReturnAction->Name = L"pnlReturnAction";
			this->pnlReturnAction->Padding = System::Windows::Forms::Padding(20, 10, 20, 10);
			this->pnlReturnAction->Size = System::Drawing::Size(1166, 120);
			this->pnlReturnAction->TabIndex = 2;
			// 
			// lblReturnTitle
			// 
			this->lblReturnTitle->AutoSize = true;
			this->lblReturnTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblReturnTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->lblReturnTitle->Location = System::Drawing::Point(20, 8);
			this->lblReturnTitle->Name = L"lblReturnTitle";
			this->lblReturnTitle->Size = System::Drawing::Size(250, 20);
			this->lblReturnTitle->TabIndex = 0;
			this->lblReturnTitle->Text = L"Process Return for Selected Rental";
			// 
			// lblReturnInfo
			// 
			this->lblReturnInfo->AutoSize = true;
			this->lblReturnInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lblReturnInfo->Location = System::Drawing::Point(20, 34);
			this->lblReturnInfo->Name = L"lblReturnInfo";
			this->lblReturnInfo->Size = System::Drawing::Size(461, 19);
			this->lblReturnInfo->TabIndex = 1;
			this->lblReturnInfo->Text = L"Select an Active or Overdue rental from the table above to process return.";
			// 
			// lblReturnDate
			// 
			this->lblReturnDate->AutoSize = true;
			this->lblReturnDate->Location = System::Drawing::Point(20, 65);
			this->lblReturnDate->Name = L"lblReturnDate";
			this->lblReturnDate->Size = System::Drawing::Size(86, 19);
			this->lblReturnDate->TabIndex = 2;
			this->lblReturnDate->Text = L"Return Date:";
			// 
			// dtpReturnDate
			// 
			this->dtpReturnDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpReturnDate->Location = System::Drawing::Point(110, 62);
			this->dtpReturnDate->Name = L"dtpReturnDate";
			this->dtpReturnDate->Size = System::Drawing::Size(120, 26);
			this->dtpReturnDate->TabIndex = 3;
			this->dtpReturnDate->ValueChanged += gcnew System::EventHandler(this, &rentals::dtpReturnDate_ValueChanged);
			// 
			// lblLateFeeCalc
			// 
			this->lblLateFeeCalc->AutoSize = true;
			this->lblLateFeeCalc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblLateFeeCalc->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->lblLateFeeCalc->Location = System::Drawing::Point(260, 65);
			this->lblLateFeeCalc->Name = L"lblLateFeeCalc";
			this->lblLateFeeCalc->Size = System::Drawing::Size(119, 17);
			this->lblLateFeeCalc->TabIndex = 4;
			this->lblLateFeeCalc->Text = L"Late Fee: LKR 0.00";
			// 
			// lblTotalCalc
			// 
			this->lblTotalCalc->AutoSize = true;
			this->lblTotalCalc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblTotalCalc->Location = System::Drawing::Point(440, 65);
			this->lblTotalCalc->Name = L"lblTotalCalc";
			this->lblTotalCalc->Size = System::Drawing::Size(133, 17);
			this->lblTotalCalc->TabIndex = 5;
			this->lblTotalCalc->Text = L"Final Total: LKR 0.00";
			// 
			// lblRefundCalc
			// 
			this->lblRefundCalc->AutoSize = true;
			this->lblRefundCalc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblRefundCalc->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->lblRefundCalc->Location = System::Drawing::Point(630, 65);
			this->lblRefundCalc->Name = L"lblRefundCalc";
			this->lblRefundCalc->Size = System::Drawing::Size(141, 17);
			this->lblRefundCalc->TabIndex = 6;
			this->lblRefundCalc->Text = L"Refund Due: LKR 0.00";
			// 
			// btnProcessReturn
			// 
			this->btnProcessReturn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->btnProcessReturn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnProcessReturn->Enabled = false;
			this->btnProcessReturn->FlatAppearance->BorderSize = 0;
			this->btnProcessReturn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnProcessReturn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnProcessReturn->ForeColor = System::Drawing::Color::White;
			this->btnProcessReturn->Location = System::Drawing::Point(820, 58);
			this->btnProcessReturn->Name = L"btnProcessReturn";
			this->btnProcessReturn->Size = System::Drawing::Size(170, 35);
			this->btnProcessReturn->TabIndex = 7;
			this->btnProcessReturn->Text = L"Complete Return";
			this->btnProcessReturn->UseVisualStyleBackColor = false;
			this->btnProcessReturn->Click += gcnew System::EventHandler(this, &rentals::btnProcessReturn_Click);
			// 
			// pnlListFilter
			// 
			this->pnlListFilter->BackColor = System::Drawing::Color::White;
			this->pnlListFilter->Controls->Add(this->lblFilterStatus);
			this->pnlListFilter->Controls->Add(this->cmbFilterStatus);
			this->pnlListFilter->Controls->Add(this->lblSearch);
			this->pnlListFilter->Controls->Add(this->txtSearch);
			this->pnlListFilter->Controls->Add(this->btnRefresh);
			this->pnlListFilter->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlListFilter->Location = System::Drawing::Point(3, 3);
			this->pnlListFilter->Name = L"pnlListFilter";
			this->pnlListFilter->Size = System::Drawing::Size(1166, 55);
			this->pnlListFilter->TabIndex = 0;
			// 
			// lblFilterStatus
			// 
			this->lblFilterStatus->AutoSize = true;
			this->lblFilterStatus->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblFilterStatus->Location = System::Drawing::Point(20, 16);
			this->lblFilterStatus->Name = L"lblFilterStatus";
			this->lblFilterStatus->Size = System::Drawing::Size(86, 17);
			this->lblFilterStatus->TabIndex = 0;
			this->lblFilterStatus->Text = L"Filter Status:";
			// 
			// cmbFilterStatus
			// 
			this->cmbFilterStatus->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbFilterStatus->FormattingEnabled = true;
			this->cmbFilterStatus->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"All", L"Active", L"Overdue", L"Returned" });
			this->cmbFilterStatus->Location = System::Drawing::Point(110, 13);
			this->cmbFilterStatus->Name = L"cmbFilterStatus";
			this->cmbFilterStatus->Size = System::Drawing::Size(130, 27);
			this->cmbFilterStatus->TabIndex = 1;
			this->cmbFilterStatus->SelectedIndexChanged += gcnew System::EventHandler(this, &rentals::FilterChanged);
			// 
			// lblSearch
			// 
			this->lblSearch->AutoSize = true;
			this->lblSearch->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblSearch->Location = System::Drawing::Point(270, 16);
			this->lblSearch->Name = L"lblSearch";
			this->lblSearch->Size = System::Drawing::Size(52, 17);
			this->lblSearch->TabIndex = 2;
			this->lblSearch->Text = L"Search:";
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(330, 13);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(240, 26);
			this->txtSearch->TabIndex = 3;
			this->txtSearch->TextChanged += gcnew System::EventHandler(this, &rentals::FilterChanged);
			// 
			// btnRefresh
			// 
			this->btnRefresh->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->btnRefresh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRefresh->FlatAppearance->BorderSize = 0;
			this->btnRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRefresh->ForeColor = System::Drawing::Color::White;
			this->btnRefresh->Location = System::Drawing::Point(585, 12);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(90, 28);
			this->btnRefresh->TabIndex = 4;
			this->btnRefresh->Text = L"Refresh";
			this->btnRefresh->UseVisualStyleBackColor = false;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &rentals::btnRefresh_Click);
			// 
			// tabNewRental
			// 
			this->tabNewRental->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->tabNewRental->Controls->Add(this->pnlNewRental);
			this->tabNewRental->Location = System::Drawing::Point(4, 28);
			this->tabNewRental->Name = L"tabNewRental";
			this->tabNewRental->Padding = System::Windows::Forms::Padding(3);
			this->tabNewRental->Size = System::Drawing::Size(1172, 618);
			this->tabNewRental->TabIndex = 1;
			this->tabNewRental->Text = L"  + Issue New Rental  ";
			// 
			// pnlNewRental
			// 
			this->pnlNewRental->BackColor = System::Drawing::Color::White;
			this->pnlNewRental->Controls->Add(this->lblNewTitle);
			this->pnlNewRental->Controls->Add(this->lblCustomer);
			this->pnlNewRental->Controls->Add(this->cmbCustomer);
			this->pnlNewRental->Controls->Add(this->lblTool);
			this->pnlNewRental->Controls->Add(this->cmbTool);
			this->pnlNewRental->Controls->Add(this->lblRentDate);
			this->pnlNewRental->Controls->Add(this->dtpRentDate);
			this->pnlNewRental->Controls->Add(this->lblDueDate);
			this->pnlNewRental->Controls->Add(this->dtpDueDate);
			this->pnlNewRental->Controls->Add(this->lblDeposit);
			this->pnlNewRental->Controls->Add(this->numDeposit);
			this->pnlNewRental->Controls->Add(this->lblNotes);
			this->pnlNewRental->Controls->Add(this->txtNotes);
			this->pnlNewRental->Controls->Add(this->pnlSummaryCard);
			this->pnlNewRental->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlNewRental->Location = System::Drawing::Point(3, 3);
			this->pnlNewRental->Name = L"pnlNewRental";
			this->pnlNewRental->Padding = System::Windows::Forms::Padding(30);
			this->pnlNewRental->Size = System::Drawing::Size(1166, 612);
			this->pnlNewRental->TabIndex = 0;
			// 
			// lblNewTitle
			// 
			this->lblNewTitle->AutoSize = true;
			this->lblNewTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->lblNewTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->lblNewTitle->Location = System::Drawing::Point(30, 20);
			this->lblNewTitle->Name = L"lblNewTitle";
			this->lblNewTitle->Size = System::Drawing::Size(281, 25);
			this->lblNewTitle->TabIndex = 0;
			this->lblNewTitle->Text = L"Issue a New Rental Agreement";
			// 
			// lblCustomer
			// 
			this->lblCustomer->AutoSize = true;
			this->lblCustomer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblCustomer->Location = System::Drawing::Point(30, 65);
			this->lblCustomer->Name = L"lblCustomer";
			this->lblCustomer->Size = System::Drawing::Size(112, 17);
			this->lblCustomer->TabIndex = 1;
			this->lblCustomer->Text = L"Select Customer:";
			// 
			// cmbCustomer
			// 
			this->cmbCustomer->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCustomer->FormattingEnabled = true;
			this->cmbCustomer->Location = System::Drawing::Point(30, 87);
			this->cmbCustomer->Name = L"cmbCustomer";
			this->cmbCustomer->Size = System::Drawing::Size(460, 27);
			this->cmbCustomer->TabIndex = 2;
			this->cmbCustomer->SelectedIndexChanged += gcnew System::EventHandler(this, &rentals::NewRentalInputChanged);
			// 
			// lblTool
			// 
			this->lblTool->AutoSize = true;
			this->lblTool->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblTool->Location = System::Drawing::Point(30, 130);
			this->lblTool->Name = L"lblTool";
			this->lblTool->Size = System::Drawing::Size(140, 17);
			this->lblTool->TabIndex = 3;
			this->lblTool->Text = L"Select Available Tool:";
			// 
			// cmbTool
			// 
			this->cmbTool->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTool->FormattingEnabled = true;
			this->cmbTool->Location = System::Drawing::Point(30, 152);
			this->cmbTool->Name = L"cmbTool";
			this->cmbTool->Size = System::Drawing::Size(460, 27);
			this->cmbTool->TabIndex = 4;
			this->cmbTool->SelectedIndexChanged += gcnew System::EventHandler(this, &rentals::cmbTool_SelectedIndexChanged);
			// 
			// lblRentDate
			// 
			this->lblRentDate->AutoSize = true;
			this->lblRentDate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblRentDate->Location = System::Drawing::Point(30, 195);
			this->lblRentDate->Name = L"lblRentDate";
			this->lblRentDate->Size = System::Drawing::Size(73, 17);
			this->lblRentDate->TabIndex = 5;
			this->lblRentDate->Text = L"Rent Date:";
			// 
			// dtpRentDate
			// 
			this->dtpRentDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpRentDate->Location = System::Drawing::Point(30, 217);
			this->dtpRentDate->Name = L"dtpRentDate";
			this->dtpRentDate->Size = System::Drawing::Size(215, 26);
			this->dtpRentDate->TabIndex = 6;
			this->dtpRentDate->ValueChanged += gcnew System::EventHandler(this, &rentals::NewRentalInputChanged);
			// 
			// lblDueDate
			// 
			this->lblDueDate->AutoSize = true;
			this->lblDueDate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblDueDate->Location = System::Drawing::Point(275, 195);
			this->lblDueDate->Name = L"lblDueDate";
			this->lblDueDate->Size = System::Drawing::Size(70, 17);
			this->lblDueDate->TabIndex = 7;
			this->lblDueDate->Text = L"Due Date:";
			// 
			// dtpDueDate
			// 
			this->dtpDueDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpDueDate->Location = System::Drawing::Point(275, 217);
			this->dtpDueDate->Name = L"dtpDueDate";
			this->dtpDueDate->Size = System::Drawing::Size(215, 26);
			this->dtpDueDate->TabIndex = 8;
			this->dtpDueDate->ValueChanged += gcnew System::EventHandler(this, &rentals::NewRentalInputChanged);
			// 
			// lblDeposit
			// 
			this->lblDeposit->AutoSize = true;
			this->lblDeposit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblDeposit->Location = System::Drawing::Point(30, 260);
			this->lblDeposit->Name = L"lblDeposit";
			this->lblDeposit->Size = System::Drawing::Size(128, 17);
			this->lblDeposit->TabIndex = 9;
			this->lblDeposit->Text = L"Deposit Paid (LKR):";
			// 
			// numDeposit
			// 
			this->numDeposit->DecimalPlaces = 2;
			this->numDeposit->Location = System::Drawing::Point(30, 282);
			this->numDeposit->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000000, 0, 0, 0 });
			this->numDeposit->Name = L"numDeposit";
			this->numDeposit->Size = System::Drawing::Size(215, 26);
			this->numDeposit->TabIndex = 10;
			this->numDeposit->ValueChanged += gcnew System::EventHandler(this, &rentals::NewRentalInputChanged);
			// 
			// lblNotes
			// 
			this->lblNotes->AutoSize = true;
			this->lblNotes->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblNotes->Location = System::Drawing::Point(30, 320);
			this->lblNotes->Name = L"lblNotes";
			this->lblNotes->Size = System::Drawing::Size(219, 17);
			this->lblNotes->TabIndex = 11;
			this->lblNotes->Text = L"Rental Notes / Condition remarks:";
			// 
			// txtNotes
			// 
			this->txtNotes->Location = System::Drawing::Point(30, 342);
			this->txtNotes->Multiline = true;
			this->txtNotes->Name = L"txtNotes";
			this->txtNotes->Size = System::Drawing::Size(460, 60);
			this->txtNotes->TabIndex = 12;
			// 
			// pnlSummaryCard
			// 
			this->pnlSummaryCard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(248)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->pnlSummaryCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlSummaryCard->Controls->Add(this->lblSummaryTitle);
			this->pnlSummaryCard->Controls->Add(this->lblSumDays);
			this->pnlSummaryCard->Controls->Add(this->lblSumDailyRate);
			this->pnlSummaryCard->Controls->Add(this->lblSumTotalRent);
			this->pnlSummaryCard->Controls->Add(this->lblSumDeposit);
			this->pnlSummaryCard->Controls->Add(this->btnIssueRental);
			this->pnlSummaryCard->Location = System::Drawing::Point(550, 65);
			this->pnlSummaryCard->Name = L"pnlSummaryCard";
			this->pnlSummaryCard->Padding = System::Windows::Forms::Padding(25);
			this->pnlSummaryCard->Size = System::Drawing::Size(450, 320);
			this->pnlSummaryCard->TabIndex = 13;
			// 
			// lblSummaryTitle
			// 
			this->lblSummaryTitle->AutoSize = true;
			this->lblSummaryTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblSummaryTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->lblSummaryTitle->Location = System::Drawing::Point(20, 20);
			this->lblSummaryTitle->Name = L"lblSummaryTitle";
			this->lblSummaryTitle->Size = System::Drawing::Size(182, 21);
			this->lblSummaryTitle->TabIndex = 0;
			this->lblSummaryTitle->Text = L"Rental Cost Estimation";
			// 
			// lblSumDays
			// 
			this->lblSumDays->AutoSize = true;
			this->lblSumDays->Location = System::Drawing::Point(20, 65);
			this->lblSumDays->Name = L"lblSumDays";
			this->lblSumDays->Size = System::Drawing::Size(120, 19);
			this->lblSumDays->TabIndex = 1;
			this->lblSumDays->Text = L"Duration: 3 Day(s)";
			// 
			// lblSumDailyRate
			// 
			this->lblSumDailyRate->AutoSize = true;
			this->lblSumDailyRate->Location = System::Drawing::Point(20, 105);
			this->lblSumDailyRate->Name = L"lblSumDailyRate";
			this->lblSumDailyRate->Size = System::Drawing::Size(131, 19);
			this->lblSumDailyRate->TabIndex = 2;
			this->lblSumDailyRate->Text = L"Daily Rate: LKR 0.00";
			// 
			// lblSumTotalRent
			// 
			this->lblSumTotalRent->AutoSize = true;
			this->lblSumTotalRent->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblSumTotalRent->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->lblSumTotalRent->Location = System::Drawing::Point(20, 150);
			this->lblSumTotalRent->Name = L"lblSumTotalRent";
			this->lblSumTotalRent->Size = System::Drawing::Size(226, 20);
			this->lblSumTotalRent->TabIndex = 3;
			this->lblSumTotalRent->Text = L"Estimated Rent Total: LKR 0.00";
			// 
			// lblSumDeposit
			// 
			this->lblSumDeposit->AutoSize = true;
			this->lblSumDeposit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.5F, System::Drawing::FontStyle::Bold));
			this->lblSumDeposit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->lblSumDeposit->Location = System::Drawing::Point(20, 195);
			this->lblSumDeposit->Name = L"lblSumDeposit";
			this->lblSumDeposit->Size = System::Drawing::Size(190, 19);
			this->lblSumDeposit->TabIndex = 4;
			this->lblSumDeposit->Text = L"Required Deposit: LKR 0.00";
			// 
			// btnIssueRental
			// 
			this->btnIssueRental->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->btnIssueRental->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnIssueRental->FlatAppearance->BorderSize = 0;
			this->btnIssueRental->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIssueRental->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btnIssueRental->ForeColor = System::Drawing::Color::White;
			this->btnIssueRental->Location = System::Drawing::Point(20, 245);
			this->btnIssueRental->Name = L"btnIssueRental";
			this->btnIssueRental->Size = System::Drawing::Size(405, 45);
			this->btnIssueRental->TabIndex = 5;
			this->btnIssueRental->Text = L"Confirm & Issue Rental";
			this->btnIssueRental->UseVisualStyleBackColor = false;
			this->btnIssueRental->Click += gcnew System::EventHandler(this, &rentals::btnIssueRental_Click);
			// 
			// rentals
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->ClientSize = System::Drawing::Size(1180, 720);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->pnlHeader);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1020, 640);
			this->Name = L"rentals";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rent-A-Tool - Rental Management";
			this->Load += gcnew System::EventHandler(this, &rentals::rentals_Load);
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabRentalsList->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRentals))->EndInit();
			this->pnlReturnAction->ResumeLayout(false);
			this->pnlReturnAction->PerformLayout();
			this->pnlListFilter->ResumeLayout(false);
			this->pnlListFilter->PerformLayout();
			this->tabNewRental->ResumeLayout(false);
			this->pnlNewRental->ResumeLayout(false);
			this->pnlNewRental->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDeposit))->EndInit();
			this->pnlSummaryCard->ResumeLayout(false);
			this->pnlSummaryCard->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		void dgvRentals_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e)
		{
			e->ThrowException = false;
		}

		void rentals_Load(System::Object^ sender, System::EventArgs^ e)
		{
			if (this->DesignMode) return;
			try {
				lateFeePerDay = Data::RentalService::GetLateFeePerDay();
				LoadCustomersForRental();
				LoadAvailableTools();
				LoadRentals();
			}
			catch (Exception^) {}
		}

		void LoadRentals()
		{
			String^ stat = cmbFilterStatus->SelectedItem != nullptr ? cmbFilterStatus->SelectedItem->ToString() : "All";
			String^ search = txtSearch->Text;
			DataTable^ dt = Data::RentalService::GetAllRentals(stat, search);
			dgvRentals->DataSource = dt;

			if (dgvRentals->Columns->Contains("id")) {
				dgvRentals->Columns["id"]->HeaderText = L"ID";
				dgvRentals->Columns["id"]->FillWeight = 35;
			}
			if (dgvRentals->Columns->Contains("rental_code")) dgvRentals->Columns["rental_code"]->HeaderText = L"Code";
			if (dgvRentals->Columns->Contains("customer_id")) dgvRentals->Columns["customer_id"]->Visible = false;
			if (dgvRentals->Columns->Contains("tool_id")) dgvRentals->Columns["tool_id"]->Visible = false;
			if (dgvRentals->Columns->Contains("customer_name")) dgvRentals->Columns["customer_name"]->HeaderText = L"Customer";
			if (dgvRentals->Columns->Contains("customer_phone")) dgvRentals->Columns["customer_phone"]->HeaderText = L"Phone";
			if (dgvRentals->Columns->Contains("customer_nic")) dgvRentals->Columns["customer_nic"]->Visible = false;
			if (dgvRentals->Columns->Contains("tool_name")) dgvRentals->Columns["tool_name"]->HeaderText = L"Tool";
			if (dgvRentals->Columns->Contains("tool_code")) dgvRentals->Columns["tool_code"]->HeaderText = L"Tool Code";
			if (dgvRentals->Columns->Contains("daily_rate")) dgvRentals->Columns["daily_rate"]->HeaderText = L"Daily Rate";
			if (dgvRentals->Columns->Contains("rent_date")) dgvRentals->Columns["rent_date"]->HeaderText = L"Rent Date";
			if (dgvRentals->Columns->Contains("due_date")) dgvRentals->Columns["due_date"]->HeaderText = L"Due Date";
			if (dgvRentals->Columns->Contains("return_date")) dgvRentals->Columns["return_date"]->HeaderText = L"Returned";
			if (dgvRentals->Columns->Contains("deposit_paid")) dgvRentals->Columns["deposit_paid"]->HeaderText = L"Deposit";
			if (dgvRentals->Columns->Contains("total_amount")) dgvRentals->Columns["total_amount"]->HeaderText = L"Total Rent";
			if (dgvRentals->Columns->Contains("status")) dgvRentals->Columns["status"]->HeaderText = L"Status";
			if (dgvRentals->Columns->Contains("notes")) dgvRentals->Columns["notes"]->Visible = false;
		}

		void LoadCustomersForRental()
		{
			cmbCustomer->Items->Clear();
			DataTable^ dt = Data::CustomerService::GetEligibleCustomers();
			for (int i = 0; i < dt->Rows->Count; i++) {
				DataRow^ row = dt->Rows[i];
				String^ item = String::Format("[{0}] {1} (NIC: {2}, Tel: {3})",
					row["id"], row["name"], row["nic"], row["phone"]);
				cmbCustomer->Items->Add(item);
			}
			if (cmbCustomer->Items->Count > 0) cmbCustomer->SelectedIndex = 0;
		}

		void LoadAvailableTools()
		{
			cmbTool->Items->Clear();
			DataTable^ dt = Data::ToolService::GetAvailableTools();
			for (int i = 0; i < dt->Rows->Count; i++) {
				DataRow^ row = dt->Rows[i];
				String^ item = String::Format("[{0}] {1} ({2}) - Rate: LKR {3}, Dep: LKR {4}",
					row["id"], row["name"], row["tool_code"], row["daily_rate"], row["deposit"]);
				cmbTool->Items->Add(item);
			}
			if (cmbTool->Items->Count > 0) {
				cmbTool->SelectedIndex = 0;
			}
		}

		void FilterChanged(System::Object^ sender, System::EventArgs^ e)
		{
			LoadRentals();
		}

		void btnRefresh_Click(System::Object^ sender, System::EventArgs^ e)
		{
			LoadRentals();
			LoadCustomersForRental();
			LoadAvailableTools();
		}

		void btnClose_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		void dgvRentals_CellFormatting(System::Object^ sender, DataGridViewCellFormattingEventArgs^ e)
		{
			if (dgvRentals->Columns[e->ColumnIndex]->Name == "status" && e->Value != nullptr) {
				String^ val = e->Value->ToString();
				if (val == "Active") {
					e->CellStyle->ForeColor = Color::FromArgb(41, 128, 185); // Blue
					e->CellStyle->Font = gcnew Drawing::Font(dgvRentals->Font, FontStyle::Bold);
				}
				else if (val == "Overdue") {
					e->CellStyle->ForeColor = Color::FromArgb(192, 57, 43); // Dark red
					e->CellStyle->Font = gcnew Drawing::Font(dgvRentals->Font, FontStyle::Bold);
				}
				else if (val == "Returned") {
					e->CellStyle->ForeColor = Color::FromArgb(39, 174, 96); // Green
				}
			}
		}

		void dgvRentals_CellClick(System::Object^ sender, DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex >= 0 && e->RowIndex < dgvRentals->Rows->Count) {
				DataGridViewRow^ row = dgvRentals->Rows[e->RowIndex];
				selectedRentalId = Convert::ToInt32(row->Cells["id"]->Value);
				selectedToolId = Convert::ToInt32(row->Cells["tool_id"]->Value);
				String^ status = row->Cells["status"]->Value->ToString();

				if (status == "Active" || status == "Overdue") {
					btnProcessReturn->Enabled = true;
					selectedDeposit = Convert::ToDecimal(row->Cells["deposit_paid"]->Value);
					selectedDailyRate = Convert::ToDecimal(row->Cells["daily_rate"]->Value);
					selectedRentDate = Convert::ToDateTime(row->Cells["rent_date"]->Value);
					selectedDueDate = Convert::ToDateTime(row->Cells["due_date"]->Value);

					lblReturnInfo->Text = String::Format("Rental: {0} | Customer: {1} | Tool: {2} (Due: {3})",
						row->Cells["rental_code"]->Value, row->Cells["customer_name"]->Value,
						row->Cells["tool_name"]->Value, selectedDueDate.ToShortDateString());

					dtpReturnDate->Value = DateTime::Today;
					CalculateReturnAmounts();
				}
				else {
					btnProcessReturn->Enabled = false;
					lblReturnInfo->Text = String::Format("Rental {0} is already marked as {1}.",
						row->Cells["rental_code"]->Value, status);
					lblLateFeeCalc->Text = L"Late Fee: LKR 0.00";
					lblTotalCalc->Text = L"Final Total: LKR " + row->Cells["total_amount"]->Value;
					lblRefundCalc->Text = L"Status: Complete";
				}
			}
		}

		void dtpReturnDate_ValueChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedRentalId > 0 && btnProcessReturn->Enabled) {
				CalculateReturnAmounts();
			}
		}

		void CalculateReturnAmounts()
		{
			DateTime retDate = dtpReturnDate->Value.Date;
			DateTime dueDate = selectedDueDate.Date;
			DateTime rentDate = selectedRentDate.Date;

			int overdueDays = (retDate - dueDate).Days;
			if (overdueDays < 0) overdueDays = 0;

			Decimal lateFee = overdueDays * lateFeePerDay;

			int rentalDays = (retDate - rentDate).Days;
			if (rentalDays < 1) rentalDays = 1;

			Decimal rentAmount = rentalDays * selectedDailyRate;
			Decimal finalTotal = rentAmount + lateFee;
			Decimal refund = selectedDeposit - finalTotal;

			lblLateFeeCalc->Text = String::Format("Late Fee ({0} d): LKR {1:F2}", overdueDays, lateFee);
			lblTotalCalc->Text = String::Format("Final Total ({0} d): LKR {1:F2}", rentalDays, finalTotal);

			if (refund >= 0) {
				lblRefundCalc->ForeColor = Color::FromArgb(39, 174, 96);
				lblRefundCalc->Text = String::Format("Refund to Cust: LKR {0:F2}", refund);
			}
			else {
				lblRefundCalc->ForeColor = Color::FromArgb(192, 57, 43);
				lblRefundCalc->Text = String::Format("Cust Owes: LKR {0:F2}", Math::Abs(refund));
			}
		}

		void btnProcessReturn_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (selectedRentalId <= 0) return;

			DateTime retDate = dtpReturnDate->Value.Date;
			DateTime rentDate = selectedRentDate.Date;
			int overdueDays = (retDate - selectedDueDate.Date).Days;
			if (overdueDays < 0) overdueDays = 0;
			Decimal lateFee = overdueDays * lateFeePerDay;
			int rentalDays = (retDate - rentDate).Days;
			if (rentalDays < 1) rentalDays = 1;
			Decimal finalTotal = (rentalDays * selectedDailyRate) + lateFee;

			String^ msg = String::Format("Confirm return for this rental?\n\nFinal Rental Total: LKR {0:F2}\nLate Fee: LKR {1:F2}\nDeposit Paid: LKR {2:F2}",
				finalTotal, lateFee, selectedDeposit);

			if (MessageBox::Show(this, msg, L"Confirm Return", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				String^ err = Data::RentalService::ProcessReturn(selectedRentalId, selectedToolId, retDate, finalTotal, L"Returned in good order");
				if (err->Length == 0) {
					MessageBox::Show(this, L"Rental return completed successfully! Tool is now available.", L"Return Complete", MessageBoxButtons::OK, MessageBoxIcon::Information);
					LoadRentals();
					LoadAvailableTools();
					btnProcessReturn->Enabled = false;
					lblReturnInfo->Text = L"Select an Active or Overdue rental to process return.";
				}
				else {
					MessageBox::Show(this, err, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		// Helpers for Tab 2 (New Rental)
		void cmbTool_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (cmbTool->SelectedItem != nullptr) {
				String^ item = cmbTool->SelectedItem->ToString();
				int idEnd = item->IndexOf("]");
				if (idEnd > 1) {
					int tid = Convert::ToInt32(item->Substring(1, idEnd - 1));
					DataTable^ dt = Data::ToolService::GetAvailableTools();
					for (int i = 0; i < dt->Rows->Count; i++) {
						if (Convert::ToInt32(dt->Rows[i]["id"]) == tid) {
							numDeposit->Value = Convert::ToDecimal(dt->Rows[i]["deposit"]);
							break;
						}
					}
				}
			}
			NewRentalInputChanged(sender, e);
		}

		void NewRentalInputChanged(System::Object^ sender, System::EventArgs^ e)
		{
			DateTime rDate = dtpRentDate->Value.Date;
			DateTime dDate = dtpDueDate->Value.Date;

			int days = (dDate - rDate).Days;
			if (days < 1) days = 1;

			lblSumDays->Text = String::Format("Duration: {0} Day(s)", days);

			Decimal dailyRate = Decimal(0);
			if (cmbTool->SelectedItem != nullptr) {
				String^ item = cmbTool->SelectedItem->ToString();
				int rateIdx = item->IndexOf("Rate: LKR ");
				if (rateIdx != -1) {
					int depIdx = item->IndexOf(", Dep:");
					String^ rateStr = item->Substring(rateIdx + 10, depIdx - (rateIdx + 10));
					Decimal::TryParse(rateStr, dailyRate);
				}
			}

			lblSumDailyRate->Text = String::Format("Daily Rate: LKR {0:F2}", dailyRate);
			Decimal estTotal = days * dailyRate;
			lblSumTotalRent->Text = String::Format("Estimated Rent Total: LKR {0:F2}", estTotal);
			lblSumDeposit->Text = String::Format("Required Deposit: LKR {0:F2}", numDeposit->Value);
		}

		void btnIssueRental_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (cmbCustomer->SelectedItem == nullptr || cmbTool->SelectedItem == nullptr) {
				MessageBox::Show(this, L"Please select both a customer and an available tool.", L"Missing Information", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ custItem = cmbCustomer->SelectedItem->ToString();
			int cIdEnd = custItem->IndexOf("]");
			int custId = Convert::ToInt32(custItem->Substring(1, cIdEnd - 1));

			String^ toolItem = cmbTool->SelectedItem->ToString();
			int tIdEnd = toolItem->IndexOf("]");
			int toolId = Convert::ToInt32(toolItem->Substring(1, tIdEnd - 1));

			DateTime rDate = dtpRentDate->Value.Date;
			DateTime dDate = dtpDueDate->Value.Date;
			if (dDate < rDate) {
				MessageBox::Show(this, L"Due date cannot be before rental start date.", L"Invalid Date Range", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int days = (dDate - rDate).Days;
			if (days < 1) days = 1;

			Decimal dailyRate = Decimal(0);
			int rateIdx = toolItem->IndexOf("Rate: LKR ");
			if (rateIdx != -1) {
				int depIdx = toolItem->IndexOf(", Dep:");
				String^ rateStr = toolItem->Substring(rateIdx + 10, depIdx - (rateIdx + 10));
				Decimal::TryParse(rateStr, dailyRate);
			}

			Decimal totalRent = days * dailyRate;
			Decimal deposit = numDeposit->Value;
			String^ notes = txtNotes->Text->Trim();

			String^ err = Data::RentalService::CreateRental(custId, toolId, rDate, dDate, deposit, totalRent, notes);
			if (err->Length == 0) {
				MessageBox::Show(this, L"Rental issued successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadRentals();
				LoadAvailableTools();
				tabControl1->SelectedTab = tabRentalsList;
			}
			else {
				MessageBox::Show(this, err, L"Rental Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	};
}
