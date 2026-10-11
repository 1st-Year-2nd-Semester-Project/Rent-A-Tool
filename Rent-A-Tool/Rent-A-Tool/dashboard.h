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
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ menuFile;
		System::Windows::Forms::ToolStripMenuItem^ menuFileRefresh;
		System::Windows::Forms::ToolStripMenuItem^ menuFileLogout;
		System::Windows::Forms::ToolStripMenuItem^ menuFileExit;
		System::Windows::Forms::ToolStripMenuItem^ menuInventory;
		System::Windows::Forms::ToolStripMenuItem^ menuInventoryManage;
		System::Windows::Forms::ToolStripMenuItem^ menuRentals;
		System::Windows::Forms::ToolStripMenuItem^ menuRentalsAll;
		System::Windows::Forms::ToolStripMenuItem^ menuCustomers;
		System::Windows::Forms::ToolStripMenuItem^ menuCustomersManage;
		System::Windows::Forms::ToolStripMenuItem^ menuSettings;
		System::Windows::Forms::ToolStripMenuItem^ menuSettingsManage;
		System::Windows::Forms::ToolStripMenuItem^ menuHelp;
		System::Windows::Forms::ToolStripMenuItem^ menuHelpAbout;
		System::Windows::Forms::Panel^ pnlHeader;
		System::Windows::Forms::Label^ lblAppTitle;
		System::Windows::Forms::Label^ lblAppSubtitle;
		System::Windows::Forms::Label^ lblUserBadge;
		System::Windows::Forms::Label^ lblDateBadge;
		System::Windows::Forms::Button^ btnHeaderRefresh;
		System::Windows::Forms::Button^ btnHeaderLogout;
		System::Windows::Forms::Panel^ pnlActions;
		System::Windows::Forms::Button^ btnActNewRental;
		System::Windows::Forms::Button^ btnActReturn;
		System::Windows::Forms::Button^ btnActTools;
		System::Windows::Forms::Button^ btnActCustomers;
		System::Windows::Forms::Button^ btnActSettings;
		System::Windows::Forms::Panel^ pnlKpiContainer;
		System::Windows::Forms::Panel^ cardActiveRentals;
		System::Windows::Forms::Label^ lblCard1Title;
		System::Windows::Forms::Label^ lblCard1Value;
		System::Windows::Forms::Label^ lblCard1Sub;
		System::Windows::Forms::Panel^ cardOverdue;
		System::Windows::Forms::Label^ lblCard2Title;
		System::Windows::Forms::Label^ lblCard2Value;
		System::Windows::Forms::Label^ lblCard2Sub;
		System::Windows::Forms::Panel^ cardTools;
		System::Windows::Forms::Label^ lblCard3Title;
		System::Windows::Forms::Label^ lblCard3Value;
		System::Windows::Forms::Label^ lblCard3Sub;
		System::Windows::Forms::Panel^ cardRevenue;
		System::Windows::Forms::Label^ lblCard4Title;
		System::Windows::Forms::Label^ lblCard4Value;
		System::Windows::Forms::Label^ lblCard4Sub;
		System::Windows::Forms::SplitContainer^ splitMain;
		System::Windows::Forms::Panel^ pnlChartContainer;
		System::Windows::Forms::Label^ lblChartHeader;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartInventory;
		System::Windows::Forms::Panel^ pnlRecentContainer;
		System::Windows::Forms::Label^ lblRecentHeader;
		System::Windows::Forms::DataGridView^ dgvRecentRentals;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFileRefresh = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFileLogout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFileExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuInventory = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuInventoryManage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuRentals = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuRentalsAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuCustomers = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuCustomersManage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSettings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSettingsManage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuHelpAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pnlHeader = (gcnew System::Windows::Forms::Panel());
			this->lblAppTitle = (gcnew System::Windows::Forms::Label());
			this->lblAppSubtitle = (gcnew System::Windows::Forms::Label());
			this->lblUserBadge = (gcnew System::Windows::Forms::Label());
			this->lblDateBadge = (gcnew System::Windows::Forms::Label());
			this->btnHeaderRefresh = (gcnew System::Windows::Forms::Button());
			this->btnHeaderLogout = (gcnew System::Windows::Forms::Button());
			this->pnlActions = (gcnew System::Windows::Forms::Panel());
			this->btnActNewRental = (gcnew System::Windows::Forms::Button());
			this->btnActReturn = (gcnew System::Windows::Forms::Button());
			this->btnActTools = (gcnew System::Windows::Forms::Button());
			this->btnActCustomers = (gcnew System::Windows::Forms::Button());
			this->btnActSettings = (gcnew System::Windows::Forms::Button());
			this->pnlKpiContainer = (gcnew System::Windows::Forms::Panel());
			this->cardActiveRentals = (gcnew System::Windows::Forms::Panel());
			this->lblCard1Title = (gcnew System::Windows::Forms::Label());
			this->lblCard1Value = (gcnew System::Windows::Forms::Label());
			this->lblCard1Sub = (gcnew System::Windows::Forms::Label());
			this->cardOverdue = (gcnew System::Windows::Forms::Panel());
			this->lblCard2Title = (gcnew System::Windows::Forms::Label());
			this->lblCard2Value = (gcnew System::Windows::Forms::Label());
			this->lblCard2Sub = (gcnew System::Windows::Forms::Label());
			this->cardTools = (gcnew System::Windows::Forms::Panel());
			this->lblCard3Title = (gcnew System::Windows::Forms::Label());
			this->lblCard3Value = (gcnew System::Windows::Forms::Label());
			this->lblCard3Sub = (gcnew System::Windows::Forms::Label());
			this->cardRevenue = (gcnew System::Windows::Forms::Panel());
			this->lblCard4Title = (gcnew System::Windows::Forms::Label());
			this->lblCard4Value = (gcnew System::Windows::Forms::Label());
			this->lblCard4Sub = (gcnew System::Windows::Forms::Label());
			this->splitMain = (gcnew System::Windows::Forms::SplitContainer());
			this->pnlChartContainer = (gcnew System::Windows::Forms::Panel());
			this->lblChartHeader = (gcnew System::Windows::Forms::Label());
			this->chartInventory = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pnlRecentContainer = (gcnew System::Windows::Forms::Panel());
			this->lblRecentHeader = (gcnew System::Windows::Forms::Label());
			this->dgvRecentRentals = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->pnlHeader->SuspendLayout();
			this->pnlActions->SuspendLayout();
			this->pnlKpiContainer->SuspendLayout();
			this->cardActiveRentals->SuspendLayout();
			this->cardOverdue->SuspendLayout();
			this->cardTools->SuspendLayout();
			this->cardRevenue->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitMain))->BeginInit();
			this->splitMain->Panel1->SuspendLayout();
			this->splitMain->Panel2->SuspendLayout();
			this->splitMain->SuspendLayout();
			this->pnlChartContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartInventory))->BeginInit();
			this->pnlRecentContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRecentRentals))->BeginInit();
			this->SuspendLayout();

			// Form properties
			this->Text = L"Rent-A-Tool - Master Dashboard";
			this->ClientSize = System::Drawing::Size(1260, 780);
			this->MinimumSize = System::Drawing::Size(1100, 700);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->BackColor = System::Drawing::Color::FromArgb(240, 243, 246);
			this->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);

			// ================= MENU STRIP =================
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(38, 64, 64);
			this->menuStrip1->ForeColor = System::Drawing::Color::White;
			this->menuStrip1->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			this->menuStrip1->Padding = System::Windows::Forms::Padding(6, 4, 6, 4);

			// File menu
			this->menuFile->ForeColor = System::Drawing::Color::White;
			this->menuFile->DropDownItems->Add(this->menuFileRefresh);
			this->menuFile->DropDownItems->Add(gcnew ToolStripSeparator());
			this->menuFile->DropDownItems->Add(this->menuFileLogout);
			this->menuFile->DropDownItems->Add(this->menuFileExit);

			// Inventory menu
			this->menuInventory->ForeColor = System::Drawing::Color::White;
			this->menuInventory->DropDownItems->Add(this->menuInventoryManage);

			// Rentals menu
			this->menuRentals->ForeColor = System::Drawing::Color::White;
			this->menuRentals->DropDownItems->Add(this->menuRentalsAll);

			// Customers menu
			this->menuCustomers->ForeColor = System::Drawing::Color::White;
			this->menuCustomers->DropDownItems->Add(this->menuCustomersManage);

			// Settings menu
			this->menuSettings->ForeColor = System::Drawing::Color::White;
			this->menuSettings->DropDownItems->Add(this->menuSettingsManage);

			// Help menu
			this->menuHelp->ForeColor = System::Drawing::Color::White;
			this->menuHelp->DropDownItems->Add(this->menuHelpAbout);

			this->menuStrip1->Items->Add(menuFile);
			this->menuStrip1->Items->Add(menuInventory);
			this->menuStrip1->Items->Add(menuRentals);
			this->menuStrip1->Items->Add(menuCustomers);
			this->menuStrip1->Items->Add(menuSettings);
			this->menuStrip1->Items->Add(menuHelp);

			// ================= TOP HEADER PANEL =================
			this->pnlHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlHeader->Height = 82;
			this->pnlHeader->BackColor = System::Drawing::Color::FromArgb(47, 79, 79); // DarkSlateGray
			this->pnlHeader->Padding = System::Windows::Forms::Padding(24, 12, 24, 12);
			this->lblAppTitle->Text = L"RENT-A-TOOL MANAGEMENT CONSOLE";
			this->lblAppTitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold);
			this->lblAppTitle->ForeColor = System::Drawing::Color::White;
			this->lblAppTitle->Location = System::Drawing::Point(24, 14);
			this->lblAppTitle->AutoSize = true;
			this->lblAppSubtitle->Text = L"Real-time overview of active rentals, inventory availability, returns, and revenue";
			this->lblAppSubtitle->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			this->lblAppSubtitle->ForeColor = System::Drawing::Color::FromArgb(200, 225, 225);
			this->lblAppSubtitle->Location = System::Drawing::Point(26, 46);
			this->lblAppSubtitle->AutoSize = true;
			this->btnHeaderLogout->Text = L"Log Out";
			this->btnHeaderLogout->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold);
			this->btnHeaderLogout->ForeColor = System::Drawing::Color::White;
			this->btnHeaderLogout->BackColor = System::Drawing::Color::FromArgb(192, 57, 43);
			this->btnHeaderLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHeaderLogout->FlatAppearance->BorderSize = 0;
			this->btnHeaderLogout->Size = System::Drawing::Size(85, 32);
			this->btnHeaderLogout->Location = System::Drawing::Point(1145, 24);
			this->btnHeaderLogout->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
			this->btnHeaderLogout->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnHeaderLogout->Click += gcnew EventHandler(this, &dashboard::menuLogout_Click);
			this->btnHeaderRefresh->Text = L"Refresh Data";
			this->btnHeaderRefresh->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold);
			this->btnHeaderRefresh->ForeColor = System::Drawing::Color::White;
			this->btnHeaderRefresh->BackColor = System::Drawing::Color::FromArgb(52, 152, 219);
			this->btnHeaderRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHeaderRefresh->FlatAppearance->BorderSize = 0;
			this->btnHeaderRefresh->Size = System::Drawing::Size(105, 32);
			this->btnHeaderRefresh->Location = System::Drawing::Point(1030, 24);
			this->btnHeaderRefresh->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
			this->btnHeaderRefresh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnHeaderRefresh->Click += gcnew EventHandler(this, &dashboard::menuRefresh_Click);
			this->lblUserBadge->Text = L"User: Chukka Fernando (Admin)";
			this->lblUserBadge->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			this->lblUserBadge->ForeColor = System::Drawing::Color::FromArgb(254, 211, 48);
			this->lblUserBadge->Location = System::Drawing::Point(730, 18);
			this->lblUserBadge->Size = System::Drawing::Size(285, 20);
			this->lblUserBadge->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblUserBadge->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
			this->lblDateBadge->Text = L"Today";
			this->lblDateBadge->Font = gcnew System::Drawing::Font(L"Segoe UI", 9);
			this->lblDateBadge->ForeColor = System::Drawing::Color::FromArgb(210, 230, 230);
			this->lblDateBadge->Location = System::Drawing::Point(730, 42);
			this->lblDateBadge->Size = System::Drawing::Size(285, 20);
			this->lblDateBadge->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->lblDateBadge->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);

			this->pnlHeader->Controls->Add(this->lblAppTitle);
			this->pnlHeader->Controls->Add(this->lblAppSubtitle);
			this->pnlHeader->Controls->Add(this->lblUserBadge);
			this->pnlHeader->Controls->Add(this->lblDateBadge);
			this->pnlHeader->Controls->Add(this->btnHeaderRefresh);
			this->pnlHeader->Controls->Add(this->btnHeaderLogout);

			// ================= QUICK ACTIONS BAR =================
			this->pnlActions->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlActions->Height = 56;
			this->pnlActions->BackColor = System::Drawing::Color::White;
			this->pnlActions->Padding = System::Windows::Forms::Padding(24, 10, 24, 10);
			this->btnActNewRental->Text = L"+ Issue New Rental";
			this->btnActNewRental->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			this->btnActNewRental->BackColor = System::Drawing::Color::FromArgb(39, 174, 96); // Green
			this->btnActNewRental->ForeColor = System::Drawing::Color::White;
			this->btnActNewRental->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActNewRental->FlatAppearance->BorderSize = 0;
			this->btnActNewRental->Location = System::Drawing::Point(24, 10);
			this->btnActNewRental->Size = System::Drawing::Size(170, 36);
			this->btnActNewRental->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActNewRental->Click += gcnew EventHandler(this, &dashboard::openRentals_Click);
			this->btnActReturn->Text = L"Process Return";
			this->btnActReturn->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			this->btnActReturn->BackColor = System::Drawing::Color::FromArgb(230, 126, 34); // Orange
			this->btnActReturn->ForeColor = System::Drawing::Color::White;
			this->btnActReturn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActReturn->FlatAppearance->BorderSize = 0;
			this->btnActReturn->Location = System::Drawing::Point(204, 10);
			this->btnActReturn->Size = System::Drawing::Size(150, 36);
			this->btnActReturn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActReturn->Click += gcnew EventHandler(this, &dashboard::openRentals_Click);
			this->btnActTools->Text = L"Tool Inventory";
			this->btnActTools->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			this->btnActTools->BackColor = System::Drawing::Color::FromArgb(47, 79, 79); // Dark teal
			this->btnActTools->ForeColor = System::Drawing::Color::White;
			this->btnActTools->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActTools->FlatAppearance->BorderSize = 0;
			this->btnActTools->Location = System::Drawing::Point(364, 10);
			this->btnActTools->Size = System::Drawing::Size(150, 36);
			this->btnActTools->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActTools->Click += gcnew EventHandler(this, &dashboard::openInventory_Click);
			this->btnActCustomers->Text = L"Customer Directory";
			this->btnActCustomers->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			this->btnActCustomers->BackColor = System::Drawing::Color::FromArgb(52, 152, 219); // Blue
			this->btnActCustomers->ForeColor = System::Drawing::Color::White;
			this->btnActCustomers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActCustomers->FlatAppearance->BorderSize = 0;
			this->btnActCustomers->Location = System::Drawing::Point(524, 10);
			this->btnActCustomers->Size = System::Drawing::Size(160, 36);
			this->btnActCustomers->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActCustomers->Click += gcnew EventHandler(this, &dashboard::openCustomers_Click);
			this->btnActSettings->Text = L"Settings & Users";
			this->btnActSettings->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			this->btnActSettings->BackColor = System::Drawing::Color::FromArgb(108, 122, 137); // Slate
			this->btnActSettings->ForeColor = System::Drawing::Color::White;
			this->btnActSettings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActSettings->FlatAppearance->BorderSize = 0;
			this->btnActSettings->Location = System::Drawing::Point(694, 10);
			this->btnActSettings->Size = System::Drawing::Size(150, 36);
			this->btnActSettings->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActSettings->Click += gcnew EventHandler(this, &dashboard::openSettings_Click);

			this->pnlActions->Controls->Add(this->btnActNewRental);
			this->pnlActions->Controls->Add(this->btnActReturn);
			this->pnlActions->Controls->Add(this->btnActTools);
			this->pnlActions->Controls->Add(this->btnActCustomers);
			this->pnlActions->Controls->Add(this->btnActSettings);

			// ================= KPI CARDS PANEL =================
			this->pnlKpiContainer->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlKpiContainer->Height = 120;
			this->pnlKpiContainer->BackColor = System::Drawing::Color::FromArgb(240, 243, 246);
			this->pnlKpiContainer->Padding = System::Windows::Forms::Padding(24, 14, 24, 14);

			// Card 1: Active Rentals
			this->cardActiveRentals->BackColor = System::Drawing::Color::White;
			this->cardActiveRentals->Size = System::Drawing::Size(280, 92);
			this->cardActiveRentals->Location = System::Drawing::Point(24, 14);
			this->lblCard1Title->Text = L"ACTIVE RENTALS";
			this->lblCard1Title->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold);
			this->lblCard1Title->ForeColor = System::Drawing::Color::FromArgb(41, 128, 185);
			this->lblCard1Title->Location = System::Drawing::Point(16, 12);
			this->lblCard1Title->AutoSize = true;
			this->lblCard1Value->Text = L"0";
			this->lblCard1Value->Font = gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold);
			this->lblCard1Value->ForeColor = System::Drawing::Color::FromArgb(44, 62, 80);
			this->lblCard1Value->Location = System::Drawing::Point(14, 30);
			this->lblCard1Value->AutoSize = true;
			this->lblCard1Sub->Text = L"Rentals today: 0";
			this->lblCard1Sub->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5F);
			this->lblCard1Sub->ForeColor = System::Drawing::Color::FromArgb(127, 140, 141);
			this->lblCard1Sub->Location = System::Drawing::Point(16, 68);
			this->lblCard1Sub->AutoSize = true;

			this->cardActiveRentals->Controls->Add(this->lblCard1Title);
			this->cardActiveRentals->Controls->Add(this->lblCard1Value);
			this->cardActiveRentals->Controls->Add(this->lblCard1Sub);

			// Card 2: Overdue
			this->cardOverdue->BackColor = System::Drawing::Color::White;
			this->cardOverdue->Size = System::Drawing::Size(280, 92);
			this->cardOverdue->Location = System::Drawing::Point(324, 14);
			this->lblCard2Title->Text = L"OVERDUE RETURNS";
			this->lblCard2Title->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold);
			this->lblCard2Title->ForeColor = System::Drawing::Color::FromArgb(192, 57, 43);
			this->lblCard2Title->Location = System::Drawing::Point(16, 12);
			this->lblCard2Title->AutoSize = true;
			this->lblCard2Value->Text = L"0";
			this->lblCard2Value->Font = gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold);
			this->lblCard2Value->ForeColor = System::Drawing::Color::FromArgb(192, 57, 43);
			this->lblCard2Value->Location = System::Drawing::Point(14, 30);
			this->lblCard2Value->AutoSize = true;
			this->lblCard2Sub->Text = L"Requires follow-up";
			this->lblCard2Sub->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5F);
			this->lblCard2Sub->ForeColor = System::Drawing::Color::FromArgb(127, 140, 141);
			this->lblCard2Sub->Location = System::Drawing::Point(16, 68);
			this->lblCard2Sub->AutoSize = true;

			this->cardOverdue->Controls->Add(this->lblCard2Title);
			this->cardOverdue->Controls->Add(this->lblCard2Value);
			this->cardOverdue->Controls->Add(this->lblCard2Sub);

			// Card 3: Available Tools
			this->cardTools->BackColor = System::Drawing::Color::White;
			this->cardTools->Size = System::Drawing::Size(280, 92);
			this->cardTools->Location = System::Drawing::Point(624, 14);
			this->lblCard3Title->Text = L"TOOL AVAILABILITY";
			this->lblCard3Title->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold);
			this->lblCard3Title->ForeColor = System::Drawing::Color::FromArgb(39, 174, 96);
			this->lblCard3Title->Location = System::Drawing::Point(16, 12);
			this->lblCard3Title->AutoSize = true;
			this->lblCard3Value->Text = L"0";
			this->lblCard3Value->Font = gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold);
			this->lblCard3Value->ForeColor = System::Drawing::Color::FromArgb(44, 62, 80);
			this->lblCard3Value->Location = System::Drawing::Point(14, 30);
			this->lblCard3Value->AutoSize = true;
			this->lblCard3Sub->Text = L"Rented: 0 | Maintenance: 0";
			this->lblCard3Sub->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5F);
			this->lblCard3Sub->ForeColor = System::Drawing::Color::FromArgb(127, 140, 141);
			this->lblCard3Sub->Location = System::Drawing::Point(16, 68);
			this->lblCard3Sub->AutoSize = true;

			this->cardTools->Controls->Add(this->lblCard3Title);
			this->cardTools->Controls->Add(this->lblCard3Value);
			this->cardTools->Controls->Add(this->lblCard3Sub);

			// Card 4: Total Revenue & Deposits
			this->cardRevenue->BackColor = System::Drawing::Color::White;
			this->cardRevenue->Size = System::Drawing::Size(305, 92);
			this->cardRevenue->Location = System::Drawing::Point(924, 14);
			this->lblCard4Title->Text = L"TOTAL REVENUE";
			this->lblCard4Title->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold);
			this->lblCard4Title->ForeColor = System::Drawing::Color::FromArgb(142, 68, 173);
			this->lblCard4Title->Location = System::Drawing::Point(16, 12);
			this->lblCard4Title->AutoSize = true;
			this->lblCard4Value->Text = L"LKR 0.00";
			this->lblCard4Value->Font = gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold);
			this->lblCard4Value->ForeColor = System::Drawing::Color::FromArgb(44, 62, 80);
			this->lblCard4Value->Location = System::Drawing::Point(14, 32);
			this->lblCard4Value->AutoSize = true;
			this->lblCard4Sub->Text = L"Deposits held: LKR 0.00";
			this->lblCard4Sub->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5F);
			this->lblCard4Sub->ForeColor = System::Drawing::Color::FromArgb(127, 140, 141);
			this->lblCard4Sub->Location = System::Drawing::Point(16, 68);
			this->lblCard4Sub->AutoSize = true;

			this->cardRevenue->Controls->Add(this->lblCard4Title);
			this->cardRevenue->Controls->Add(this->lblCard4Value);
			this->cardRevenue->Controls->Add(this->lblCard4Sub);

			this->pnlKpiContainer->Controls->Add(this->cardActiveRentals);
			this->pnlKpiContainer->Controls->Add(this->cardOverdue);
			this->pnlKpiContainer->Controls->Add(this->cardTools);
			this->pnlKpiContainer->Controls->Add(this->cardRevenue);

			// ================= SPLIT MAIN SECTION =================
			this->splitMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitMain->SplitterDistance = 490;
			this->splitMain->Padding = System::Windows::Forms::Padding(24, 0, 24, 16);
			this->splitMain->BackColor = System::Drawing::Color::FromArgb(240, 243, 246);

			// Left Panel: Tool Distribution Chart
			this->pnlChartContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlChartContainer->BackColor = System::Drawing::Color::White;
			this->pnlChartContainer->Padding = System::Windows::Forms::Padding(16);
			this->lblChartHeader->Text = L"Tool Inventory by Category";
			this->lblChartHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold);
			this->lblChartHeader->ForeColor = System::Drawing::Color::FromArgb(47, 79, 79);
			this->lblChartHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblChartHeader->Height = 32;
			this->chartInventory->Dock = System::Windows::Forms::DockStyle::Fill;
			chartArea1->Name = L"MainArea";
			chartArea1->BackColor = System::Drawing::Color::White;
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::FromArgb(240, 240, 240);
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::FromArgb(240, 240, 240);
			this->chartInventory->ChartAreas->Add(chartArea1);

			legend1->Name = L"MainLegend";
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			this->chartInventory->Legends->Add(legend1);

			series1->Name = L"Categories";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->IsValueShownAsLabel = true;
			this->chartInventory->Series->Add(series1);

			this->pnlChartContainer->Controls->Add(this->chartInventory);
			this->pnlChartContainer->Controls->Add(this->lblChartHeader);
			this->splitMain->Panel1->Controls->Add(this->pnlChartContainer);

			// Right Panel: Recent Rentals Table
			this->pnlRecentContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlRecentContainer->BackColor = System::Drawing::Color::White;
			this->pnlRecentContainer->Padding = System::Windows::Forms::Padding(16);
			this->lblRecentHeader->Text = L"Recent Rental Activity";
			this->lblRecentHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold);
			this->lblRecentHeader->ForeColor = System::Drawing::Color::FromArgb(47, 79, 79);
			this->lblRecentHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblRecentHeader->Height = 32;
			this->dgvRecentRentals->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvRecentRentals->BackgroundColor = System::Drawing::Color::White;
			this->dgvRecentRentals->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgvRecentRentals->AllowUserToAddRows = false;
			this->dgvRecentRentals->AllowUserToDeleteRows = false;
			this->dgvRecentRentals->ReadOnly = true;
			this->dgvRecentRentals->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvRecentRentals->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvRecentRentals->RowHeadersVisible = false;
			this->dgvRecentRentals->CellFormatting += gcnew DataGridViewCellFormattingEventHandler(this, &dashboard::dgvRecent_CellFormatting);
			this->dgvRecentRentals->DataError += gcnew DataGridViewDataErrorEventHandler(this, &dashboard::dgvRecent_DataError);

			this->pnlRecentContainer->Controls->Add(this->dgvRecentRentals);
			this->pnlRecentContainer->Controls->Add(this->lblRecentHeader);
			this->splitMain->Panel2->Controls->Add(this->pnlRecentContainer);

			// Assemble Form controls
			this->Controls->Add(this->splitMain);
			this->Controls->Add(this->pnlKpiContainer);
			this->Controls->Add(this->pnlActions);
			this->Controls->Add(this->pnlHeader);
			this->Controls->Add(this->menuStrip1);

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
			if (this->DesignMode) return;
			try {
				String^ userName = CurrentUser::FullName != nullptr ? CurrentUser::FullName : "Chukka Fernando";
				String^ role = CurrentUser::Role != nullptr ? CurrentUser::Role : "Admin";
				this->lblUserBadge->Text = String::Format("User: {0} ({1})", userName, role);
				this->lblDateBadge->Text = DateTime::Now.ToString("dddd, MMMM dd, yyyy");
			} catch (Exception^) {}
			try {
				RefreshDashboardData();
			} catch (Exception^) {}
		}

	public:
		void RefreshDashboardData()
		{
			// 1. Fetch live metrics
			Data::DashboardSummary^ summary = Data::DashboardService::GetSummary();

			this->lblCard1Value->Text = summary->ActiveRentals.ToString();
			this->lblCard1Sub->Text = "Rentals today: +" + summary->RentalsToday;

			this->lblCard2Value->Text = summary->OverdueRentals.ToString();
			if (summary->OverdueRentals > 0) {
				this->lblCard2Sub->Text = "Requires immediate return action!";
				this->lblCard2Sub->ForeColor = System::Drawing::Color::FromArgb(192, 57, 43);
			}
			else {
				this->lblCard2Sub->Text = "No overdue rentals";
				this->lblCard2Sub->ForeColor = System::Drawing::Color::FromArgb(39, 174, 96);
			}

			this->lblCard3Value->Text = String::Format("{0} / {1}", summary->AvailableTools, summary->TotalTools);
			this->lblCard3Sub->Text = String::Format("Rented: {0} | Maint: {1}", summary->RentedTools, summary->MaintenanceTools);

			this->lblCard4Value->Text = String::Format("LKR {0:N2}", summary->TotalRevenue);
			this->lblCard4Sub->Text = String::Format("Deposits held: LKR {0:N2}", summary->DepositsHeld);

			// 2. Populate Chart with category breakdown
			this->chartInventory->Series["Categories"]->Points->Clear();
			DataTable^ dtCat = Data::DashboardService::GetCategoryStats();
			for (int i = 0; i < dtCat->Rows->Count; i++) {
				String^ cat = dtCat->Rows[i]["Category"]->ToString();
				int count = Convert::ToInt32(dtCat->Rows[i]["ToolCount"]);
				DataPoint^ dp = gcnew DataPoint();
				dp->SetValueXY(cat, count);
				dp->LegendText = cat + " (" + count + ")";
				dp->Label = count.ToString();
				this->chartInventory->Series["Categories"]->Points->Add(dp);
			}

			// 3. Populate Recent Rentals Grid
			DataTable^ dtRecent = Data::DashboardService::GetRecentRentals(8);
			this->dgvRecentRentals->DataSource = dtRecent;
			if (this->dgvRecentRentals->Columns->Contains("rental_code")) this->dgvRecentRentals->Columns["rental_code"]->HeaderText = L"Code";
			if (this->dgvRecentRentals->Columns->Contains("customer_name")) this->dgvRecentRentals->Columns["customer_name"]->HeaderText = L"Customer";
			if (this->dgvRecentRentals->Columns->Contains("tool_name")) this->dgvRecentRentals->Columns["tool_name"]->HeaderText = L"Tool";
			if (this->dgvRecentRentals->Columns->Contains("rent_date")) this->dgvRecentRentals->Columns["rent_date"]->HeaderText = L"Rent Date";
			if (this->dgvRecentRentals->Columns->Contains("due_date")) this->dgvRecentRentals->Columns["due_date"]->HeaderText = L"Due Date";
			if (this->dgvRecentRentals->Columns->Contains("status")) this->dgvRecentRentals->Columns["status"]->HeaderText = L"Status";
			if (this->dgvRecentRentals->Columns->Contains("deposit_paid")) this->dgvRecentRentals->Columns["deposit_paid"]->Visible = false;
			if (this->dgvRecentRentals->Columns->Contains("total_amount")) this->dgvRecentRentals->Columns["total_amount"]->Visible = false;
		}

	private:
		void dgvRecent_CellFormatting(System::Object^ sender, DataGridViewCellFormattingEventArgs^ e)
		{
			if (this->dgvRecentRentals->Columns[e->ColumnIndex]->Name == "status" && e->Value != nullptr) {
				String^ val = e->Value->ToString();
				if (val == "Active") {
					e->CellStyle->ForeColor = System::Drawing::Color::FromArgb(41, 128, 185);
					e->CellStyle->Font = gcnew System::Drawing::Font(this->dgvRecentRentals->Font, System::Drawing::FontStyle::Bold);
				}
				else if (val == "Overdue") {
					e->CellStyle->ForeColor = System::Drawing::Color::FromArgb(192, 57, 43);
					e->CellStyle->Font = gcnew System::Drawing::Font(this->dgvRecentRentals->Font, System::Drawing::FontStyle::Bold);
				}
				else if (val == "Returned") {
					e->CellStyle->ForeColor = System::Drawing::Color::FromArgb(39, 174, 96);
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
