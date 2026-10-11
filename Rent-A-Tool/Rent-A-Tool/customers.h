#pragma once
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

		Panel^ pnlHeader;
		Label^ lblTitle;
		Label^ lblSubtitle;
		Button^ btnClose;

		Panel^ pnlFilter;
		Label^ lblSearch;
		TextBox^ txtSearch;
		Button^ btnRefresh;

		DataGridView^ dgvCustomers;

		Panel^ pnlEditor;
		Label^ lblEditorTitle;
		Label^ lblCode;
		TextBox^ txtCode;
		Label^ lblName;
		TextBox^ txtName;
		Label^ lblNIC;
		TextBox^ txtNIC;
		Label^ lblPhone;
		TextBox^ txtPhone;
		Label^ lblEmail;
		TextBox^ txtEmail;
		Label^ lblAddress;
		TextBox^ txtAddress;
		CheckBox^ chkBlacklist;

		Button^ btnAdd;
		Button^ btnUpdate;
		Button^ btnToggleBlacklist;
		Button^ btnDelete;
		Button^ btnClear;

		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->SuspendLayout();

			// Form properties
			this->Text = L"Rent-A-Tool - Customer Management";
			this->ClientSize = System::Drawing::Size(1150, 680);
			this->MinimumSize = System::Drawing::Size(1000, 600);
			this->StartPosition = FormStartPosition::CenterScreen;
			this->BackColor = Color::FromArgb(244, 246, 249);
			this->Font = gcnew Drawing::Font(L"Segoe UI", 10);

			// Header Panel
			pnlHeader = gcnew Panel();
			pnlHeader->Dock = DockStyle::Top;
			pnlHeader->Height = 70;
			pnlHeader->BackColor = Color::FromArgb(47, 79, 79);

			lblTitle = gcnew Label();
			lblTitle->Text = L"CUSTOMER MANAGEMENT & DIRECTORY";
			lblTitle->Font = gcnew Drawing::Font(L"Segoe UI", 16, FontStyle::Bold);
			lblTitle->ForeColor = Color::White;
			lblTitle->Location = Point(20, 12);
			lblTitle->AutoSize = true;

			lblSubtitle = gcnew Label();
			lblSubtitle->Text = L"Manage customer profiles, contact info, rental history, and blacklisting";
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
			btnClose->Click += gcnew EventHandler(this, &customers::btnClose_Click);

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
			lblSearch->Text = L"Search Customer (Name, NIC, Phone, Code):";
			lblSearch->Location = Point(20, 16);
			lblSearch->AutoSize = true;
			lblSearch->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);

			txtSearch = gcnew TextBox();
			txtSearch->Location = Point(330, 13);
			txtSearch->Size = System::Drawing::Size(280, 25);
			txtSearch->TextChanged += gcnew EventHandler(this, &customers::txtSearch_TextChanged);

			btnRefresh = gcnew Button();
			btnRefresh->Text = L"Refresh";
			btnRefresh->Location = Point(625, 12);
			btnRefresh->Size = System::Drawing::Size(90, 28);
			btnRefresh->BackColor = Color::FromArgb(52, 152, 219);
			btnRefresh->ForeColor = Color::White;
			btnRefresh->FlatStyle = FlatStyle::Flat;
			btnRefresh->FlatAppearance->BorderSize = 0;
			btnRefresh->Cursor = Cursors::Hand;
			btnRefresh->Click += gcnew EventHandler(this, &customers::btnRefresh_Click);

			pnlFilter->Controls->Add(lblSearch);
			pnlFilter->Controls->Add(txtSearch);
			pnlFilter->Controls->Add(btnRefresh);

			// Right Editor Panel
			pnlEditor = gcnew Panel();
			pnlEditor->Dock = DockStyle::Right;
			pnlEditor->Width = 340;
			pnlEditor->BackColor = Color::White;
			pnlEditor->Padding = System::Windows::Forms::Padding(20);

			lblEditorTitle = gcnew Label();
			lblEditorTitle->Text = L"Customer Details";
			lblEditorTitle->Font = gcnew Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblEditorTitle->ForeColor = Color::FromArgb(47, 79, 79);
			lblEditorTitle->Location = Point(20, 15);
			lblEditorTitle->AutoSize = true;

			int y = 50;
			lblCode = gcnew Label();
			lblCode->Text = L"Customer Code:";
			lblCode->Location = Point(20, y);
			lblCode->AutoSize = true;
			txtCode = gcnew TextBox();
			txtCode->Location = Point(20, y + 20);
			txtCode->Size = System::Drawing::Size(295, 25);

			y += 50;
			lblName = gcnew Label();
			lblName->Text = L"Full Name:";
			lblName->Location = Point(20, y);
			lblName->AutoSize = true;
			txtName = gcnew TextBox();
			txtName->Location = Point(20, y + 20);
			txtName->Size = System::Drawing::Size(295, 25);

			y += 50;
			lblNIC = gcnew Label();
			lblNIC->Text = L"NIC / ID Card:";
			lblNIC->Location = Point(20, y);
			lblNIC->AutoSize = true;
			txtNIC = gcnew TextBox();
			txtNIC->Location = Point(20, y + 20);
			txtNIC->Size = System::Drawing::Size(295, 25);

			y += 50;
			lblPhone = gcnew Label();
			lblPhone->Text = L"Phone Number:";
			lblPhone->Location = Point(20, y);
			lblPhone->AutoSize = true;
			txtPhone = gcnew TextBox();
			txtPhone->Location = Point(20, y + 20);
			txtPhone->Size = System::Drawing::Size(295, 25);

			y += 50;
			lblEmail = gcnew Label();
			lblEmail->Text = L"Email Address:";
			lblEmail->Location = Point(20, y);
			lblEmail->AutoSize = true;
			txtEmail = gcnew TextBox();
			txtEmail->Location = Point(20, y + 20);
			txtEmail->Size = System::Drawing::Size(295, 25);

			y += 50;
			lblAddress = gcnew Label();
			lblAddress->Text = L"Address:";
			lblAddress->Location = Point(20, y);
			lblAddress->AutoSize = true;
			txtAddress = gcnew TextBox();
			txtAddress->Location = Point(20, y + 20);
			txtAddress->Size = System::Drawing::Size(295, 25);

			y += 55;
			chkBlacklist = gcnew CheckBox();
			chkBlacklist->Text = L"Blacklist this Customer (blocks new rentals)";
			chkBlacklist->ForeColor = Color::FromArgb(192, 57, 43);
			chkBlacklist->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			chkBlacklist->Location = Point(20, y);
			chkBlacklist->Size = System::Drawing::Size(300, 25);

			// Action buttons
			y += 40;
			btnAdd = gcnew Button();
			btnAdd->Text = L"+ Add Customer";
			btnAdd->Location = Point(20, y);
			btnAdd->Size = System::Drawing::Size(140, 36);
			btnAdd->BackColor = Color::FromArgb(39, 174, 96);
			btnAdd->ForeColor = Color::White;
			btnAdd->FlatStyle = FlatStyle::Flat;
			btnAdd->FlatAppearance->BorderSize = 0;
			btnAdd->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnAdd->Cursor = Cursors::Hand;
			btnAdd->Click += gcnew EventHandler(this, &customers::btnAdd_Click);

			btnUpdate = gcnew Button();
			btnUpdate->Text = L"Update";
			btnUpdate->Location = Point(175, y);
			btnUpdate->Size = System::Drawing::Size(140, 36);
			btnUpdate->BackColor = Color::FromArgb(41, 128, 185);
			btnUpdate->ForeColor = Color::White;
			btnUpdate->FlatStyle = FlatStyle::Flat;
			btnUpdate->FlatAppearance->BorderSize = 0;
			btnUpdate->Font = gcnew Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Bold);
			btnUpdate->Cursor = Cursors::Hand;
			btnUpdate->Click += gcnew EventHandler(this, &customers::btnUpdate_Click);

			y += 44;
			btnToggleBlacklist = gcnew Button();
			btnToggleBlacklist->Text = L"Toggle Blacklist";
			btnToggleBlacklist->Location = Point(20, y);
			btnToggleBlacklist->Size = System::Drawing::Size(140, 34);
			btnToggleBlacklist->BackColor = Color::FromArgb(230, 126, 34);
			btnToggleBlacklist->ForeColor = Color::White;
			btnToggleBlacklist->FlatStyle = FlatStyle::Flat;
			btnToggleBlacklist->FlatAppearance->BorderSize = 0;
			btnToggleBlacklist->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			btnToggleBlacklist->Cursor = Cursors::Hand;
			btnToggleBlacklist->Click += gcnew EventHandler(this, &customers::btnToggleBlacklist_Click);

			btnClear = gcnew Button();
			btnClear->Text = L"Clear Form";
			btnClear->Location = Point(175, y);
			btnClear->Size = System::Drawing::Size(140, 34);
			btnClear->BackColor = Color::FromArgb(149, 165, 166);
			btnClear->ForeColor = Color::White;
			btnClear->FlatStyle = FlatStyle::Flat;
			btnClear->FlatAppearance->BorderSize = 0;
			btnClear->Cursor = Cursors::Hand;
			btnClear->Click += gcnew EventHandler(this, &customers::btnClear_Click);

			y += 42;
			btnDelete = gcnew Button();
			btnDelete->Text = L"Delete Customer";
			btnDelete->Location = Point(20, y);
			btnDelete->Size = System::Drawing::Size(295, 32);
			btnDelete->BackColor = Color::FromArgb(231, 76, 60);
			btnDelete->ForeColor = Color::White;
			btnDelete->FlatStyle = FlatStyle::Flat;
			btnDelete->FlatAppearance->BorderSize = 0;
			btnDelete->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
			btnDelete->Cursor = Cursors::Hand;
			btnDelete->Click += gcnew EventHandler(this, &customers::btnDelete_Click);

			pnlEditor->Controls->Add(lblEditorTitle);
			pnlEditor->Controls->Add(lblCode);
			pnlEditor->Controls->Add(txtCode);
			pnlEditor->Controls->Add(lblName);
			pnlEditor->Controls->Add(txtName);
			pnlEditor->Controls->Add(lblNIC);
			pnlEditor->Controls->Add(txtNIC);
			pnlEditor->Controls->Add(lblPhone);
			pnlEditor->Controls->Add(txtPhone);
			pnlEditor->Controls->Add(lblEmail);
			pnlEditor->Controls->Add(txtEmail);
			pnlEditor->Controls->Add(lblAddress);
			pnlEditor->Controls->Add(txtAddress);
			pnlEditor->Controls->Add(chkBlacklist);
			pnlEditor->Controls->Add(btnAdd);
			pnlEditor->Controls->Add(btnUpdate);
			pnlEditor->Controls->Add(btnToggleBlacklist);
			pnlEditor->Controls->Add(btnClear);
			pnlEditor->Controls->Add(btnDelete);

			// DataGridView Customers
			dgvCustomers = gcnew DataGridView();
			dgvCustomers->Dock = DockStyle::Fill;
			dgvCustomers->BackgroundColor = Color::FromArgb(244, 246, 249);
			dgvCustomers->BorderStyle = BorderStyle::None;
			dgvCustomers->AllowUserToAddRows = false;
			dgvCustomers->AllowUserToDeleteRows = false;
			dgvCustomers->ReadOnly = true;
			dgvCustomers->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dgvCustomers->MultiSelect = false;
			dgvCustomers->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dgvCustomers->RowHeadersVisible = false;
			dgvCustomers->CellClick += gcnew DataGridViewCellEventHandler(this, &customers::dgvCustomers_CellClick);
			dgvCustomers->CellFormatting += gcnew DataGridViewCellFormattingEventHandler(this, &customers::dgvCustomers_CellFormatting);
			dgvCustomers->DataError += gcnew DataGridViewDataErrorEventHandler(this, &customers::dgvCustomers_DataError);

			this->Controls->Add(dgvCustomers);
			this->Controls->Add(pnlEditor);
			this->Controls->Add(pnlFilter);
			this->Controls->Add(pnlHeader);

			this->Load += gcnew EventHandler(this, &customers::customers_Load);
			this->ResumeLayout(false);
		}

		void dgvCustomers_DataError(System::Object^ sender, DataGridViewDataErrorEventArgs^ e)
		{
			e->ThrowException = false;
		}

		void customers_Load(System::Object^ sender, System::EventArgs^ e)
		{
			LoadCustomers();
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
			txtCode->Clear();
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
			String^ code = txtCode->Text->Trim();
			String^ name = txtName->Text->Trim();
			String^ nic = txtNIC->Text->Trim();
			String^ phone = txtPhone->Text->Trim();
			String^ email = txtEmail->Text->Trim();
			String^ address = txtAddress->Text->Trim();
			bool bl = chkBlacklist->Checked;

			if (code->Length == 0 || name->Length == 0) {
				MessageBox::Show(this, L"Please enter customer code and full name.", L"Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ err = Data::CustomerService::AddCustomer(code, name, nic, phone, email, address, bl);
			if (err->Length == 0) {
				MessageBox::Show(this, L"Customer added successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadCustomers();
				ClearForm();
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

			if (code->Length == 0 || name->Length == 0) {
				MessageBox::Show(this, L"Please enter customer code and full name.", L"Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ err = Data::CustomerService::UpdateCustomer(selectedCustomerId, code, name, nic, phone, email, address, bl);
			if (err->Length == 0) {
				MessageBox::Show(this, L"Customer updated successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LoadCustomers();
				ClearForm();
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
