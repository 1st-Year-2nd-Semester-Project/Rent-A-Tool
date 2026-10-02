#pragma once

namespace RentATool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for dashboard1
	/// </summary>
	public ref class dashboard1 : public System::Windows::Forms::Form
	{
	public:
		dashboard1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~dashboard1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ homeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addToolToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ removeToolToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editToolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rentalsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ customersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addCustomerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editCustomerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ removeCustomerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ contactToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;









	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(dashboard1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->homeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rentalsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->customersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addCustomerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editCustomerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeCustomerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contactToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::DarkSlateGray;
			this->menuStrip1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->homeToolStripMenuItem,
					this->toolsToolStripMenuItem, this->rentalsToolStripMenuItem, this->customersToolStripMenuItem, this->contactToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(948, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &dashboard1::menuStrip1_ItemClicked);
			// 
			// homeToolStripMenuItem
			// 
			this->homeToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->homeToolStripMenuItem->Name = L"homeToolStripMenuItem";
			this->homeToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->homeToolStripMenuItem->Text = L"Home";
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addToolToolStripMenuItem,
					this->removeToolToolStripMenuItem, this->editToolsToolStripMenuItem
			});
			this->toolsToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// addToolToolStripMenuItem
			// 
			this->addToolToolStripMenuItem->Name = L"addToolToolStripMenuItem";
			this->addToolToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->addToolToolStripMenuItem->Text = L"Add Tool";
			// 
			// removeToolToolStripMenuItem
			// 
			this->removeToolToolStripMenuItem->Name = L"removeToolToolStripMenuItem";
			this->removeToolToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->removeToolToolStripMenuItem->Text = L"Remove Tool";
			// 
			// editToolsToolStripMenuItem
			// 
			this->editToolsToolStripMenuItem->Name = L"editToolsToolStripMenuItem";
			this->editToolsToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->editToolsToolStripMenuItem->Text = L"Edit Tools";
			// 
			// rentalsToolStripMenuItem
			// 
			this->rentalsToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->rentalsToolStripMenuItem->Name = L"rentalsToolStripMenuItem";
			this->rentalsToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->rentalsToolStripMenuItem->Text = L"Rentals";
			// 
			// customersToolStripMenuItem
			// 
			this->customersToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addCustomerToolStripMenuItem,
					this->editCustomerToolStripMenuItem, this->removeCustomerToolStripMenuItem
			});
			this->customersToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->customersToolStripMenuItem->Name = L"customersToolStripMenuItem";
			this->customersToolStripMenuItem->Size = System::Drawing::Size(76, 20);
			this->customersToolStripMenuItem->Text = L"Customers";
			// 
			// addCustomerToolStripMenuItem
			// 
			this->addCustomerToolStripMenuItem->Name = L"addCustomerToolStripMenuItem";
			this->addCustomerToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->addCustomerToolStripMenuItem->Text = L"Add Customer";
			// 
			// editCustomerToolStripMenuItem
			// 
			this->editCustomerToolStripMenuItem->Name = L"editCustomerToolStripMenuItem";
			this->editCustomerToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->editCustomerToolStripMenuItem->Text = L"Edit Customer";
			// 
			// removeCustomerToolStripMenuItem
			// 
			this->removeCustomerToolStripMenuItem->Name = L"removeCustomerToolStripMenuItem";
			this->removeCustomerToolStripMenuItem->Size = System::Drawing::Size(172, 22);
			this->removeCustomerToolStripMenuItem->Text = L"Remove Customer";
			// 
			// contactToolStripMenuItem
			// 
			this->contactToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->contactToolStripMenuItem->Name = L"contactToolStripMenuItem";
			this->contactToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->contactToolStripMenuItem->Text = L"Contact";
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(79, 130);
			this->chart1->Margin = System::Windows::Forms::Padding(2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(562, 375);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 33);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(613, 55);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Welcome to Rental a Tool ";
			this->label1->Click += gcnew System::EventHandler(this, &dashboard1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(74, 89);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Overview";
			this->label2->Click += gcnew System::EventHandler(this, &dashboard1::label2_Click);
			// 
			// dashboard1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(948, 553);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(964, 592);
			this->Name = L"dashboard1";
			this->Text = L"dashboard1";
			this->Load += gcnew System::EventHandler(this, &dashboard1::dashboard1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}

private: System::Void dashboard1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
