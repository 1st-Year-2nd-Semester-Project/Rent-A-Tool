#pragma once
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

		// UI Controls
		Panel^ pnlHeader;
		Label^ lblTitle;
		Label^ lblSubtitle;

		Panel^ pnlFilter;
		Label^ lblSearch;
		TextBox^ txtSearch;
		Label^ lblCatFilter;
		ComboBox^ cmbCatFilter;
		Label^ lblStatFilter;
		ComboBox^ cmbStatFilter;
		Button^ btnRefresh;

		DataGridView^ dgvTools;

		Panel^ pnlEditor;
		Label^ lblEditorTitle;
		Label^ lblCode;
		TextBox^ txtCode;
		Label^ lblName;
		TextBox^ txtName;
		Label^ lblCategory;
		ComboBox^ cmbCategory;
		Label^ lblDailyRate;
		NumericUpDown^ numDailyRate;
		Label^ lblDeposit;
		NumericUpDown^ numDeposit;
		Label^ lblStatus;
		ComboBox^ cmbStatus;
		Label^ lblBrand;
		TextBox^ txtBrand;
		Label^ lblModel;
		TextBox^ txtModel;

		Button^ btnAdd;
		Button^ btnUpdate;
		Button^ btnDelete;
		Button^ btnClear;
		Button^ btnClose;

		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->SuspendLayout();

			// Form properties
			this->Text = L"Rent-A-Tool - Inventory Management";
			this->ClientSize = System::Drawing::Size(1150, 680);
			this->MinimumSize = System::Drawing::Size(1000, 600);
			this->StartPosition = FormStartPosition::CenterScreen;
			this->BackColor = Color::FromArgb(244, 246, 249);
			this->Font = gcnew Drawing::Font(L"Segoe UI", 10);

			// Header Panel
			pnlHeader = gcnew Panel();
			pnlHeader->Dock = DockStyle::Top;
			pnlHeader->Height = 70;
			pnlHeader->BackColor = Color::FromArgb(47, 79, 79); // DarkSlateGray

			lblTitle = gcnew Label();
			lblTitle->Text = L"TOOL INVENTORY MANAGEMENT";
			lblTitle->Font = gcnew Drawing::Font(L"Segoe UI", 16, FontStyle::Bold);
			lblTitle->ForeColor = Color::White;
			lblTitle->Location = Point(20, 12);
			lblTitle->AutoSize = true;

			lblSubtitle = gcnew Label();
			lblSubtitle->Text = L"Add, edit, track and manage rental tools, daily rates, and status";
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
			btnClose->Location = Point(980, 18);
			btnClose->Size = System::Drawing::Size(150, 35);
			btnClose->Anchor = AnchorStyles::Top | AnchorStyles::Right;
			btnClose->Cursor = Cursors::Hand;
			btnClose->Click += gcnew EventHandler(this, &inventory::btnClose_Click);

			pnlHeader->Controls->Add(lblTitle);
			pnlHeader->Controls->Add(lblSubtitle);
			pnlHeader->Controls->Add(btnClose);

			// Filter Bar Panel
			pnlFilter = gcnew Panel();
			pnlFilter->Dock = DockStyle::Top;
			pnlFilter->Height = 55;
			pnlFilter->BackColor = Color::White;
			pnlFilter->Padding = System::Windows::Forms::Padding(20, 10, 20, 10);

			lblSearch = gcnew Label();
			lblSearch->Text = L"Search:";
			lblSearch->Location = Point(20, 16);
			lblSearch->AutoSize = true;
			lblSearch->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			txtSearch = gcnew TextBox();
			txtSearch->Location = Point(75, 13);
			txtSearch->Size = System::Drawing::Size(220, 25);
			txtSearch->TextChanged += gcnew EventHandler(this, &inventory::FilterChanged);

			lblCatFilter = gcnew Label();
			lblCatFilter->Text = L"Category:";
			lblCatFilter->Location = Point(315, 16);
			lblCatFilter->AutoSize = true;
			lblCatFilter->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			cmbCatFilter = gcnew ComboBox();
			cmbCatFilter->DropDownStyle = ComboBoxStyle::DropDownList;
			cmbCatFilter->Location = Point(385, 13);
			cmbCatFilter->Size = System::Drawing::Size(150, 25);
			cmbCatFilter->SelectedIndexChanged += gcnew EventHandler(this, &inventory::FilterChanged);

			lblStatFilter = gcnew Label();
			lblStatFilter->Text = L"Status:";
			lblStatFilter->Location = Point(555, 16);
			lblStatFilter->AutoSize = true;
			lblStatFilter->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			cmbStatFilter = gcnew ComboBox();
			cmbStatFilter->DropDownStyle = ComboBoxStyle::DropDownList;
			cmbStatFilter->Items->AddRange(gcnew cli::array<Object^>{ L"All", L"Available", L"Rented", L"Maintenance" });
			cmbStatFilter->SelectedIndex = 0;
			cmbStatFilter->Location = Point(610, 13);
			cmbStatFilter->Size = System::Drawing::Size(120, 25);
			cmbStatFilter->SelectedIndexChanged += gcnew EventHandler(this, &inventory::FilterChanged);

			btnRefresh = gcnew Button();
			btnRefresh->Text = L"Refresh";
			btnRefresh->Location = Point(745, 12);
			btnRefresh->Size = System::Drawing::Size(90, 28);
			btnRefresh->BackColor = Color::FromArgb(52, 152, 219);
			btnRefresh->ForeColor = Color::White;
			btnRefresh->FlatStyle = FlatStyle::Flat;
			btnRefresh->FlatAppearance->BorderSize = 0;
			btnRefresh->Cursor = Cursors::Hand;
			btnRefresh->Click += gcnew EventHandler(this, &inventory::btnRefresh_Click);

			pnlFilter->Controls->Add(lblSearch);
			pnlFilter->Controls->Add(txtSearch);
			pnlFilter->Controls->Add(lblCatFilter);
			pnlFilter->Controls->Add(cmbCatFilter);
			pnlFilter->Controls->Add(lblStatFilter);
			pnlFilter->Controls->Add(cmbStatFilter);
			pnlFilter->Controls->Add(btnRefresh);

			// Right Editor Panel
			pnlEditor = gcnew Panel();
			pnlEditor->Dock = DockStyle::Right;
			pnlEditor->Width = 340;
			pnlEditor->BackColor = Color::White;
			pnlEditor->Padding = System::Windows::Forms::Padding(20);

			lblEditorTitle = gcnew Label();
			lblEditorTitle->Text = L"Tool Details";
			lblEditorTitle->Font = gcnew Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblEditorTitle->ForeColor = Color::FromArgb(47, 79, 79);
			lblEditorTitle->Location = Point(20, 15);
			lblEditorTitle->AutoSize = true;

			int curY = 55;
			lblCode = gcnew Label();
			lblCode->Text = L"Tool Code:";
			lblCode->Location = Point(20, curY);
			lblCode->AutoSize = true;
			txtCode = gcnew TextBox();
			txtCode->Location = Point(20, curY + 20);
			txtCode->Size = System::Drawing::Size(295, 25);

			curY += 55;
			lblName = gcnew Label();
			lblName->Text = L"Tool Name:";
			lblName->Location = Point(20, curY);
			lblName->AutoSize = true;
			txtName = gcnew TextBox();
			txtName->Location = Point(20, curY + 20);
			txtName->Size = System::Drawing::Size(295, 25);

			curY += 55;
			lblCategory = gcnew Label();
			lblCategory->Text = L"Category:";
			lblCategory->Location = Point(20, curY);
			lblCategory->AutoSize = true;
			cmbCategory = gcnew ComboBox();
			cmbCategory->Location = Point(20, curY + 20);
			cmbCategory->Size = System::Drawing::Size(295, 25);
			cmbCategory->Items->AddRange(gcnew cli::array<Object^>{ L"Power tools", L"Construction", L"Garden", L"Hand tools", L"Plumbing", L"Other" });
			cmbCategory->SelectedIndex = 0;

			curY += 55;
			lblDailyRate = gcnew Label();
			lblDailyRate->Text = L"Daily Rate (LKR):";
			lblDailyRate->Location = Point(20, curY);
			lblDailyRate->AutoSize = true;
			numDailyRate = gcnew NumericUpDown();
			numDailyRate->Location = Point(20, curY + 20);
			numDailyRate->Size = System::Drawing::Size(140, 25);
			numDailyRate->Maximum = 1000000;
			numDailyRate->DecimalPlaces = 2;

			lblDeposit = gcnew Label();
			lblDeposit->Text = L"Deposit (LKR):";
			lblDeposit->Location = Point(175, curY);
			lblDeposit->AutoSize = true;
			numDeposit = gcnew NumericUpDown();
			numDeposit->Location = Point(175, curY + 20);
			numDeposit->Size = System::Drawing::Size(140, 25);
			numDeposit->Maximum = 10000000;
			numDeposit->DecimalPlaces = 2;

			curY += 55;
			lblStatus = gcnew Label();
			lblStatus->Text = L"Status:";
			lblStatus->Location = Point(20, curY);
			lblStatus->AutoSize = true;
			cmbStatus = gcnew ComboBox();
			cmbStatus->DropDownStyle = ComboBoxStyle::DropDownList;
			cmbStatus->Items->AddRange(gcnew cli::array<Object^>{ L"Available", L"Rented", L"Maintenance" });
			cmbStatus->SelectedIndex = 0;
			cmbStatus->Location = Point(20, curY + 20);
			cmbStatus->Size = System::Drawing::Size(295, 25);

			curY += 55;
			lblBrand = gcnew Label();
			lblBrand->Text = L"Brand:";
			lblBrand->Location = Point(20, curY);
			lblBrand->AutoSize = true;
			txtBrand = gcnew TextBox();
			txtBrand->Location = Point(20, curY + 20);
			txtBrand->Size = System::Drawing::Size(140, 25);

			lblModel = gcnew Label();
			lblModel->Text = L"Model/Serial:";
			lblModel->Location = Point(175, curY);
			lblModel->AutoSize = true;
			txtModel = gcnew TextBox();
			txtModel->Location = Point(175, curY + 20);
			txtModel->Size = System::Drawing::Size(140, 25);

			// Action Buttons
			curY += 65;
			btnAdd = gcnew Button();
			btnAdd->Text = L"+ Add Tool";
			btnAdd->Location = Point(20, curY);
			btnAdd->Size = System::Drawing::Size(140, 36);
			btnAdd->BackColor = Color::FromArgb(39, 174, 96); // Green
			btnAdd->ForeColor = Color::White;
			btnAdd->FlatStyle = FlatStyle::Flat;
			btnAdd->FlatAppearance->BorderSize = 0;
			btnAdd->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnAdd->Cursor = Cursors::Hand;
			btnAdd->Click += gcnew EventHandler(this, &inventory::btnAdd_Click);

			btnUpdate = gcnew Button();
			btnUpdate->Text = L"Update";
			btnUpdate->Location = Point(175, curY);
			btnUpdate->Size = System::Drawing::Size(140, 36);
			btnUpdate->BackColor = Color::FromArgb(41, 128, 185); // Blue
			btnUpdate->ForeColor = Color::White;
			btnUpdate->FlatStyle = FlatStyle::Flat;
			btnUpdate->FlatAppearance->BorderSize = 0;
			btnUpdate->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnUpdate->Cursor = Cursors::Hand;
			btnUpdate->Click += gcnew EventHandler(this, &inventory::btnUpdate_Click);

			curY += 46;
			btnDelete = gcnew Button();
			btnDelete->Text = L"Delete";
			btnDelete->Location = Point(20, curY);
			btnDelete->Size = System::Drawing::Size(140, 34);
			btnDelete->BackColor = Color::FromArgb(231, 76, 60); // Red
			btnDelete->ForeColor = Color::White;
			btnDelete->FlatStyle = FlatStyle::Flat;
			btnDelete->FlatAppearance->BorderSize = 0;
			btnDelete->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnDelete->Cursor = Cursors::Hand;
			btnDelete->Click += gcnew EventHandler(this, &inventory::btnDelete_Click);

			btnClear = gcnew Button();
			btnClear->Text = L"Clear Form";
			btnClear->Location = Point(175, curY);
			btnClear->Size = System::Drawing::Size(140, 34);
			btnClear->BackColor = Color::FromArgb(149, 165, 166);
			btnClear->ForeColor = Color::White;
			btnClear->FlatStyle = FlatStyle::Flat;
			btnClear->FlatAppearance->BorderSize = 0;
			btnClear->Cursor = Cursors::Hand;
			btnClear->Click += gcnew EventHandler(this, &inventory::btnClear_Click);

			pnlEditor->Controls->Add(lblEditorTitle);
			pnlEditor->Controls->Add(lblCode);
			pnlEditor->Controls->Add(txtCode);
			pnlEditor->Controls->Add(lblName);
			pnlEditor->Controls->Add(txtName);
			pnlEditor->Controls->Add(lblCategory);
			pnlEditor->Controls->Add(cmbCategory);
			pnlEditor->Controls->Add(lblDailyRate);
			pnlEditor->Controls->Add(numDailyRate);
			pnlEditor->Controls->Add(lblDeposit);
			pnlEditor->Controls->Add(numDeposit);
			pnlEditor->Controls->Add(lblStatus);
			pnlEditor->Controls->Add(cmbStatus);
			pnlEditor->Controls->Add(lblBrand);
			pnlEditor->Controls->Add(txtBrand);
			pnlEditor->Controls->Add(lblModel);
			pnlEditor->Controls->Add(txtModel);
			pnlEditor->Controls->Add(btnAdd);
			pnlEditor->Controls->Add(btnUpdate);
			pnlEditor->Controls->Add(btnDelete);
			pnlEditor->Controls->Add(btnClear);

			// DataGridView Tools
			dgvTools = gcnew DataGridView();
			dgvTools->Dock = DockStyle::Fill;
			dgvTools->BackgroundColor = Color::FromArgb(244, 246, 249);
			dgvTools->BorderStyle = BorderStyle::None;
			dgvTools->AllowUserToAddRows = false;
			dgvTools->AllowUserToDeleteRows = false;
			dgvTools->ReadOnly = true;
			dgvTools->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dgvTools->MultiSelect = false;
			dgvTools->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dgvTools->RowHeadersVisible = false;
			dgvTools->CellClick += gcnew DataGridViewCellEventHandler(this, &inventory::dgvTools_CellClick);
			dgvTools->CellFormatting += gcnew DataGridViewCellFormattingEventHandler(this, &inventory::dgvTools_CellFormatting);
			dgvTools->DataError += gcnew DataGridViewDataErrorEventHandler(this, &inventory::dgvTools_DataError);

			// Add to Form
			this->Controls->Add(dgvTools);
			this->Controls->Add(pnlEditor);
			this->Controls->Add(pnlFilter);
			this->Controls->Add(pnlHeader);

			this->Load += gcnew EventHandler(this, &inventory::inventory_Load);
			this->ResumeLayout(false);
		}

		void dgvTools_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e)
		{
			e->ThrowException = false;
		}

		void inventory_Load(System::Object^ sender, System::EventArgs^ e)
		{
			LoadCategories();
			LoadTools();
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
			txtCode->Clear();
			txtName->Clear();
			cmbCategory->SelectedIndex = 0;
			numDailyRate->Value = 0;
			numDeposit->Value = 0;
			cmbStatus->SelectedIndex = 0;
			txtBrand->Clear();
			txtModel->Clear();
			lblEditorTitle->Text = L"Tool Details";
		}

		void btnClear_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ClearForm();
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
			String^ code = txtCode->Text->Trim();
			String^ name = txtName->Text->Trim();
			String^ cat = cmbCategory->Text->Trim();
			Decimal rate = numDailyRate->Value;
			Decimal dep = numDeposit->Value;
			String^ stat = cmbStatus->SelectedItem->ToString();
			String^ brand = txtBrand->Text->Trim();
			String^ model = txtModel->Text->Trim();

			if (code->Length == 0 || name->Length == 0) {
				MessageBox::Show(this, L"Please enter tool code and tool name.", L"Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ err = Data::ToolService::AddTool(code, name, cat, rate, dep, stat, brand, model, L"");
			if (err->Length == 0) {
				MessageBox::Show(this, L"Tool added successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadCategories();
				LoadTools();
				ClearForm();
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
			String^ stat = cmbStatus->SelectedItem->ToString();
			String^ brand = txtBrand->Text->Trim();
			String^ model = txtModel->Text->Trim();

			if (code->Length == 0 || name->Length == 0) {
				MessageBox::Show(this, L"Please enter tool code and tool name.", L"Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ err = Data::ToolService::UpdateTool(selectedToolId, code, name, cat, rate, dep, stat, brand, model, L"");
			if (err->Length == 0) {
				MessageBox::Show(this, L"Tool updated successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadTools();
				ClearForm();
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
	};
}
