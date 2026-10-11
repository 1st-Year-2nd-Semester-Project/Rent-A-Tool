#pragma once
#include "Data/DashboardService.h"
#include "Data/authresult.h"
#include "inventory.h"
#include "rentals.h"
#include "customers.h"
#include "settings.h"

namespace RentATool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	public ref class dashboard : public System::Windows::Forms::Form
	{
	public:
		dashboard(void)
		{
			InitializeComponent();
		}

	protected:
		~dashboard()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;

		// Menu strip
		MenuStrip^ menuStrip1;
		ToolStripMenuItem^ menuFile;
		ToolStripMenuItem^ menuFileRefresh;
		ToolStripMenuItem^ menuFileLogout;
		ToolStripMenuItem^ menuFileExit;

		ToolStripMenuItem^ menuInventory;
		ToolStripMenuItem^ menuInventoryManage;

		ToolStripMenuItem^ menuRentals;
		ToolStripMenuItem^ menuRentalsAll;

		ToolStripMenuItem^ menuCustomers;
		ToolStripMenuItem^ menuCustomersManage;

		ToolStripMenuItem^ menuSettings;
		ToolStripMenuItem^ menuSettingsManage;

		ToolStripMenuItem^ menuHelp;
		ToolStripMenuItem^ menuHelpAbout;

		// Top Header
		Panel^ pnlHeader;
		Label^ lblAppTitle;
		Label^ lblAppSubtitle;
		Label^ lblUserBadge;
		Label^ lblDateBadge;
		Button^ btnHeaderRefresh;
		Button^ btnHeaderLogout;

		// Quick Actions Bar
		Panel^ pnlActions;
		Button^ btnActNewRental;
		Button^ btnActReturn;
		Button^ btnActTools;
		Button^ btnActCustomers;
		Button^ btnActSettings;

		// KPI Cards Panel
		Panel^ pnlKpiContainer;
		Panel^ cardActiveRentals;
		Label^ lblCard1Title;
		Label^ lblCard1Value;
		Label^ lblCard1Sub;

		Panel^ cardOverdue;
		Label^ lblCard2Title;
		Label^ lblCard2Value;
		Label^ lblCard2Sub;

		Panel^ cardTools;
		Label^ lblCard3Title;
		Label^ lblCard3Value;
		Label^ lblCard3Sub;

		Panel^ cardRevenue;
		Label^ lblCard4Title;
		Label^ lblCard4Value;
		Label^ lblCard4Sub;

		// Split Main Container
		SplitContainer^ splitMain;

		// Chart Section
		Panel^ pnlChartContainer;
		Label^ lblChartHeader;
		Chart^ chartInventory;

		// Recent Activity Section
		Panel^ pnlRecentContainer;
		Label^ lblRecentHeader;
		DataGridView^ dgvRecentRentals;

		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->SuspendLayout();

			// Form properties
			this->Text = L"Rent-A-Tool - Master Dashboard";
			this->ClientSize = System::Drawing::Size(1260, 780);
			this->MinimumSize = System::Drawing::Size(1100, 700);
			this->StartPosition = FormStartPosition::CenterScreen;
			this->BackColor = Color::FromArgb(240, 243, 246);
			this->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F);

			// ================= MENU STRIP =================
			menuStrip1 = gcnew MenuStrip();
			menuStrip1->BackColor = Color::FromArgb(38, 64, 64);
			menuStrip1->ForeColor = Color::White;
			menuStrip1->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F);
			menuStrip1->Padding = System::Windows::Forms::Padding(6, 4, 6, 4);

			// File menu
			menuFile = gcnew ToolStripMenuItem(L"&File");
			menuFile->ForeColor = Color::White;
			menuFileRefresh = gcnew ToolStripMenuItem(L"&Refresh Dashboard", nullptr, gcnew EventHandler(this, &dashboard::menuRefresh_Click));
			menuFileLogout = gcnew ToolStripMenuItem(L"&Logout", nullptr, gcnew EventHandler(this, &dashboard::menuLogout_Click));
			menuFileExit = gcnew ToolStripMenuItem(L"E&xit", nullptr, gcnew EventHandler(this, &dashboard::menuExit_Click));
			menuFile->DropDownItems->Add(menuFileRefresh);
			menuFile->DropDownItems->Add(gcnew ToolStripSeparator());
			menuFile->DropDownItems->Add(menuFileLogout);
			menuFile->DropDownItems->Add(menuFileExit);

			// Inventory menu
			menuInventory = gcnew ToolStripMenuItem(L"&Inventory");
			menuInventory->ForeColor = Color::White;
			menuInventoryManage = gcnew ToolStripMenuItem(L"&Tool Inventory Management", nullptr, gcnew EventHandler(this, &dashboard::openInventory_Click));
			menuInventory->DropDownItems->Add(menuInventoryManage);

			// Rentals menu
			menuRentals = gcnew ToolStripMenuItem(L"&Rentals");
			menuRentals->ForeColor = Color::White;
			menuRentalsAll = gcnew ToolStripMenuItem(L"&Rental Transactions & Checkout", nullptr, gcnew EventHandler(this, &dashboard::openRentals_Click));
			menuRentals->DropDownItems->Add(menuRentalsAll);

			// Customers menu
			menuCustomers = gcnew ToolStripMenuItem(L"&Customers");
			menuCustomers->ForeColor = Color::White;
			menuCustomersManage = gcnew ToolStripMenuItem(L"&Customer Directory & Profiles", nullptr, gcnew EventHandler(this, &dashboard::openCustomers_Click));
			menuCustomers->DropDownItems->Add(menuCustomersManage);

			// Settings menu
			menuSettings = gcnew ToolStripMenuItem(L"&Settings");
			menuSettings->ForeColor = Color::White;
			menuSettingsManage = gcnew ToolStripMenuItem(L"&System Rules & User Accounts", nullptr, gcnew EventHandler(this, &dashboard::openSettings_Click));
			menuSettings->DropDownItems->Add(menuSettingsManage);

			// Help menu
			menuHelp = gcnew ToolStripMenuItem(L"&Help");
			menuHelp->ForeColor = Color::White;
			menuHelpAbout = gcnew ToolStripMenuItem(L"&About Rent-A-Tool", nullptr, gcnew EventHandler(this, &dashboard::menuAbout_Click));
			menuHelp->DropDownItems->Add(menuHelpAbout);

			menuStrip1->Items->Add(menuFile);
			menuStrip1->Items->Add(menuInventory);
			menuStrip1->Items->Add(menuRentals);
			menuStrip1->Items->Add(menuCustomers);
			menuStrip1->Items->Add(menuSettings);
			menuStrip1->Items->Add(menuHelp);

			// ================= TOP HEADER PANEL =================
			pnlHeader = gcnew Panel();
			pnlHeader->Dock = DockStyle::Top;
			pnlHeader->Height = 82;
			pnlHeader->BackColor = Color::FromArgb(47, 79, 79); // DarkSlateGray
			pnlHeader->Padding = System::Windows::Forms::Padding(24, 12, 24, 12);

			lblAppTitle = gcnew Label();
			lblAppTitle->Text = L"RENT-A-TOOL MANAGEMENT CONSOLE";
			lblAppTitle->Font = gcnew Drawing::Font(L"Segoe UI", 16, FontStyle::Bold);
			lblAppTitle->ForeColor = Color::White;
			lblAppTitle->Location = Point(24, 14);
			lblAppTitle->AutoSize = true;

			lblAppSubtitle = gcnew Label();
			lblAppSubtitle->Text = L"Real-time overview of active rentals, inventory availability, returns, and revenue";
			lblAppSubtitle->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F);
			lblAppSubtitle->ForeColor = Color::FromArgb(200, 225, 225);
			lblAppSubtitle->Location = Point(26, 46);
			lblAppSubtitle->AutoSize = true;

			btnHeaderLogout = gcnew Button();
			btnHeaderLogout->Text = L"Log Out";
			btnHeaderLogout->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			btnHeaderLogout->ForeColor = Color::White;
			btnHeaderLogout->BackColor = Color::FromArgb(192, 57, 43);
			btnHeaderLogout->FlatStyle = FlatStyle::Flat;
			btnHeaderLogout->FlatAppearance->BorderSize = 0;
			btnHeaderLogout->Size = System::Drawing::Size(85, 32);
			btnHeaderLogout->Location = Point(1145, 24);
			btnHeaderLogout->Anchor = AnchorStyles::Top | AnchorStyles::Right;
			btnHeaderLogout->Cursor = Cursors::Hand;
			btnHeaderLogout->Click += gcnew EventHandler(this, &dashboard::menuLogout_Click);

			btnHeaderRefresh = gcnew Button();
			btnHeaderRefresh->Text = L"Refresh Data";
			btnHeaderRefresh->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			btnHeaderRefresh->ForeColor = Color::White;
			btnHeaderRefresh->BackColor = Color::FromArgb(52, 152, 219);
			btnHeaderRefresh->FlatStyle = FlatStyle::Flat;
			btnHeaderRefresh->FlatAppearance->BorderSize = 0;
			btnHeaderRefresh->Size = System::Drawing::Size(105, 32);
			btnHeaderRefresh->Location = Point(1030, 24);
			btnHeaderRefresh->Anchor = AnchorStyles::Top | AnchorStyles::Right;
			btnHeaderRefresh->Cursor = Cursors::Hand;
			btnHeaderRefresh->Click += gcnew EventHandler(this, &dashboard::menuRefresh_Click);

			lblUserBadge = gcnew Label();
			String^ userName = CurrentUser::FullName != nullptr ? CurrentUser::FullName : "Chukka Fernando";
			String^ role = CurrentUser::Role != nullptr ? CurrentUser::Role : "Admin";
			lblUserBadge->Text = String::Format("User: {0} ({1})", userName, role);
			lblUserBadge->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			lblUserBadge->ForeColor = Color::FromArgb(254, 211, 48);
			lblUserBadge->Location = Point(730, 18);
			lblUserBadge->Size = System::Drawing::Size(285, 20);
			lblUserBadge->TextAlign = ContentAlignment::MiddleRight;
			lblUserBadge->Anchor = AnchorStyles::Top | AnchorStyles::Right;

			lblDateBadge = gcnew Label();
			lblDateBadge->Text = DateTime::Now.ToString("dddd, MMMM dd, yyyy");
			lblDateBadge->Font = gcnew Drawing::Font(L"Segoe UI", 9);
			lblDateBadge->ForeColor = Color::FromArgb(210, 230, 230);
			lblDateBadge->Location = Point(730, 42);
			lblDateBadge->Size = System::Drawing::Size(285, 20);
			lblDateBadge->TextAlign = ContentAlignment::MiddleRight;
			lblDateBadge->Anchor = AnchorStyles::Top | AnchorStyles::Right;

			pnlHeader->Controls->Add(lblAppTitle);
			pnlHeader->Controls->Add(lblAppSubtitle);
			pnlHeader->Controls->Add(lblUserBadge);
			pnlHeader->Controls->Add(lblDateBadge);
			pnlHeader->Controls->Add(btnHeaderRefresh);
			pnlHeader->Controls->Add(btnHeaderLogout);

			// ================= QUICK ACTIONS BAR =================
			pnlActions = gcnew Panel();
			pnlActions->Dock = DockStyle::Top;
			pnlActions->Height = 56;
			pnlActions->BackColor = Color::White;
			pnlActions->Padding = System::Windows::Forms::Padding(24, 10, 24, 10);

			btnActNewRental = gcnew Button();
			btnActNewRental->Text = L"+ Issue New Rental";
			btnActNewRental->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnActNewRental->BackColor = Color::FromArgb(39, 174, 96); // Green
			btnActNewRental->ForeColor = Color::White;
			btnActNewRental->FlatStyle = FlatStyle::Flat;
			btnActNewRental->FlatAppearance->BorderSize = 0;
			btnActNewRental->Location = Point(24, 10);
			btnActNewRental->Size = System::Drawing::Size(170, 36);
			btnActNewRental->Cursor = Cursors::Hand;
			btnActNewRental->Click += gcnew EventHandler(this, &dashboard::openRentals_Click);

			btnActReturn = gcnew Button();
			btnActReturn->Text = L"Process Return";
			btnActReturn->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnActReturn->BackColor = Color::FromArgb(230, 126, 34); // Orange
			btnActReturn->ForeColor = Color::White;
			btnActReturn->FlatStyle = FlatStyle::Flat;
			btnActReturn->FlatAppearance->BorderSize = 0;
			btnActReturn->Location = Point(204, 10);
			btnActReturn->Size = System::Drawing::Size(150, 36);
			btnActReturn->Cursor = Cursors::Hand;
			btnActReturn->Click += gcnew EventHandler(this, &dashboard::openRentals_Click);

			btnActTools = gcnew Button();
			btnActTools->Text = L"Tool Inventory";
			btnActTools->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnActTools->BackColor = Color::FromArgb(47, 79, 79); // Dark teal
			btnActTools->ForeColor = Color::White;
			btnActTools->FlatStyle = FlatStyle::Flat;
			btnActTools->FlatAppearance->BorderSize = 0;
			btnActTools->Location = Point(364, 10);
			btnActTools->Size = System::Drawing::Size(150, 36);
			btnActTools->Cursor = Cursors::Hand;
			btnActTools->Click += gcnew EventHandler(this, &dashboard::openInventory_Click);

			btnActCustomers = gcnew Button();
			btnActCustomers->Text = L"Customer Directory";
			btnActCustomers->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnActCustomers->BackColor = Color::FromArgb(52, 152, 219); // Blue
			btnActCustomers->ForeColor = Color::White;
			btnActCustomers->FlatStyle = FlatStyle::Flat;
			btnActCustomers->FlatAppearance->BorderSize = 0;
			btnActCustomers->Location = Point(524, 10);
			btnActCustomers->Size = System::Drawing::Size(160, 36);
			btnActCustomers->Cursor = Cursors::Hand;
			btnActCustomers->Click += gcnew EventHandler(this, &dashboard::openCustomers_Click);

			btnActSettings = gcnew Button();
			btnActSettings->Text = L"Settings & Users";
			btnActSettings->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnActSettings->BackColor = Color::FromArgb(108, 122, 137); // Slate
			btnActSettings->ForeColor = Color::White;
			btnActSettings->FlatStyle = FlatStyle::Flat;
			btnActSettings->FlatAppearance->BorderSize = 0;
			btnActSettings->Location = Point(694, 10);
			btnActSettings->Size = System::Drawing::Size(150, 36);
			btnActSettings->Cursor = Cursors::Hand;
			btnActSettings->Click += gcnew EventHandler(this, &dashboard::openSettings_Click);

			pnlActions->Controls->Add(btnActNewRental);
			pnlActions->Controls->Add(btnActReturn);
			pnlActions->Controls->Add(btnActTools);
			pnlActions->Controls->Add(btnActCustomers);
			pnlActions->Controls->Add(btnActSettings);

			// ================= KPI CARDS PANEL =================
			pnlKpiContainer = gcnew Panel();
			pnlKpiContainer->Dock = DockStyle::Top;
			pnlKpiContainer->Height = 120;
			pnlKpiContainer->BackColor = Color::FromArgb(240, 243, 246);
			pnlKpiContainer->Padding = System::Windows::Forms::Padding(24, 14, 24, 14);

			// Card 1: Active Rentals
			cardActiveRentals = gcnew Panel();
			cardActiveRentals->BackColor = Color::White;
			cardActiveRentals->Size = System::Drawing::Size(280, 92);
			cardActiveRentals->Location = Point(24, 14);

			lblCard1Title = gcnew Label();
			lblCard1Title->Text = L"ACTIVE RENTALS";
			lblCard1Title->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			lblCard1Title->ForeColor = Color::FromArgb(41, 128, 185);
			lblCard1Title->Location = Point(16, 12);
			lblCard1Title->AutoSize = true;

			lblCard1Value = gcnew Label();
			lblCard1Value->Text = L"0";
			lblCard1Value->Font = gcnew Drawing::Font(L"Segoe UI", 20, FontStyle::Bold);
			lblCard1Value->ForeColor = Color::FromArgb(44, 62, 80);
			lblCard1Value->Location = Point(14, 30);
			lblCard1Value->AutoSize = true;

			lblCard1Sub = gcnew Label();
			lblCard1Sub->Text = L"Rentals today: 0";
			lblCard1Sub->Font = gcnew Drawing::Font(L"Segoe UI", 8.5F);
			lblCard1Sub->ForeColor = Color::FromArgb(127, 140, 141);
			lblCard1Sub->Location = Point(16, 68);
			lblCard1Sub->AutoSize = true;

			cardActiveRentals->Controls->Add(lblCard1Title);
			cardActiveRentals->Controls->Add(lblCard1Value);
			cardActiveRentals->Controls->Add(lblCard1Sub);

			// Card 2: Overdue
			cardOverdue = gcnew Panel();
			cardOverdue->BackColor = Color::White;
			cardOverdue->Size = System::Drawing::Size(280, 92);
			cardOverdue->Location = Point(324, 14);

			lblCard2Title = gcnew Label();
			lblCard2Title->Text = L"OVERDUE RETURNS";
			lblCard2Title->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			lblCard2Title->ForeColor = Color::FromArgb(192, 57, 43);
			lblCard2Title->Location = Point(16, 12);
			lblCard2Title->AutoSize = true;

			lblCard2Value = gcnew Label();
			lblCard2Value->Text = L"0";
			lblCard2Value->Font = gcnew Drawing::Font(L"Segoe UI", 20, FontStyle::Bold);
			lblCard2Value->ForeColor = Color::FromArgb(192, 57, 43);
			lblCard2Value->Location = Point(14, 30);
			lblCard2Value->AutoSize = true;

			lblCard2Sub = gcnew Label();
			lblCard2Sub->Text = L"Requires follow-up";
			lblCard2Sub->Font = gcnew Drawing::Font(L"Segoe UI", 8.5F);
			lblCard2Sub->ForeColor = Color::FromArgb(127, 140, 141);
			lblCard2Sub->Location = Point(16, 68);
			lblCard2Sub->AutoSize = true;

			cardOverdue->Controls->Add(lblCard2Title);
			cardOverdue->Controls->Add(lblCard2Value);
			cardOverdue->Controls->Add(lblCard2Sub);

			// Card 3: Available Tools
			cardTools = gcnew Panel();
			cardTools->BackColor = Color::White;
			cardTools->Size = System::Drawing::Size(280, 92);
			cardTools->Location = Point(624, 14);

			lblCard3Title = gcnew Label();
			lblCard3Title->Text = L"TOOL AVAILABILITY";
			lblCard3Title->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			lblCard3Title->ForeColor = Color::FromArgb(39, 174, 96);
			lblCard3Title->Location = Point(16, 12);
			lblCard3Title->AutoSize = true;

			lblCard3Value = gcnew Label();
			lblCard3Value->Text = L"0";
			lblCard3Value->Font = gcnew Drawing::Font(L"Segoe UI", 20, FontStyle::Bold);
			lblCard3Value->ForeColor = Color::FromArgb(44, 62, 80);
			lblCard3Value->Location = Point(14, 30);
			lblCard3Value->AutoSize = true;

			lblCard3Sub = gcnew Label();
			lblCard3Sub->Text = L"Rented: 0 | Maintenance: 0";
			lblCard3Sub->Font = gcnew Drawing::Font(L"Segoe UI", 8.5F);
			lblCard3Sub->ForeColor = Color::FromArgb(127, 140, 141);
			lblCard3Sub->Location = Point(16, 68);
			lblCard3Sub->AutoSize = true;

			cardTools->Controls->Add(lblCard3Title);
			cardTools->Controls->Add(lblCard3Value);
			cardTools->Controls->Add(lblCard3Sub);

			// Card 4: Total Revenue & Deposits
			cardRevenue = gcnew Panel();
			cardRevenue->BackColor = Color::White;
			cardRevenue->Size = System::Drawing::Size(305, 92);
			cardRevenue->Location = Point(924, 14);

			lblCard4Title = gcnew Label();
			lblCard4Title->Text = L"TOTAL REVENUE";
			lblCard4Title->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			lblCard4Title->ForeColor = Color::FromArgb(142, 68, 173);
			lblCard4Title->Location = Point(16, 12);
			lblCard4Title->AutoSize = true;

			lblCard4Value = gcnew Label();
			lblCard4Value->Text = L"LKR 0.00";
			lblCard4Value->Font = gcnew Drawing::Font(L"Segoe UI", 18, FontStyle::Bold);
			lblCard4Value->ForeColor = Color::FromArgb(44, 62, 80);
			lblCard4Value->Location = Point(14, 32);
			lblCard4Value->AutoSize = true;

			lblCard4Sub = gcnew Label();
			lblCard4Sub->Text = L"Deposits held: LKR 0.00";
			lblCard4Sub->Font = gcnew Drawing::Font(L"Segoe UI", 8.5F);
			lblCard4Sub->ForeColor = Color::FromArgb(127, 140, 141);
			lblCard4Sub->Location = Point(16, 68);
			lblCard4Sub->AutoSize = true;

			cardRevenue->Controls->Add(lblCard4Title);
			cardRevenue->Controls->Add(lblCard4Value);
			cardRevenue->Controls->Add(lblCard4Sub);

			pnlKpiContainer->Controls->Add(cardActiveRentals);
			pnlKpiContainer->Controls->Add(cardOverdue);
			pnlKpiContainer->Controls->Add(cardTools);
			pnlKpiContainer->Controls->Add(cardRevenue);

			// ================= SPLIT MAIN SECTION =================
			splitMain = gcnew SplitContainer();
			splitMain->Dock = DockStyle::Fill;
			splitMain->SplitterDistance = 490;
			splitMain->Padding = System::Windows::Forms::Padding(24, 0, 24, 16);
			splitMain->BackColor = Color::FromArgb(240, 243, 246);

			// Left Panel: Tool Distribution Chart
			pnlChartContainer = gcnew Panel();
			pnlChartContainer->Dock = DockStyle::Fill;
			pnlChartContainer->BackColor = Color::White;
			pnlChartContainer->Padding = System::Windows::Forms::Padding(16);

			lblChartHeader = gcnew Label();
			lblChartHeader->Text = L"Tool Inventory by Category";
			lblChartHeader->Font = gcnew Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblChartHeader->ForeColor = Color::FromArgb(47, 79, 79);
			lblChartHeader->Dock = DockStyle::Top;
			lblChartHeader->Height = 32;

			chartInventory = gcnew Chart();
			chartInventory->Dock = DockStyle::Fill;
			ChartArea^ chartArea1 = gcnew ChartArea(L"MainArea");
			chartArea1->BackColor = Color::White;
			chartArea1->AxisX->MajorGrid->LineColor = Color::FromArgb(240, 240, 240);
			chartArea1->AxisY->MajorGrid->LineColor = Color::FromArgb(240, 240, 240);
			chartInventory->ChartAreas->Add(chartArea1);

			Legend^ legend1 = gcnew Legend(L"MainLegend");
			legend1->Docking = Docking::Bottom;
			chartInventory->Legends->Add(legend1);

			Series^ series1 = gcnew Series(L"Categories");
			series1->ChartType = SeriesChartType::Pie;
			series1->IsValueShownAsLabel = true;
			chartInventory->Series->Add(series1);

			pnlChartContainer->Controls->Add(chartInventory);
			pnlChartContainer->Controls->Add(lblChartHeader);
			splitMain->Panel1->Controls->Add(pnlChartContainer);

			// Right Panel: Recent Rentals Table
			pnlRecentContainer = gcnew Panel();
			pnlRecentContainer->Dock = DockStyle::Fill;
			pnlRecentContainer->BackColor = Color::White;
			pnlRecentContainer->Padding = System::Windows::Forms::Padding(16);

			lblRecentHeader = gcnew Label();
			lblRecentHeader->Text = L"Recent Rental Activity";
			lblRecentHeader->Font = gcnew Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblRecentHeader->ForeColor = Color::FromArgb(47, 79, 79);
			lblRecentHeader->Dock = DockStyle::Top;
			lblRecentHeader->Height = 32;

			dgvRecentRentals = gcnew DataGridView();
			dgvRecentRentals->Dock = DockStyle::Fill;
			dgvRecentRentals->BackgroundColor = Color::White;
			dgvRecentRentals->BorderStyle = BorderStyle::None;
			dgvRecentRentals->AllowUserToAddRows = false;
			dgvRecentRentals->AllowUserToDeleteRows = false;
			dgvRecentRentals->ReadOnly = true;
			dgvRecentRentals->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dgvRecentRentals->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dgvRecentRentals->RowHeadersVisible = false;
			dgvRecentRentals->CellFormatting += gcnew DataGridViewCellFormattingEventHandler(this, &dashboard::dgvRecent_CellFormatting);
			dgvRecentRentals->DataError += gcnew DataGridViewDataErrorEventHandler(this, &dashboard::dgvRecent_DataError);

			pnlRecentContainer->Controls->Add(dgvRecentRentals);
			pnlRecentContainer->Controls->Add(lblRecentHeader);
			splitMain->Panel2->Controls->Add(pnlRecentContainer);

			// Assemble Form controls
			this->Controls->Add(splitMain);
			this->Controls->Add(pnlKpiContainer);
			this->Controls->Add(pnlActions);
			this->Controls->Add(pnlHeader);
			this->Controls->Add(menuStrip1);

			this->MainMenuStrip = menuStrip1;
			this->Load += gcnew EventHandler(this, &dashboard::dashboard_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}

	private:
		void dgvRecent_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e)
		{
			e->ThrowException = false;
		}

		void dashboard_Load(System::Object^ sender, System::EventArgs^ e)
		{
			RefreshDashboardData();
		}

	public:
		void RefreshDashboardData()
		{
			// 1. Fetch live metrics
			Data::DashboardSummary^ summary = Data::DashboardService::GetSummary();

			lblCard1Value->Text = summary->ActiveRentals.ToString();
			lblCard1Sub->Text = "Rentals today: +" + summary->RentalsToday;

			lblCard2Value->Text = summary->OverdueRentals.ToString();
			if (summary->OverdueRentals > 0) {
				lblCard2Sub->Text = "Requires immediate return action!";
				lblCard2Sub->ForeColor = Color::FromArgb(192, 57, 43);
			}
			else {
				lblCard2Sub->Text = "No overdue rentals";
				lblCard2Sub->ForeColor = Color::FromArgb(39, 174, 96);
			}

			lblCard3Value->Text = String::Format("{0} / {1}", summary->AvailableTools, summary->TotalTools);
			lblCard3Sub->Text = String::Format("Rented: {0} | Maint: {1}", summary->RentedTools, summary->MaintenanceTools);

			lblCard4Value->Text = String::Format("LKR {0:N2}", summary->TotalRevenue);
			lblCard4Sub->Text = String::Format("Deposits held: LKR {0:N2}", summary->DepositsHeld);

			// 2. Populate Chart with category breakdown
			chartInventory->Series["Categories"]->Points->Clear();
			DataTable^ dtCat = Data::DashboardService::GetCategoryStats();
			for (int i = 0; i < dtCat->Rows->Count; i++) {
				String^ cat = dtCat->Rows[i]["Category"]->ToString();
				int count = Convert::ToInt32(dtCat->Rows[i]["ToolCount"]);
				DataPoint^ dp = gcnew DataPoint();
				dp->SetValueXY(cat, count);
				dp->LegendText = cat + " (" + count + ")";
				dp->Label = count.ToString();
				chartInventory->Series["Categories"]->Points->Add(dp);
			}

			// 3. Populate Recent Rentals Grid
			DataTable^ dtRecent = Data::DashboardService::GetRecentRentals(8);
			dgvRecentRentals->DataSource = dtRecent;
			if (dgvRecentRentals->Columns->Contains("rental_code")) dgvRecentRentals->Columns["rental_code"]->HeaderText = L"Code";
			if (dgvRecentRentals->Columns->Contains("customer_name")) dgvRecentRentals->Columns["customer_name"]->HeaderText = L"Customer";
			if (dgvRecentRentals->Columns->Contains("tool_name")) dgvRecentRentals->Columns["tool_name"]->HeaderText = L"Tool";
			if (dgvRecentRentals->Columns->Contains("rent_date")) dgvRecentRentals->Columns["rent_date"]->HeaderText = L"Rent Date";
			if (dgvRecentRentals->Columns->Contains("due_date")) dgvRecentRentals->Columns["due_date"]->HeaderText = L"Due Date";
			if (dgvRecentRentals->Columns->Contains("status")) dgvRecentRentals->Columns["status"]->HeaderText = L"Status";
			if (dgvRecentRentals->Columns->Contains("deposit_paid")) dgvRecentRentals->Columns["deposit_paid"]->Visible = false;
			if (dgvRecentRentals->Columns->Contains("total_amount")) dgvRecentRentals->Columns["total_amount"]->Visible = false;
		}

	private:
		void dgvRecent_CellFormatting(System::Object^ sender, DataGridViewCellFormattingEventArgs^ e)
		{
			if (dgvRecentRentals->Columns[e->ColumnIndex]->Name == "status" && e->Value != nullptr) {
				String^ val = e->Value->ToString();
				if (val == "Active") {
					e->CellStyle->ForeColor = Color::FromArgb(41, 128, 185);
					e->CellStyle->Font = gcnew Drawing::Font(dgvRecentRentals->Font, FontStyle::Bold);
				}
				else if (val == "Overdue") {
					e->CellStyle->ForeColor = Color::FromArgb(192, 57, 43);
					e->CellStyle->Font = gcnew Drawing::Font(dgvRecentRentals->Font, FontStyle::Bold);
				}
				else if (val == "Returned") {
					e->CellStyle->ForeColor = Color::FromArgb(39, 174, 96);
				}
			}
		}

		void menuRefresh_Click(System::Object^ sender, System::EventArgs^ e)
		{
			RefreshDashboardData();
		}

		void openInventory_Click(System::Object^ sender, System::EventArgs^ e)
		{
			inventory^ invForm = gcnew inventory();
			invForm->ShowDialog(this);
			RefreshDashboardData();
		}

		void openRentals_Click(System::Object^ sender, System::EventArgs^ e)
		{
			rentals^ rentForm = gcnew rentals();
			rentForm->ShowDialog(this);
			RefreshDashboardData();
		}

		void openCustomers_Click(System::Object^ sender, System::EventArgs^ e)
		{
			customers^ custForm = gcnew customers();
			custForm->ShowDialog(this);
			RefreshDashboardData();
		}

		void openSettings_Click(System::Object^ sender, System::EventArgs^ e)
		{
			settings^ setForm = gcnew settings();
			setForm->ShowDialog(this);
			RefreshDashboardData();
		}

		void menuLogout_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (MessageBox::Show(this, L"Are you sure you want to log out of Rent-A-Tool?",
				L"Confirm Logout", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				this->Close();
			}
		}

		void menuExit_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Application::Exit();
		}

		void menuAbout_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MessageBox::Show(this,
				L"Rent-A-Tool Management System\nVersion 1.0\n\nA desktop application for managing tool rentals, inventory, customer accounts, and return processing.",
				L"About Rent-A-Tool", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	};
}
