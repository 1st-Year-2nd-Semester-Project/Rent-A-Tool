#pragma once

namespace RentATool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for loginform
	/// </summary>
	public ref class loginform : public System::Windows::Forms::Form
	{
	public:
		loginform(void)
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
		~loginform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ logopic;
	protected:

	private: System::Windows::Forms::Label^ txtuser;
	private: System::Windows::Forms::Label^ txtpass;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ loginbtn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ signupbtn;



	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(loginform::typeid));
			this->logopic = (gcnew System::Windows::Forms::PictureBox());
			this->txtuser = (gcnew System::Windows::Forms::Label());
			this->txtpass = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->loginbtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->signupbtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logopic))->BeginInit();
			this->SuspendLayout();
			// 
			// logopic
			// 
			this->logopic->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->logopic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logopic.Image")));
			this->logopic->Location = System::Drawing::Point(109, 64);
			this->logopic->Name = L"logopic";
			this->logopic->Size = System::Drawing::Size(150, 150);
			this->logopic->TabIndex = 0;
			this->logopic->TabStop = false;
			// 
			// txtuser
			// 
			this->txtuser->AutoSize = true;
			this->txtuser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtuser->Location = System::Drawing::Point(39, 296);
			this->txtuser->Name = L"txtuser";
			this->txtuser->Size = System::Drawing::Size(116, 25);
			this->txtuser->TabIndex = 1;
			this->txtuser->Text = L"Username:";
			// 
			// txtpass
			// 
			this->txtpass->AutoSize = true;
			this->txtpass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtpass->Location = System::Drawing::Point(39, 352);
			this->txtpass->Name = L"txtpass";
			this->txtpass->Size = System::Drawing::Size(112, 25);
			this->txtpass->TabIndex = 2;
			this->txtpass->Text = L"Password:";
			this->txtpass->Click += gcnew System::EventHandler(this, &loginform::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(170, 293);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(190, 31);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(170, 352);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(190, 31);
			this->textBox2->TabIndex = 4;
			// 
			// loginbtn
			// 
			this->loginbtn->BackColor = System::Drawing::Color::CadetBlue;
			this->loginbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->loginbtn->ForeColor = System::Drawing::Color::Black;
			this->loginbtn->Location = System::Drawing::Point(109, 427);
			this->loginbtn->Name = L"loginbtn";
			this->loginbtn->Size = System::Drawing::Size(150, 35);
			this->loginbtn->TabIndex = 5;
			this->loginbtn->Text = L"Login";
			this->loginbtn->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(39, 519);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(197, 25);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Not Have Account\?";
			// 
			// signupbtn
			// 
			this->signupbtn->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->signupbtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->signupbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->signupbtn->ForeColor = System::Drawing::Color::Transparent;
			this->signupbtn->Location = System::Drawing::Point(242, 514);
			this->signupbtn->Name = L"signupbtn";
			this->signupbtn->Size = System::Drawing::Size(106, 35);
			this->signupbtn->TabIndex = 7;
			this->signupbtn->Text = L"SignUP";
			this->signupbtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->signupbtn->UseVisualStyleBackColor = false;
			// 
			// loginform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkSlateGray;
			this->ClientSize = System::Drawing::Size(405, 618);
			this->Controls->Add(this->signupbtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->loginbtn);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->txtpass);
			this->Controls->Add(this->txtuser);
			this->Controls->Add(this->logopic);
			this->ForeColor = System::Drawing::Color::Transparent;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(421, 657);
			this->MinimumSize = System::Drawing::Size(421, 657);
			this->Name = L"loginform";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rent-A-Tool";
			this->Load += gcnew System::EventHandler(this, &loginform::loginform_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logopic))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loginform_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
