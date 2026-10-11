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
			lateFeePerDay = Data::RentalService::GetLateFeePerDay();

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

		System::ComponentModel::Container^ components;

		// UI Header
		Panel^ pnlHeader;
		Label^ lblTitle;
		Label^ lblSubtitle;
		Button^ btnClose;

		TabControl^ tabControl1;
		TabPage^ tabRentalsList;
		TabPage^ tabNewRental;

		// Tab 1 controls (List & Return)
		Panel^ pnlListFilter;
		Label^ lblFilterStatus;
		ComboBox^ cmbFilterStatus;
		Label^ lblSearch;
		TextBox^ txtSearch;
		Button^ btnRefresh;

		DataGridView^ dgvRentals;

		Panel^ pnlReturnAction;
		Label^ lblReturnTitle;
		Label^ lblReturnInfo;
		Label^ lblReturnDate;
		DateTimePicker^ dtpReturnDate;
		Label^ lblLateFeeCalc;
		Label^ lblTotalCalc;
		Label^ lblRefundCalc;
		Button^ btnProcessReturn;

		// Tab 2 controls (New Rental)
		Panel^ pnlNewRental;
		Label^ lblNewTitle;
		Label^ lblCustomer;
		ComboBox^ cmbCustomer;
		Label^ lblTool;
		ComboBox^ cmbTool;
		Label^ lblRentDate;
		DateTimePicker^ dtpRentDate;
		Label^ lblDueDate;
		DateTimePicker^ dtpDueDate;
		Label^ lblDeposit;
		NumericUpDown^ numDeposit;
		Label^ lblNotes;
		TextBox^ txtNotes;

		Panel^ pnlSummaryCard;
		Label^ lblSummaryTitle;
		Label^ lblSumDays;
		Label^ lblSumDailyRate;
		Label^ lblSumTotalRent;
		Label^ lblSumDeposit;
		Button^ btnIssueRental;

		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->SuspendLayout();

			// Form properties
			this->Text = L"Rent-A-Tool - Rental Management";
			this->ClientSize = System::Drawing::Size(1180, 720);
			this->MinimumSize = System::Drawing::Size(1020, 640);
			this->StartPosition = FormStartPosition::CenterScreen;
			this->BackColor = Color::FromArgb(244, 246, 249);
			this->Font = gcnew Drawing::Font(L"Segoe UI", 10);

			// Header
			pnlHeader = gcnew Panel();
			pnlHeader->Dock = DockStyle::Top;
			pnlHeader->Height = 70;
			pnlHeader->BackColor = Color::FromArgb(47, 79, 79);

			lblTitle = gcnew Label();
			lblTitle->Text = L"RENTAL MANAGEMENT & TRANSACTIONS";
			lblTitle->Font = gcnew Drawing::Font(L"Segoe UI", 16, FontStyle::Bold);
			lblTitle->ForeColor = Color::White;
			lblTitle->Location = Point(20, 12);
			lblTitle->AutoSize = true;

			lblSubtitle = gcnew Label();
			lblSubtitle->Text = L"Issue tool rentals, calculate fees, track due dates, and process returns";
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
			btnClose->Location = Point(1000, 18);
			btnClose->Size = System::Drawing::Size(155, 35);
			btnClose->Anchor = AnchorStyles::Top | AnchorStyles::Right;
			btnClose->Cursor = Cursors::Hand;
			btnClose->Click += gcnew EventHandler(this, &rentals::btnClose_Click);

			pnlHeader->Controls->Add(lblTitle);
			pnlHeader->Controls->Add(lblSubtitle);
			pnlHeader->Controls->Add(btnClose);

			// Tabs
			tabControl1 = gcnew TabControl();
			tabControl1->Dock = DockStyle::Fill;
			tabControl1->Font = gcnew Drawing::Font(L"Segoe UI", 10.5F, FontStyle::Regular);

			tabRentalsList = gcnew TabPage();
			tabRentalsList->Text = L"  Active & All Rentals  ";
			tabRentalsList->BackColor = Color::FromArgb(244, 246, 249);

			tabNewRental = gcnew TabPage();
			tabNewRental->Text = L"  + Issue New Rental  ";
			tabNewRental->BackColor = Color::FromArgb(244, 246, 249);

			// ================= TAB 1: RENTALS LIST & RETURN =================
			pnlListFilter = gcnew Panel();
			pnlListFilter->Dock = DockStyle::Top;
			pnlListFilter->Height = 55;
			pnlListFilter->BackColor = Color::White;

			lblFilterStatus = gcnew Label();
			lblFilterStatus->Text = L"Filter Status:";
			lblFilterStatus->Location = Point(20, 16);
			lblFilterStatus->AutoSize = true;
			lblFilterStatus->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			cmbFilterStatus = gcnew ComboBox();
			cmbFilterStatus->DropDownStyle = ComboBoxStyle::DropDownList;
			cmbFilterStatus->Items->AddRange(gcnew cli::array<Object^>{ L"All", L"Active", L"Overdue", L"Returned" });
			cmbFilterStatus->SelectedIndex = 0;
			cmbFilterStatus->Location = Point(110, 13);
			cmbFilterStatus->Size = System::Drawing::Size(130, 25);
			cmbFilterStatus->SelectedIndexChanged += gcnew EventHandler(this, &rentals::FilterChanged);

			lblSearch = gcnew Label();
			lblSearch->Text = L"Search:";
			lblSearch->Location = Point(270, 16);
			lblSearch->AutoSize = true;
			lblSearch->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			txtSearch = gcnew TextBox();
			txtSearch->Location = Point(330, 13);
			txtSearch->Size = System::Drawing::Size(240, 25);
			txtSearch->TextChanged += gcnew EventHandler(this, &rentals::FilterChanged);

			btnRefresh = gcnew Button();
			btnRefresh->Text = L"Refresh";
			btnRefresh->Location = Point(585, 12);
			btnRefresh->Size = System::Drawing::Size(90, 28);
			btnRefresh->BackColor = Color::FromArgb(52, 152, 219);
			btnRefresh->ForeColor = Color::White;
			btnRefresh->FlatStyle = FlatStyle::Flat;
			btnRefresh->FlatAppearance->BorderSize = 0;
			btnRefresh->Cursor = Cursors::Hand;
			btnRefresh->Click += gcnew EventHandler(this, &rentals::btnRefresh_Click);

			pnlListFilter->Controls->Add(lblFilterStatus);
			pnlListFilter->Controls->Add(cmbFilterStatus);
			pnlListFilter->Controls->Add(lblSearch);
			pnlListFilter->Controls->Add(txtSearch);
			pnlListFilter->Controls->Add(btnRefresh);

			// Return Action Panel at bottom of Tab 1
			pnlReturnAction = gcnew Panel();
			pnlReturnAction->Dock = DockStyle::Bottom;
			pnlReturnAction->Height = 120;
			pnlReturnAction->BackColor = Color::White;
			pnlReturnAction->Padding = System::Windows::Forms::Padding(20, 10, 20, 10);

			lblReturnTitle = gcnew Label();
			lblReturnTitle->Text = L"Process Return for Selected Rental";
			lblReturnTitle->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			lblReturnTitle->ForeColor = Color::FromArgb(47, 79, 79);
			lblReturnTitle->Location = Point(20, 8);
			lblReturnTitle->AutoSize = true;

			lblReturnInfo = gcnew Label();
			lblReturnInfo->Text = L"Select an Active or Overdue rental from the table above to process return.";
			lblReturnInfo->ForeColor = Color::FromArgb(100, 100, 100);
			lblReturnInfo->Location = Point(20, 34);
			lblReturnInfo->AutoSize = true;

			lblReturnDate = gcnew Label();
			lblReturnDate->Text = L"Return Date:";
			lblReturnDate->Location = Point(20, 65);
			lblReturnDate->AutoSize = true;

			dtpReturnDate = gcnew DateTimePicker();
			dtpReturnDate->Format = DateTimePickerFormat::Short;
			dtpReturnDate->Location = Point(110, 62);
			dtpReturnDate->Size = System::Drawing::Size(120, 25);
			dtpReturnDate->ValueChanged += gcnew EventHandler(this, &rentals::dtpReturnDate_ValueChanged);

			lblLateFeeCalc = gcnew Label();
			lblLateFeeCalc->Text = L"Late Fee: LKR 0.00";
			lblLateFeeCalc->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			lblLateFeeCalc->ForeColor = Color::FromArgb(192, 57, 43);
			lblLateFeeCalc->Location = Point(260, 65);
			lblLateFeeCalc->AutoSize = true;

			lblTotalCalc = gcnew Label();
			lblTotalCalc->Text = L"Final Total: LKR 0.00";
			lblTotalCalc->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			lblTotalCalc->Location = Point(440, 65);
			lblTotalCalc->AutoSize = true;

			lblRefundCalc = gcnew Label();
			lblRefundCalc->Text = L"Refund Due: LKR 0.00";
			lblRefundCalc->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			lblRefundCalc->ForeColor = Color::FromArgb(39, 174, 96);
			lblRefundCalc->Location = Point(630, 65);
			lblRefundCalc->AutoSize = true;

			btnProcessReturn = gcnew Button();
			btnProcessReturn->Text = L"Complete Return";
			btnProcessReturn->Font = gcnew Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
			btnProcessReturn->BackColor = Color::FromArgb(39, 174, 96);
			btnProcessReturn->ForeColor = Color::White;
			btnProcessReturn->FlatStyle = FlatStyle::Flat;
			btnProcessReturn->FlatAppearance->BorderSize = 0;
			btnProcessReturn->Location = Point(820, 58);
			btnProcessReturn->Size = System::Drawing::Size(170, 35);
			btnProcessReturn->Cursor = Cursors::Hand;
			btnProcessReturn->Enabled = false;
			btnProcessReturn->Click += gcnew EventHandler(this, &rentals::btnProcessReturn_Click);

			pnlReturnAction->Controls->Add(lblReturnTitle);
			pnlReturnAction->Controls->Add(lblReturnInfo);
			pnlReturnAction->Controls->Add(lblReturnDate);
			pnlReturnAction->Controls->Add(dtpReturnDate);
			pnlReturnAction->Controls->Add(lblLateFeeCalc);
			pnlReturnAction->Controls->Add(lblTotalCalc);
			pnlReturnAction->Controls->Add(lblRefundCalc);
			pnlReturnAction->Controls->Add(btnProcessReturn);

			// DataGridView Rentals
			dgvRentals = gcnew DataGridView();
			dgvRentals->Dock = DockStyle::Fill;
			dgvRentals->BackgroundColor = Color::FromArgb(244, 246, 249);
			dgvRentals->BorderStyle = BorderStyle::None;
			dgvRentals->AllowUserToAddRows = false;
			dgvRentals->AllowUserToDeleteRows = false;
			dgvRentals->ReadOnly = true;
			dgvRentals->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dgvRentals->MultiSelect = false;
			dgvRentals->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dgvRentals->RowHeadersVisible = false;
			dgvRentals->CellClick += gcnew DataGridViewCellEventHandler(this, &rentals::dgvRentals_CellClick);
			dgvRentals->CellFormatting += gcnew DataGridViewCellFormattingEventHandler(this, &rentals::dgvRentals_CellFormatting);
			dgvRentals->DataError += gcnew DataGridViewDataErrorEventHandler(this, &rentals::dgvRentals_DataError);

			tabRentalsList->Controls->Add(dgvRentals);
			tabRentalsList->Controls->Add(pnlReturnAction);
			tabRentalsList->Controls->Add(pnlListFilter);

			// ================= TAB 2: NEW RENTAL =================
			pnlNewRental = gcnew Panel();
			pnlNewRental->Dock = DockStyle::Fill;
			pnlNewRental->Padding = System::Windows::Forms::Padding(30);
			pnlNewRental->BackColor = Color::White;

			lblNewTitle = gcnew Label();
			lblNewTitle->Text = L"Issue a New Rental Agreement";
			lblNewTitle->Font = gcnew Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
			lblNewTitle->ForeColor = Color::FromArgb(47, 79, 79);
			lblNewTitle->Location = Point(30, 20);
			lblNewTitle->AutoSize = true;

			int y = 65;
			lblCustomer = gcnew Label();
			lblCustomer->Text = L"Select Customer:";
			lblCustomer->Location = Point(30, y);
			lblCustomer->AutoSize = true;
			lblCustomer->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			cmbCustomer = gcnew ComboBox();
			cmbCustomer->DropDownStyle = ComboBoxStyle::DropDownList;
			cmbCustomer->Location = Point(30, y + 22);
			cmbCustomer->Size = System::Drawing::Size(460, 26);
			cmbCustomer->SelectedIndexChanged += gcnew EventHandler(this, &rentals::NewRentalInputChanged);

			y += 65;
			lblTool = gcnew Label();
			lblTool->Text = L"Select Available Tool:";
			lblTool->Location = Point(30, y);
			lblTool->AutoSize = true;
			lblTool->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			cmbTool = gcnew ComboBox();
			cmbTool->DropDownStyle = ComboBoxStyle::DropDownList;
			cmbTool->Location = Point(30, y + 22);
			cmbTool->Size = System::Drawing::Size(460, 26);
			cmbTool->SelectedIndexChanged += gcnew EventHandler(this, &rentals::cmbTool_SelectedIndexChanged);

			y += 65;
			lblRentDate = gcnew Label();
			lblRentDate->Text = L"Rent Date:";
			lblRentDate->Location = Point(30, y);
			lblRentDate->AutoSize = true;
			lblRentDate->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			dtpRentDate = gcnew DateTimePicker();
			dtpRentDate->Format = DateTimePickerFormat::Short;
			dtpRentDate->Location = Point(30, y + 22);
			dtpRentDate->Size = System::Drawing::Size(215, 25);
			dtpRentDate->Value = DateTime::Today;
			dtpRentDate->ValueChanged += gcnew EventHandler(this, &rentals::NewRentalInputChanged);

			lblDueDate = gcnew Label();
			lblDueDate->Text = L"Due Date:";
			lblDueDate->Location = Point(275, y);
			lblDueDate->AutoSize = true;
			lblDueDate->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			dtpDueDate = gcnew DateTimePicker();
			dtpDueDate->Format = DateTimePickerFormat::Short;
			dtpDueDate->Location = Point(275, y + 22);
			dtpDueDate->Size = System::Drawing::Size(215, 25);
			dtpDueDate->Value = DateTime::Today.AddDays(3);
			dtpDueDate->ValueChanged += gcnew EventHandler(this, &rentals::NewRentalInputChanged);

			y += 65;
			lblDeposit = gcnew Label();
			lblDeposit->Text = L"Deposit Paid (LKR):";
			lblDeposit->Location = Point(30, y);
			lblDeposit->AutoSize = true;
			lblDeposit->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			numDeposit = gcnew NumericUpDown();
			numDeposit->Location = Point(30, y + 22);
			numDeposit->Size = System::Drawing::Size(215, 25);
			numDeposit->Maximum = 10000000;
			numDeposit->DecimalPlaces = 2;
			numDeposit->ValueChanged += gcnew EventHandler(this, &rentals::NewRentalInputChanged);

			lblNotes = gcnew Label();
			lblNotes->Text = L"Rental Notes / Condition remarks:";
			lblNotes->Location = Point(30, y + 60);
			lblNotes->AutoSize = true;
			lblNotes->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			txtNotes = gcnew TextBox();
			txtNotes->Multiline = true;
			txtNotes->Location = Point(30, y + 82);
			txtNotes->Size = System::Drawing::Size(460, 60);

			// Summary Card on right
			pnlSummaryCard = gcnew Panel();
			pnlSummaryCard->Location = Point(550, 65);
			pnlSummaryCard->Size = System::Drawing::Size(450, 320);
			pnlSummaryCard->BackColor = Color::FromArgb(248, 249, 250);
			pnlSummaryCard->BorderStyle = BorderStyle::FixedSingle;
			pnlSummaryCard->Padding = System::Windows::Forms::Padding(25);

			lblSummaryTitle = gcnew Label();
			lblSummaryTitle->Text = L"Rental Cost Estimation";
			lblSummaryTitle->Font = gcnew Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblSummaryTitle->ForeColor = Color::FromArgb(47, 79, 79);
			lblSummaryTitle->Location = Point(20, 20);
			lblSummaryTitle->AutoSize = true;

			lblSumDays = gcnew Label();
			lblSumDays->Text = L"Duration: 3 Day(s)";
			lblSumDays->Location = Point(20, 65);
			lblSumDays->AutoSize = true;

			lblSumDailyRate = gcnew Label();
			lblSumDailyRate->Text = L"Daily Rate: LKR 0.00";
			lblSumDailyRate->Location = Point(20, 105);
			lblSumDailyRate->AutoSize = true;

			lblSumTotalRent = gcnew Label();
			lblSumTotalRent->Text = L"Estimated Rent Total: LKR 0.00";
			lblSumTotalRent->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			lblSumTotalRent->ForeColor = Color::FromArgb(41, 128, 185);
			lblSumTotalRent->Location = Point(20, 150);
			lblSumTotalRent->AutoSize = true;

			lblSumDeposit = gcnew Label();
			lblSumDeposit->Text = L"Required Deposit: LKR 0.00";
			lblSumDeposit->Font = gcnew Drawing::Font(L"Segoe UI", 10.5F, FontStyle::Bold);
			lblSumDeposit->ForeColor = Color::FromArgb(39, 174, 96);
			lblSumDeposit->Location = Point(20, 195);
			lblSumDeposit->AutoSize = true;

			btnIssueRental = gcnew Button();
			btnIssueRental->Text = L"Confirm & Issue Rental";
			btnIssueRental->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
			btnIssueRental->BackColor = Color::FromArgb(39, 174, 96);
			btnIssueRental->ForeColor = Color::White;
			btnIssueRental->FlatStyle = FlatStyle::Flat;
			btnIssueRental->FlatAppearance->BorderSize = 0;
			btnIssueRental->Location = Point(20, 245);
			btnIssueRental->Size = System::Drawing::Size(405, 45);
			btnIssueRental->Cursor = Cursors::Hand;
			btnIssueRental->Click += gcnew EventHandler(this, &rentals::btnIssueRental_Click);

			pnlSummaryCard->Controls->Add(lblSummaryTitle);
			pnlSummaryCard->Controls->Add(lblSumDays);
			pnlSummaryCard->Controls->Add(lblSumDailyRate);
			pnlSummaryCard->Controls->Add(lblSumTotalRent);
			pnlSummaryCard->Controls->Add(lblSumDeposit);
			pnlSummaryCard->Controls->Add(btnIssueRental);

			pnlNewRental->Controls->Add(lblNewTitle);
			pnlNewRental->Controls->Add(lblCustomer);
			pnlNewRental->Controls->Add(cmbCustomer);
			pnlNewRental->Controls->Add(lblTool);
			pnlNewRental->Controls->Add(cmbTool);
			pnlNewRental->Controls->Add(lblRentDate);
			pnlNewRental->Controls->Add(dtpRentDate);
			pnlNewRental->Controls->Add(lblDueDate);
			pnlNewRental->Controls->Add(dtpDueDate);
			pnlNewRental->Controls->Add(lblDeposit);
			pnlNewRental->Controls->Add(numDeposit);
			pnlNewRental->Controls->Add(lblNotes);
			pnlNewRental->Controls->Add(txtNotes);
			pnlNewRental->Controls->Add(pnlSummaryCard);

			tabNewRental->Controls->Add(pnlNewRental);

			tabControl1->TabPages->Add(tabRentalsList);
			tabControl1->TabPages->Add(tabNewRental);

			this->Controls->Add(tabControl1);
			this->Controls->Add(pnlHeader);

			this->Load += gcnew EventHandler(this, &rentals::rentals_Load);
			this->ResumeLayout(false);
		}

		void dgvRentals_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e)
		{
			e->ThrowException = false;
		}

		void rentals_Load(System::Object^ sender, System::EventArgs^ e)
		{
			LoadCustomersForRental();
			LoadAvailableTools();
			LoadRentals();
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
