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
		System::Windows::Forms::ToolStripSeparator^ menuFileSep;
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
		System::Windows::Forms::Panel^ pnlRecentHeaderTop;
		System::Windows::Forms::Label^ lblRecentHeader;
		System::Windows::Forms::Label^ lblRecentSubtitle;
		System::Windows::Forms::DataGridView^ dgvRecentRentals;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(dashboard::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFileRefresh = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFileSep = (gcnew System::Windows::Forms::ToolStripSeparator());
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
			this->chartInventory = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->lblChartHeader = (gcnew System::Windows::Forms::Label());
			this->pnlRecentContainer = (gcnew System::Windows::Forms::Panel());
			this->pnlRecentHeaderTop = (gcnew System::Windows::Forms::Panel());
			this->lblRecentSubtitle = (gcnew System::Windows::Forms::Label());
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
			this->pnlRecentHeaderTop->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRecentRentals))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->menuStrip1->ForeColor = System::Drawing::Color::White;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->menuFile, this->menuInventory,
					this->menuRentals, this->menuCustomers, this->menuSettings, this->menuHelp
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(6, 4, 6, 4);
			this->menuStrip1->Size = System::Drawing::Size(1260, 29);
			this->menuStrip1->TabIndex = 4;
			// 
			// menuFile
			// 
			this->menuFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->menuFileRefresh,
					this->menuFileSep, this->menuFileLogout, this->menuFileExit
			});
			this->menuFile->ForeColor = System::Drawing::Color::White;
			this->menuFile->Name = L"menuFile";
			this->menuFile->Size = System::Drawing::Size(39, 21);
			this->menuFile->Text = L"&File";
			// 
			// menuFileRefresh
			// 
			this->menuFileRefresh->Name = L"menuFileRefresh";
			this->menuFileRefresh->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->menuFileRefresh->Size = System::Drawing::Size(172, 22);
			this->menuFileRefresh->Text = L"&Refresh Data";
			this->menuFileRefresh->Click += gcnew System::EventHandler(this, &dashboard::menuRefresh_Click);
			// 
			// menuFileSep
			// 
			this->menuFileSep->Name = L"menuFileSep";
			this->menuFileSep->Size = System::Drawing::Size(169, 6);
			// 
			// menuFileLogout
			// 
			this->menuFileLogout->Name = L"menuFileLogout";
			this->menuFileLogout->Size = System::Drawing::Size(172, 22);
			this->menuFileLogout->Text = L"&Log Out";
			this->menuFileLogout->Click += gcnew System::EventHandler(this, &dashboard::menuLogout_Click);
			// 
			// menuFileExit
			// 
			this->menuFileExit->Name = L"menuFileExit";
			this->menuFileExit->Size = System::Drawing::Size(172, 22);
			this->menuFileExit->Text = L"E&xit";
			this->menuFileExit->Click += gcnew System::EventHandler(this, &dashboard::menuExit_Click);
			// 
			// menuInventory
			// 
			this->menuInventory->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuInventoryManage });
			this->menuInventory->ForeColor = System::Drawing::Color::White;
			this->menuInventory->Name = L"menuInventory";
			this->menuInventory->Size = System::Drawing::Size(73, 21);
			this->menuInventory->Text = L"&Inventory";
			// 
			// menuInventoryManage
			// 
			this->menuInventoryManage->Name = L"menuInventoryManage";
			this->menuInventoryManage->Size = System::Drawing::Size(168, 22);
			this->menuInventoryManage->Text = L"Manage &Tools...";
			this->menuInventoryManage->Click += gcnew System::EventHandler(this, &dashboard::openInventory_Click);
			// 
			// menuRentals
			// 
			this->menuRentals->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuRentalsAll });
			this->menuRentals->ForeColor = System::Drawing::Color::White;
			this->menuRentals->Name = L"menuRentals";
			this->menuRentals->Size = System::Drawing::Size(62, 21);
			this->menuRentals->Text = L"&Rentals";
			// 
			// menuRentalsAll
			// 
			this->menuRentalsAll->Name = L"menuRentalsAll";
			this->menuRentalsAll->Size = System::Drawing::Size(179, 22);
			this->menuRentalsAll->Text = L"Manage &Rentals...";
			this->menuRentalsAll->Click += gcnew System::EventHandler(this, &dashboard::openRentals_Click);
			// 
			// menuCustomers
			// 
			this->menuCustomers->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuCustomersManage });
			this->menuCustomers->ForeColor = System::Drawing::Color::White;
			this->menuCustomers->Name = L"menuCustomers";
			this->menuCustomers->Size = System::Drawing::Size(82, 21);
			this->menuCustomers->Text = L"&Customers";
			// 
			// menuCustomersManage
			// 
			this->menuCustomersManage->Name = L"menuCustomersManage";
			this->menuCustomersManage->Size = System::Drawing::Size(199, 22);
			this->menuCustomersManage->Text = L"Manage &Customers...";
			this->menuCustomersManage->Click += gcnew System::EventHandler(this, &dashboard::openCustomers_Click);
			// 
			// menuSettings
			// 
			this->menuSettings->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuSettingsManage });
			this->menuSettings->ForeColor = System::Drawing::Color::White;
			this->menuSettings->Name = L"menuSettings";
			this->menuSettings->Size = System::Drawing::Size(66, 21);
			this->menuSettings->Text = L"&Settings";
			// 
			// menuSettingsManage
			// 
			this->menuSettingsManage->Name = L"menuSettingsManage";
			this->menuSettingsManage->Size = System::Drawing::Size(176, 22);
			this->menuSettingsManage->Text = L"System &Settings...";
			this->menuSettingsManage->Click += gcnew System::EventHandler(this, &dashboard::openSettings_Click);
			// 
			// menuHelp
			// 
			this->menuHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuHelpAbout });
			this->menuHelp->ForeColor = System::Drawing::Color::White;
			this->menuHelp->Name = L"menuHelp";
			this->menuHelp->Size = System::Drawing::Size(47, 21);
			this->menuHelp->Text = L"&Help";
			// 
			// menuHelpAbout
			// 
			this->menuHelpAbout->Name = L"menuHelpAbout";
			this->menuHelpAbout->Size = System::Drawing::Size(184, 22);
			this->menuHelpAbout->Text = L"&About Rent-A-Tool";
			this->menuHelpAbout->Click += gcnew System::EventHandler(this, &dashboard::menuAbout_Click);
			// 
			// pnlHeader
			// 
			this->pnlHeader->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->pnlHeader->Controls->Add(this->lblAppTitle);
			this->pnlHeader->Controls->Add(this->lblAppSubtitle);
			this->pnlHeader->Controls->Add(this->lblUserBadge);
			this->pnlHeader->Controls->Add(this->lblDateBadge);
			this->pnlHeader->Controls->Add(this->btnHeaderRefresh);
			this->pnlHeader->Controls->Add(this->btnHeaderLogout);
			this->pnlHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlHeader->Location = System::Drawing::Point(0, 29);
			this->pnlHeader->Name = L"pnlHeader";
			this->pnlHeader->Padding = System::Windows::Forms::Padding(24, 12, 24, 12);
			this->pnlHeader->Size = System::Drawing::Size(1260, 82);
			this->pnlHeader->TabIndex = 3;
			// 
			// lblAppTitle
			// 
			this->lblAppTitle->AutoSize = true;
			this->lblAppTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblAppTitle->ForeColor = System::Drawing::Color::White;
			this->lblAppTitle->Location = System::Drawing::Point(24, 14);
			this->lblAppTitle->Name = L"lblAppTitle";
			this->lblAppTitle->Size = System::Drawing::Size(430, 30);
			this->lblAppTitle->TabIndex = 0;
			this->lblAppTitle->Text = L"RENT-A-TOOL MANAGEMENT CONSOLE";
			// 
			// lblAppSubtitle
			// 
			this->lblAppSubtitle->AutoSize = true;
			this->lblAppSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->lblAppSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(225)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->lblAppSubtitle->Location = System::Drawing::Point(26, 46);
			this->lblAppSubtitle->Name = L"lblAppSubtitle";
			this->lblAppSubtitle->Size = System::Drawing::Size(465, 17);
			this->lblAppSubtitle->TabIndex = 1;
			this->lblAppSubtitle->Text = L"Real-time overview of active rentals, inventory availability, returns, and revenu"
				L"e";
			// 
			// lblUserBadge
			// 
			this->lblUserBadge->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblUserBadge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->lblUserBadge->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->lblUserBadge->Location = System::Drawing::Point(730, 18);
			this->lblUserBadge->Name = L"lblUserBadge";
			this->lblUserBadge->Size = System::Drawing::Size(285, 20);
			this->lblUserBadge->TabIndex = 2;
			this->lblUserBadge->Text = L"User: Chukka Fernando (Admin)";
			this->lblUserBadge->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblDateBadge
			// 
			this->lblDateBadge->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblDateBadge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblDateBadge->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->lblDateBadge->Location = System::Drawing::Point(730, 42);
			this->lblDateBadge->Name = L"lblDateBadge";
			this->lblDateBadge->Size = System::Drawing::Size(285, 20);
			this->lblDateBadge->TabIndex = 3;
			this->lblDateBadge->Text = L"Today";
			this->lblDateBadge->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// btnHeaderRefresh
			// 
			this->btnHeaderRefresh->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnHeaderRefresh->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->btnHeaderRefresh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnHeaderRefresh->FlatAppearance->BorderSize = 0;
			this->btnHeaderRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHeaderRefresh->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnHeaderRefresh->ForeColor = System::Drawing::Color::White;
			this->btnHeaderRefresh->Location = System::Drawing::Point(1030, 24);
			this->btnHeaderRefresh->Name = L"btnHeaderRefresh";
			this->btnHeaderRefresh->Size = System::Drawing::Size(105, 32);
			this->btnHeaderRefresh->TabIndex = 4;
			this->btnHeaderRefresh->Text = L"Refresh Data";
			this->btnHeaderRefresh->UseVisualStyleBackColor = false;
			this->btnHeaderRefresh->Click += gcnew System::EventHandler(this, &dashboard::menuRefresh_Click);
			// 
			// btnHeaderLogout
			// 
			this->btnHeaderLogout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnHeaderLogout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->btnHeaderLogout->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnHeaderLogout->FlatAppearance->BorderSize = 0;
			this->btnHeaderLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHeaderLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnHeaderLogout->ForeColor = System::Drawing::Color::White;
			this->btnHeaderLogout->Location = System::Drawing::Point(1145, 24);
			this->btnHeaderLogout->Name = L"btnHeaderLogout";
			this->btnHeaderLogout->Size = System::Drawing::Size(85, 32);
			this->btnHeaderLogout->TabIndex = 5;
			this->btnHeaderLogout->Text = L"Log Out";
			this->btnHeaderLogout->UseVisualStyleBackColor = false;
			this->btnHeaderLogout->Click += gcnew System::EventHandler(this, &dashboard::menuLogout_Click);
			// 
			// pnlActions
			// 
			this->pnlActions->BackColor = System::Drawing::Color::White;
			this->pnlActions->Controls->Add(this->btnActNewRental);
			this->pnlActions->Controls->Add(this->btnActReturn);
			this->pnlActions->Controls->Add(this->btnActTools);
			this->pnlActions->Controls->Add(this->btnActCustomers);
			this->pnlActions->Controls->Add(this->btnActSettings);
			this->pnlActions->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlActions->Location = System::Drawing::Point(0, 111);
			this->pnlActions->Name = L"pnlActions";
			this->pnlActions->Padding = System::Windows::Forms::Padding(24, 10, 24, 10);
			this->pnlActions->Size = System::Drawing::Size(1260, 56);
			this->pnlActions->TabIndex = 2;
			// 
			// btnActNewRental
			// 
			this->btnActNewRental->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->btnActNewRental->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActNewRental->FlatAppearance->BorderSize = 0;
			this->btnActNewRental->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActNewRental->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->btnActNewRental->ForeColor = System::Drawing::Color::White;
			this->btnActNewRental->Location = System::Drawing::Point(24, 10);
			this->btnActNewRental->Name = L"btnActNewRental";
			this->btnActNewRental->Size = System::Drawing::Size(170, 36);
			this->btnActNewRental->TabIndex = 0;
			this->btnActNewRental->Text = L"+ Issue New Rental";
			this->btnActNewRental->UseVisualStyleBackColor = false;
			this->btnActNewRental->Click += gcnew System::EventHandler(this, &dashboard::openRentalsNew_Click);
			// 
			// btnActReturn
			// 
			this->btnActReturn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(126)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)));
			this->btnActReturn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActReturn->FlatAppearance->BorderSize = 0;
			this->btnActReturn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActReturn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->btnActReturn->ForeColor = System::Drawing::Color::White;
			this->btnActReturn->Location = System::Drawing::Point(204, 10);
			this->btnActReturn->Name = L"btnActReturn";
			this->btnActReturn->Size = System::Drawing::Size(150, 36);
			this->btnActReturn->TabIndex = 1;
			this->btnActReturn->Text = L"Process Return";
			this->btnActReturn->UseVisualStyleBackColor = false;
			this->btnActReturn->Click += gcnew System::EventHandler(this, &dashboard::openRentalsReturn_Click);
			// 
			// btnActTools
			// 
			this->btnActTools->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->btnActTools->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActTools->FlatAppearance->BorderSize = 0;
			this->btnActTools->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActTools->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->btnActTools->ForeColor = System::Drawing::Color::White;
			this->btnActTools->Location = System::Drawing::Point(364, 10);
			this->btnActTools->Name = L"btnActTools";
			this->btnActTools->Size = System::Drawing::Size(150, 36);
			this->btnActTools->TabIndex = 2;
			this->btnActTools->Text = L"Tool Inventory";
			this->btnActTools->UseVisualStyleBackColor = false;
			this->btnActTools->Click += gcnew System::EventHandler(this, &dashboard::openInventory_Click);
			// 
			// btnActCustomers
			// 
			this->btnActCustomers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(152)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->btnActCustomers->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActCustomers->FlatAppearance->BorderSize = 0;
			this->btnActCustomers->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActCustomers->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->btnActCustomers->ForeColor = System::Drawing::Color::White;
			this->btnActCustomers->Location = System::Drawing::Point(524, 10);
			this->btnActCustomers->Name = L"btnActCustomers";
			this->btnActCustomers->Size = System::Drawing::Size(160, 36);
			this->btnActCustomers->TabIndex = 3;
			this->btnActCustomers->Text = L"Customer Directory";
			this->btnActCustomers->UseVisualStyleBackColor = false;
			this->btnActCustomers->Click += gcnew System::EventHandler(this, &dashboard::openCustomers_Click);
			// 
			// btnActSettings
			// 
			this->btnActSettings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(108)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)));
			this->btnActSettings->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnActSettings->FlatAppearance->BorderSize = 0;
			this->btnActSettings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnActSettings->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
			this->btnActSettings->ForeColor = System::Drawing::Color::White;
			this->btnActSettings->Location = System::Drawing::Point(694, 10);
			this->btnActSettings->Name = L"btnActSettings";
			this->btnActSettings->Size = System::Drawing::Size(150, 36);
			this->btnActSettings->TabIndex = 4;
			this->btnActSettings->Text = L"Settings & Users";
			this->btnActSettings->UseVisualStyleBackColor = false;
			this->btnActSettings->Click += gcnew System::EventHandler(this, &dashboard::openSettings_Click);
			// 
			// pnlKpiContainer
			// 
			this->pnlKpiContainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->pnlKpiContainer->Controls->Add(this->cardActiveRentals);
			this->pnlKpiContainer->Controls->Add(this->cardOverdue);
			this->pnlKpiContainer->Controls->Add(this->cardTools);
			this->pnlKpiContainer->Controls->Add(this->cardRevenue);
			this->pnlKpiContainer->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlKpiContainer->Location = System::Drawing::Point(0, 167);
			this->pnlKpiContainer->Name = L"pnlKpiContainer";
			this->pnlKpiContainer->Padding = System::Windows::Forms::Padding(24, 14, 24, 14);
			this->pnlKpiContainer->Size = System::Drawing::Size(1260, 120);
			this->pnlKpiContainer->TabIndex = 1;
			// 
			// cardActiveRentals
			// 
			this->cardActiveRentals->BackColor = System::Drawing::Color::White;
			this->cardActiveRentals->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cardActiveRentals->Controls->Add(this->lblCard1Title);
			this->cardActiveRentals->Controls->Add(this->lblCard1Value);
			this->cardActiveRentals->Controls->Add(this->lblCard1Sub);
			this->cardActiveRentals->Location = System::Drawing::Point(24, 14);
			this->cardActiveRentals->Name = L"cardActiveRentals";
			this->cardActiveRentals->Size = System::Drawing::Size(282, 92);
			this->cardActiveRentals->TabIndex = 0;
			// 
			// lblCard1Title
			// 
			this->lblCard1Title->AutoSize = true;
			this->lblCard1Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold));
			this->lblCard1Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->lblCard1Title->Location = System::Drawing::Point(16, 12);
			this->lblCard1Title->Name = L"lblCard1Title";
			this->lblCard1Title->Size = System::Drawing::Size(94, 13);
			this->lblCard1Title->TabIndex = 0;
			this->lblCard1Title->Text = L"ACTIVE RENTALS";
			// 
			// lblCard1Value
			// 
			this->lblCard1Value->AutoSize = true;
			this->lblCard1Value->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22, System::Drawing::FontStyle::Bold));
			this->lblCard1Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->lblCard1Value->Location = System::Drawing::Point(14, 28);
			this->lblCard1Value->Name = L"lblCard1Value";
			this->lblCard1Value->Size = System::Drawing::Size(35, 41);
			this->lblCard1Value->TabIndex = 1;
			this->lblCard1Value->Text = L"0";
			// 
			// lblCard1Sub
			// 
			this->lblCard1Sub->AutoSize = true;
			this->lblCard1Sub->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F));
			this->lblCard1Sub->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)));
			this->lblCard1Sub->Location = System::Drawing::Point(16, 68);
			this->lblCard1Sub->Name = L"lblCard1Sub";
			this->lblCard1Sub->Size = System::Drawing::Size(90, 15);
			this->lblCard1Sub->TabIndex = 2;
			this->lblCard1Sub->Text = L"Rentals today: 0";
			// 
			// cardOverdue
			// 
			this->cardOverdue->BackColor = System::Drawing::Color::White;
			this->cardOverdue->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cardOverdue->Controls->Add(this->lblCard2Title);
			this->cardOverdue->Controls->Add(this->lblCard2Value);
			this->cardOverdue->Controls->Add(this->lblCard2Sub);
			this->cardOverdue->Location = System::Drawing::Point(330, 14);
			this->cardOverdue->Name = L"cardOverdue";
			this->cardOverdue->Size = System::Drawing::Size(282, 92);
			this->cardOverdue->TabIndex = 1;
			// 
			// lblCard2Title
			// 
			this->lblCard2Title->AutoSize = true;
			this->lblCard2Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold));
			this->lblCard2Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->lblCard2Title->Location = System::Drawing::Point(16, 12);
			this->lblCard2Title->Name = L"lblCard2Title";
			this->lblCard2Title->Size = System::Drawing::Size(109, 13);
			this->lblCard2Title->TabIndex = 0;
			this->lblCard2Title->Text = L"OVERDUE RETURNS";
			// 
			// lblCard2Value
			// 
			this->lblCard2Value->AutoSize = true;
			this->lblCard2Value->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22, System::Drawing::FontStyle::Bold));
			this->lblCard2Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->lblCard2Value->Location = System::Drawing::Point(14, 28);
			this->lblCard2Value->Name = L"lblCard2Value";
			this->lblCard2Value->Size = System::Drawing::Size(35, 41);
			this->lblCard2Value->TabIndex = 1;
			this->lblCard2Value->Text = L"0";
			// 
			// lblCard2Sub
			// 
			this->lblCard2Sub->AutoSize = true;
			this->lblCard2Sub->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F));
			this->lblCard2Sub->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)));
			this->lblCard2Sub->Location = System::Drawing::Point(16, 68);
			this->lblCard2Sub->Name = L"lblCard2Sub";
			this->lblCard2Sub->Size = System::Drawing::Size(107, 15);
			this->lblCard2Sub->TabIndex = 2;
			this->lblCard2Sub->Text = L"Requires follow-up";
			// 
			// cardTools
			// 
			this->cardTools->BackColor = System::Drawing::Color::White;
			this->cardTools->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cardTools->Controls->Add(this->lblCard3Title);
			this->cardTools->Controls->Add(this->lblCard3Value);
			this->cardTools->Controls->Add(this->lblCard3Sub);
			this->cardTools->Location = System::Drawing::Point(636, 14);
			this->cardTools->Name = L"cardTools";
			this->cardTools->Size = System::Drawing::Size(282, 92);
			this->cardTools->TabIndex = 2;
			// 
			// lblCard3Title
			// 
			this->lblCard3Title->AutoSize = true;
			this->lblCard3Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold));
			this->lblCard3Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->lblCard3Title->Location = System::Drawing::Point(16, 12);
			this->lblCard3Title->Name = L"lblCard3Title";
			this->lblCard3Title->Size = System::Drawing::Size(108, 13);
			this->lblCard3Title->TabIndex = 0;
			this->lblCard3Title->Text = L"TOOL AVAILABILITY";
			// 
			// lblCard3Value
			// 
			this->lblCard3Value->AutoSize = true;
			this->lblCard3Value->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22, System::Drawing::FontStyle::Bold));
			this->lblCard3Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(39)), static_cast<System::Int32>(static_cast<System::Byte>(174)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->lblCard3Value->Location = System::Drawing::Point(14, 28);
			this->lblCard3Value->Name = L"lblCard3Value";
			this->lblCard3Value->Size = System::Drawing::Size(35, 41);
			this->lblCard3Value->TabIndex = 1;
			this->lblCard3Value->Text = L"0";
			// 
			// lblCard3Sub
			// 
			this->lblCard3Sub->AutoSize = true;
			this->lblCard3Sub->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F));
			this->lblCard3Sub->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)));
			this->lblCard3Sub->Location = System::Drawing::Point(16, 68);
			this->lblCard3Sub->Name = L"lblCard3Sub";
			this->lblCard3Sub->Size = System::Drawing::Size(146, 15);
			this->lblCard3Sub->TabIndex = 2;
			this->lblCard3Sub->Text = L"Rented: 0 | Maintenance: 0";
			// 
			// cardRevenue
			// 
			this->cardRevenue->BackColor = System::Drawing::Color::White;
			this->cardRevenue->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->cardRevenue->Controls->Add(this->lblCard4Title);
			this->cardRevenue->Controls->Add(this->lblCard4Value);
			this->cardRevenue->Controls->Add(this->lblCard4Sub);
			this->cardRevenue->Location = System::Drawing::Point(942, 14);
			this->cardRevenue->Name = L"cardRevenue";
			this->cardRevenue->Size = System::Drawing::Size(294, 92);
			this->cardRevenue->TabIndex = 3;
			// 
			// lblCard4Title
			// 
			this->lblCard4Title->AutoSize = true;
			this->lblCard4Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold));
			this->lblCard4Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->lblCard4Title->Location = System::Drawing::Point(16, 12);
			this->lblCard4Title->Name = L"lblCard4Title";
			this->lblCard4Title->Size = System::Drawing::Size(92, 13);
			this->lblCard4Title->TabIndex = 0;
			this->lblCard4Title->Text = L"TOTAL REVENUE";
			// 
			// lblCard4Value
			// 
			this->lblCard4Value->AutoSize = true;
			this->lblCard4Value->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblCard4Value->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->lblCard4Value->Location = System::Drawing::Point(14, 29);
			this->lblCard4Value->Name = L"lblCard4Value";
			this->lblCard4Value->Size = System::Drawing::Size(129, 37);
			this->lblCard4Value->TabIndex = 1;
			this->lblCard4Value->Text = L"LKR 0.00";
			// 
			// lblCard4Sub
			// 
			this->lblCard4Sub->AutoSize = true;
			this->lblCard4Sub->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F));
			this->lblCard4Sub->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(135)),
				static_cast<System::Int32>(static_cast<System::Byte>(145)));
			this->lblCard4Sub->Location = System::Drawing::Point(16, 68);
			this->lblCard4Sub->Name = L"lblCard4Sub";
			this->lblCard4Sub->Size = System::Drawing::Size(128, 15);
			this->lblCard4Sub->TabIndex = 2;
			this->lblCard4Sub->Text = L"Deposits held: LKR 0.00";
			// 
			// splitMain
			// 
			this->splitMain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->splitMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitMain->Location = System::Drawing::Point(0, 287);
			this->splitMain->Name = L"splitMain";
			// 
			// splitMain.Panel1
			// 
			this->splitMain->Panel1->Controls->Add(this->pnlChartContainer);
			// 
			// splitMain.Panel2
			// 
			this->splitMain->Panel2->Controls->Add(this->pnlRecentContainer);
			this->splitMain->Size = System::Drawing::Size(1260, 493);
			this->splitMain->SplitterDistance = 600;
			this->splitMain->TabIndex = 0;
			// 
			// pnlChartContainer
			// 
			this->pnlChartContainer->BackColor = System::Drawing::Color::White;
			this->pnlChartContainer->Controls->Add(this->chartInventory);
			this->pnlChartContainer->Controls->Add(this->lblChartHeader);
			this->pnlChartContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlChartContainer->Location = System::Drawing::Point(0, 0);
			this->pnlChartContainer->Name = L"pnlChartContainer";
			this->pnlChartContainer->Padding = System::Windows::Forms::Padding(16);
			this->pnlChartContainer->Size = System::Drawing::Size(600, 493);
			this->pnlChartContainer->TabIndex = 0;
			// 
			// chartInventory
			// 
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			chartArea1->BackColor = System::Drawing::Color::White;
			chartArea1->Name = L"MainArea";
			this->chartInventory->ChartAreas->Add(chartArea1);
			this->chartInventory->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend1->Name = L"MainLegend";
			this->chartInventory->Legends->Add(legend1);
			this->chartInventory->Location = System::Drawing::Point(16, 48);
			this->chartInventory->Name = L"chartInventory";
			series1->ChartArea = L"MainArea";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			series1->IsValueShownAsLabel = true;
			series1->Legend = L"MainLegend";
			series1->Name = L"Categories";
			this->chartInventory->Series->Add(series1);
			this->chartInventory->Size = System::Drawing::Size(568, 429);
			this->chartInventory->TabIndex = 0;
			this->chartInventory->Click += gcnew System::EventHandler(this, &dashboard::chartInventory_Click);
			// 
			// lblChartHeader
			// 
			this->lblChartHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblChartHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblChartHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(79)),
				static_cast<System::Int32>(static_cast<System::Byte>(79)));
			this->lblChartHeader->Location = System::Drawing::Point(16, 16);
			this->lblChartHeader->Name = L"lblChartHeader";
			this->lblChartHeader->Size = System::Drawing::Size(568, 32);
			this->lblChartHeader->TabIndex = 1;
			this->lblChartHeader->Text = L"Tool Inventory by Category";
			// 
			// pnlRecentContainer
			// 
			this->pnlRecentContainer->BackColor = System::Drawing::Color::White;
			this->pnlRecentContainer->Controls->Add(this->pnlRecentHeaderTop);
			this->pnlRecentContainer->Controls->Add(this->dgvRecentRentals);
			this->pnlRecentContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlRecentContainer->Location = System::Drawing::Point(0, 0);
			this->pnlRecentContainer->Name = L"pnlRecentContainer";
			this->pnlRecentContainer->Size = System::Drawing::Size(656, 493);
			this->pnlRecentContainer->TabIndex = 0;
			// 
			// pnlRecentHeaderTop
			// 
			this->pnlRecentHeaderTop->Controls->Add(this->lblRecentSubtitle);
			this->pnlRecentHeaderTop->Controls->Add(this->lblRecentHeader);
			this->pnlRecentHeaderTop->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlRecentHeaderTop->Location = System::Drawing::Point(0, 0);
			this->pnlRecentHeaderTop->Name = L"pnlRecentHeaderTop";
			this->pnlRecentHeaderTop->Padding = System::Windows::Forms::Padding(12, 6, 0, 0);
			this->pnlRecentHeaderTop->Size = System::Drawing::Size(656, 60);
			this->pnlRecentHeaderTop->TabIndex = 2;
			// 
			// lblRecentSubtitle
			// 
			this->lblRecentSubtitle->AutoSize = true;
			this->lblRecentSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F));
			this->lblRecentSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(141)));
			this->lblRecentSubtitle->Location = System::Drawing::Point(1, 24);
			this->lblRecentSubtitle->Name = L"lblRecentSubtitle";
			this->lblRecentSubtitle->Size = System::Drawing::Size(313, 15);
			this->lblRecentSubtitle->TabIndex = 1;
			this->lblRecentSubtitle->Text = L"Latest transactions, customer assignments & return statuses";
			// 
			// lblRecentHeader
			// 
			this->lblRecentHeader->AutoSize = true;
			this->lblRecentHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12.5F, System::Drawing::FontStyle::Bold));
			this->lblRecentHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblRecentHeader->Location = System::Drawing::Point(0, 0);
			this->lblRecentHeader->Name = L"lblRecentHeader";
			this->lblRecentHeader->Size = System::Drawing::Size(187, 23);
			this->lblRecentHeader->TabIndex = 0;
			this->lblRecentHeader->Text = L"Recent Rental Activity";
			// 
			// dgvRecentRentals
			// 
			this->dgvRecentRentals->AllowUserToAddRows = false;
			this->dgvRecentRentals->AllowUserToDeleteRows = false;
			this->dgvRecentRentals->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvRecentRentals->BackgroundColor = System::Drawing::Color::White;
			this->dgvRecentRentals->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgvRecentRentals->Location = System::Drawing::Point(0, 60);
			this->dgvRecentRentals->Name = L"dgvRecentRentals";
			this->dgvRecentRentals->ReadOnly = true;
			this->dgvRecentRentals->RowHeadersVisible = false;
			this->dgvRecentRentals->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvRecentRentals->Size = System::Drawing::Size(624, 438);
			this->dgvRecentRentals->TabIndex = 0;
			this->dgvRecentRentals->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &dashboard::dgvRecent_CellFormatting);
			this->dgvRecentRentals->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &dashboard::dgvRecent_DataError);
			// 
			// dashboard
			// 
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(1260, 780);
			this->Controls->Add(this->splitMain);
			this->Controls->Add(this->pnlKpiContainer);
			this->Controls->Add(this->pnlActions);
			this->Controls->Add(this->pnlHeader);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(1100, 700);
			this->Name = L"dashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rent-A-Tool - Master Dashboard";
			this->Load += gcnew System::EventHandler(this, &dashboard::dashboard_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->pnlHeader->ResumeLayout(false);
			this->pnlHeader->PerformLayout();
			this->pnlActions->ResumeLayout(false);
			this->pnlKpiContainer->ResumeLayout(false);
			this->cardActiveRentals->ResumeLayout(false);
			this->cardActiveRentals->PerformLayout();
			this->cardOverdue->ResumeLayout(false);
			this->cardOverdue->PerformLayout();
			this->cardTools->ResumeLayout(false);
			this->cardTools->PerformLayout();
			this->cardRevenue->ResumeLayout(false);
			this->cardRevenue->PerformLayout();
			this->splitMain->Panel1->ResumeLayout(false);
			this->splitMain->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitMain))->EndInit();
			this->splitMain->ResumeLayout(false);
			this->pnlChartContainer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartInventory))->EndInit();
			this->pnlRecentContainer->ResumeLayout(false);
			this->pnlRecentHeaderTop->ResumeLayout(false);
			this->pnlRecentHeaderTop->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRecentRentals))->EndInit();
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

			// Set window icon from assets folder (next to exe)
			try {
				String^ exeDir = System::IO::Path::GetDirectoryName(System::Windows::Forms::Application::ExecutablePath);
				String^ iconPath = System::IO::Path::Combine(exeDir, L"assets\\icon.ico");
				if (System::IO::File::Exists(iconPath)) {
					this->Icon = gcnew System::Drawing::Icon(iconPath);
				}
			} catch (Exception^) {}

			try {
				String^ userName = CurrentUser::FullName != nullptr ? CurrentUser::FullName : "Chukka Fernando";
				String^ role = CurrentUser::Role != nullptr ? CurrentUser::Role : "Admin";
				this->lblUserBadge->Text = String::Format("User: {0} ({1})", userName, role);
				this->lblDateBadge->Text = DateTime::Now.ToString("dddd, MMMM dd, yyyy");
			} catch (Exception^) {}

			// Dynamically fit the DataGridView below the header panel
			try {
				int headerH = pnlRecentHeaderTop->Height;
				dgvRecentRentals->Location = System::Drawing::Point(0, headerH);
				dgvRecentRentals->Size = System::Drawing::Size(
					pnlRecentContainer->ClientSize.Width,
					pnlRecentContainer->ClientSize.Height - headerH);
			} catch (Exception^) {}

			// Wire up resize so grid always fills space below header
			pnlRecentContainer->Resize += gcnew System::EventHandler(this, &dashboard::pnlRecentContainer_Resize);

			try {
				RefreshDashboardData();
			} catch (Exception^) {}
		}

		void pnlRecentContainer_Resize(System::Object^ sender, System::EventArgs^ e)
		{
			try {
				int headerH = pnlRecentHeaderTop->Height;
				dgvRecentRentals->Location = System::Drawing::Point(0, headerH);
				dgvRecentRentals->Size = System::Drawing::Size(
					pnlRecentContainer->ClientSize.Width,
					pnlRecentContainer->ClientSize.Height - headerH);
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
			this->chartInventory->Refresh();

			// 3. Populate Recent Rentals Grid
			DataTable^ dtRecent = Data::DashboardService::GetRecentRentals(10);
			this->dgvRecentRentals->DataSource = dtRecent;
			this->dgvRecentRentals->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvRecentRentals->ColumnHeadersVisible = true;
			this->dgvRecentRentals->EnableHeadersVisualStyles = false;
			this->dgvRecentRentals->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dgvRecentRentals->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(38, 64, 64);
			this->dgvRecentRentals->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			this->dgvRecentRentals->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold);
			this->dgvRecentRentals->ColumnHeadersDefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			this->dgvRecentRentals->ColumnHeadersHeight = 36;
			this->dgvRecentRentals->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dgvRecentRentals->RowTemplate->Height = 30;
			this->dgvRecentRentals->GridColor = System::Drawing::Color::FromArgb(230, 235, 240);
			this->dgvRecentRentals->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(248, 250, 252);
			this->dgvRecentRentals->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(52, 152, 219);
			this->dgvRecentRentals->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dgvRecentRentals->DefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular);

			if (this->dgvRecentRentals->Columns->Contains("rental_code")) {
				this->dgvRecentRentals->Columns["rental_code"]->HeaderText = L"Rental Code";
				this->dgvRecentRentals->Columns["rental_code"]->FillWeight = 85;
			}
			if (this->dgvRecentRentals->Columns->Contains("customer_name")) {
				this->dgvRecentRentals->Columns["customer_name"]->HeaderText = L"Customer Name";
				this->dgvRecentRentals->Columns["customer_name"]->FillWeight = 115;
			}
			if (this->dgvRecentRentals->Columns->Contains("tool_name")) {
				this->dgvRecentRentals->Columns["tool_name"]->HeaderText = L"Tool";
				this->dgvRecentRentals->Columns["tool_name"]->FillWeight = 110;
			}
			if (this->dgvRecentRentals->Columns->Contains("rent_date")) {
				this->dgvRecentRentals->Columns["rent_date"]->HeaderText = L"Rented Date";
				this->dgvRecentRentals->Columns["rent_date"]->DefaultCellStyle->Format = L"yyyy-MM-dd";
				this->dgvRecentRentals->Columns["rent_date"]->FillWeight = 85;
			}
			if (this->dgvRecentRentals->Columns->Contains("due_date")) {
				this->dgvRecentRentals->Columns["due_date"]->HeaderText = L"Due Date";
				this->dgvRecentRentals->Columns["due_date"]->DefaultCellStyle->Format = L"yyyy-MM-dd";
				this->dgvRecentRentals->Columns["due_date"]->FillWeight = 85;
			}
			if (this->dgvRecentRentals->Columns->Contains("status")) {
				this->dgvRecentRentals->Columns["status"]->HeaderText = L"Status";
				this->dgvRecentRentals->Columns["status"]->FillWeight = 75;
			}
			if (this->dgvRecentRentals->Columns->Contains("deposit_paid")) {
				this->dgvRecentRentals->Columns["deposit_paid"]->HeaderText = L"Deposit (LKR)";
				this->dgvRecentRentals->Columns["deposit_paid"]->DefaultCellStyle->Format = L"N2";
				this->dgvRecentRentals->Columns["deposit_paid"]->FillWeight = 85;
				this->dgvRecentRentals->Columns["deposit_paid"]->Visible = true;
			}
			if (this->dgvRecentRentals->Columns->Contains("total_amount")) {
				this->dgvRecentRentals->Columns["total_amount"]->HeaderText = L"Total (LKR)";
				this->dgvRecentRentals->Columns["total_amount"]->DefaultCellStyle->Format = L"N2";
				this->dgvRecentRentals->Columns["total_amount"]->FillWeight = 85;
				this->dgvRecentRentals->Columns["total_amount"]->Visible = true;
			}
			this->dgvRecentRentals->Refresh();
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

		void openRentalsNew_Click(System::Object^ sender, System::EventArgs^ e)
		{
			rentals^ rentForm = gcnew rentals();
			rentForm->SelectNewRentalTab();
			rentForm->ShowDialog(this);
			RefreshDashboardData();
		}

		void openRentalsReturn_Click(System::Object^ sender, System::EventArgs^ e)
		{
			rentals^ rentForm = gcnew rentals();
			rentForm->SelectRentalsListTab();
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
	private: System::Void chartInventory_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
