#pragma once

namespace LABA_1_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				if (swTowns) swTowns->Close();
				if (swCountries) swCountries->Close();
				delete components;
			}
		}

	//�������� �� �����
	private: System::Windows::Forms::GroupBox^  groupBoxTowns;
	private: System::Windows::Forms::Button^  buttonTownsFileChoose;
	private: System::Windows::Forms::Label^  labelTownsFileChoose;
	private: System::Windows::Forms::Label^  labelTownsWriteTown;
	private: System::Windows::Forms::Label^  labelTownsWritePeople;
	private: System::Windows::Forms::Label^  labelTownsWriteCountry;
	private: System::Windows::Forms::TextBox^  textBoxTownsWriteTown;
	private: System::Windows::Forms::TextBox^  textBoxTownsWritePeople;
	private: System::Windows::Forms::TextBox^  textBoxTownsWriteCountry;
	private: System::Windows::Forms::Label^  labelTownsAdd;
	private: System::Windows::Forms::Button^  buttonTownsAdd;

	private: System::Windows::Forms::GroupBox^  groupBoxCountries;
	private: System::Windows::Forms::Button^  buttonCountriesFileChoose;
	private: System::Windows::Forms::Label^  labelCountriesFileChoose;
	private: System::Windows::Forms::Label^  labelCountriesWriteCountry;
	private: System::Windows::Forms::Label^  labelCountriesWriteCapital;
	private: System::Windows::Forms::Label^  labelCountriesWriteContinent;
	private: System::Windows::Forms::TextBox^  textBoxCountriesWriteCountry;
	private: System::Windows::Forms::TextBox^  textBoxCountriesWriteCapital;
	private: System::Windows::Forms::TextBox^  textBoxCountriesWriteContinent;
	private: System::Windows::Forms::Label^  labelCountriesAdd;
	private: System::Windows::Forms::Button^  buttonCountriesAdd;

	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;



	private: System::ComponentModel::IContainer^  components;

			 

		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->groupBoxTowns = (gcnew System::Windows::Forms::GroupBox());
			this->labelTownsAdd = (gcnew System::Windows::Forms::Label());
			this->buttonTownsAdd = (gcnew System::Windows::Forms::Button());
			this->labelTownsWriteCountry = (gcnew System::Windows::Forms::Label());
			this->labelTownsWritePeople = (gcnew System::Windows::Forms::Label());
			this->labelTownsWriteTown = (gcnew System::Windows::Forms::Label());
			this->textBoxTownsWriteCountry = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTownsWritePeople = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTownsWriteTown = (gcnew System::Windows::Forms::TextBox());
			this->labelTownsFileChoose = (gcnew System::Windows::Forms::Label());
			this->buttonTownsFileChoose = (gcnew System::Windows::Forms::Button());
			this->groupBoxCountries = (gcnew System::Windows::Forms::GroupBox());
			this->labelCountriesAdd = (gcnew System::Windows::Forms::Label());
			this->buttonCountriesAdd = (gcnew System::Windows::Forms::Button());
			this->labelCountriesWriteContinent = (gcnew System::Windows::Forms::Label());
			this->labelCountriesWriteCapital = (gcnew System::Windows::Forms::Label());
			this->labelCountriesWriteCountry = (gcnew System::Windows::Forms::Label());
			this->textBoxCountriesWriteContinent = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCountriesWriteCapital = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCountriesWriteCountry = (gcnew System::Windows::Forms::TextBox());
			this->labelCountriesFileChoose = (gcnew System::Windows::Forms::Label());
			this->buttonCountriesFileChoose = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxTowns->SuspendLayout();
			this->groupBoxCountries->SuspendLayout();
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBoxTowns
			// 
			this->groupBoxTowns->Controls->Add(this->labelTownsAdd);
			this->groupBoxTowns->Controls->Add(this->buttonTownsAdd);
			this->groupBoxTowns->Controls->Add(this->labelTownsWriteCountry);
			this->groupBoxTowns->Controls->Add(this->labelTownsWritePeople);
			this->groupBoxTowns->Controls->Add(this->labelTownsWriteTown);
			this->groupBoxTowns->Controls->Add(this->textBoxTownsWriteCountry);
			this->groupBoxTowns->Controls->Add(this->textBoxTownsWritePeople);
			this->groupBoxTowns->Controls->Add(this->textBoxTownsWriteTown);
			this->groupBoxTowns->Controls->Add(this->labelTownsFileChoose);
			this->groupBoxTowns->Controls->Add(this->buttonTownsFileChoose);
			this->groupBoxTowns->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxTowns->Location = System::Drawing::Point(12, 30);
			this->groupBoxTowns->Name = L"groupBoxTowns";
			this->groupBoxTowns->Size = System::Drawing::Size(425, 180);
			this->groupBoxTowns->TabIndex = 0;
			this->groupBoxTowns->TabStop = false;
			this->groupBoxTowns->Text = L"������";
			// 
			// labelTownsAdd
			// 
			this->labelTownsAdd->Location = System::Drawing::Point(25, 146);
			this->labelTownsAdd->Name = L"labelTownsAdd";
			this->labelTownsAdd->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->labelTownsAdd->Size = System::Drawing::Size(252, 24);
			this->labelTownsAdd->TabIndex = 5;
			this->labelTownsAdd->Text = L"���������";
			// 
			// buttonTownsAdd
			// 
			this->buttonTownsAdd->Location = System::Drawing::Point(315, 138);
			this->buttonTownsAdd->Name = L"buttonTownsAdd";
			this->buttonTownsAdd->Size = System::Drawing::Size(94, 32);
			this->buttonTownsAdd->TabIndex = 3;
			this->buttonTownsAdd->Text = L"��������";
			this->buttonTownsAdd->UseVisualStyleBackColor = true;
			this->buttonTownsAdd->Click += gcnew System::EventHandler(this, &MainForm::buttonTownsAdd_Click);
			// 
			// labelTownsWriteCountry
			// 
			this->labelTownsWriteCountry->AutoSize = true;
			this->labelTownsWriteCountry->Location = System::Drawing::Point(299, 90);
			this->labelTownsWriteCountry->Name = L"labelTownsWriteCountry";
			this->labelTownsWriteCountry->Size = System::Drawing::Size(56, 17);
			this->labelTownsWriteCountry->TabIndex = 3;
			this->labelTownsWriteCountry->Text = L"������";
			// 
			// labelTownsWritePeople
			// 
			this->labelTownsWritePeople->AutoSize = true;
			this->labelTownsWritePeople->Location = System::Drawing::Point(168, 90);
			this->labelTownsWritePeople->Name = L"labelTownsWritePeople";
			this->labelTownsWritePeople->Size = System::Drawing::Size(109, 17);
			this->labelTownsWritePeople->TabIndex = 3;
			this->labelTownsWritePeople->Text = L"����� �������";
			// 
			// labelTownsWriteTown
			// 
			this->labelTownsWriteTown->AutoSize = true;
			this->labelTownsWriteTown->Location = System::Drawing::Point(29, 90);
			this->labelTownsWriteTown->Name = L"labelTownsWriteTown";
			this->labelTownsWriteTown->Size = System::Drawing::Size(48, 17);
			this->labelTownsWriteTown->TabIndex = 3;
			this->labelTownsWriteTown->Text = L"�����";
			// 
			// textBoxTownsWriteCountry
			// 
			this->textBoxTownsWriteCountry->Location = System::Drawing::Point(299, 109);
			this->textBoxTownsWriteCountry->Name = L"textBoxTownsWriteCountry";
			this->textBoxTownsWriteCountry->Size = System::Drawing::Size(110, 23);
			this->textBoxTownsWriteCountry->TabIndex = 2;
			this->textBoxTownsWriteCountry->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBox_OnlyLetters_KeyPress);
			// 
			// textBoxTownsWritePeople
			// 
			this->textBoxTownsWritePeople->Location = System::Drawing::Point(168, 109);
			this->textBoxTownsWritePeople->Name = L"textBoxTownsWritePeople";
			this->textBoxTownsWritePeople->Size = System::Drawing::Size(110, 23);
			this->textBoxTownsWritePeople->TabIndex = 1;
			this->textBoxTownsWritePeople->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBox_OnlyDigits_KeyPress);
			// 
			// textBoxTownsWriteTown
			// 
			this->textBoxTownsWriteTown->Location = System::Drawing::Point(29, 109);
			this->textBoxTownsWriteTown->Name = L"textBoxTownsWriteTown";
			this->textBoxTownsWriteTown->Size = System::Drawing::Size(110, 23);
			this->textBoxTownsWriteTown->TabIndex = 0;
			this->textBoxTownsWriteTown->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBox_OnlyLetters_KeyPress);
			// 
			// labelTownsFileChoose
			// 
			this->labelTownsFileChoose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelTownsFileChoose->Location = System::Drawing::Point(154, 33);
			this->labelTownsFileChoose->Name = L"labelTownsFileChoose";
			this->labelTownsFileChoose->Size = System::Drawing::Size(265, 49);
			this->labelTownsFileChoose->TabIndex = 1;
			this->labelTownsFileChoose->Text = L"���� �� ������";
			// 
			// buttonTownsFileChoose
			// 
			this->buttonTownsFileChoose->Location = System::Drawing::Point(25, 33);
			this->buttonTownsFileChoose->Name = L"buttonTownsFileChoose";
			this->buttonTownsFileChoose->Size = System::Drawing::Size(123, 35);
			this->buttonTownsFileChoose->TabIndex = 0;
			this->buttonTownsFileChoose->TabStop = false;
			this->buttonTownsFileChoose->Text = L"������� ����";
			this->buttonTownsFileChoose->UseVisualStyleBackColor = true;
			this->buttonTownsFileChoose->Click += gcnew System::EventHandler(this, &MainForm::buttonTownsFileChoose_Click);
			// 
			// groupBoxCountries
			// 
			this->groupBoxCountries->Controls->Add(this->labelCountriesAdd);
			this->groupBoxCountries->Controls->Add(this->buttonCountriesAdd);
			this->groupBoxCountries->Controls->Add(this->labelCountriesWriteContinent);
			this->groupBoxCountries->Controls->Add(this->labelCountriesWriteCapital);
			this->groupBoxCountries->Controls->Add(this->labelCountriesWriteCountry);
			this->groupBoxCountries->Controls->Add(this->textBoxCountriesWriteContinent);
			this->groupBoxCountries->Controls->Add(this->textBoxCountriesWriteCapital);
			this->groupBoxCountries->Controls->Add(this->textBoxCountriesWriteCountry);
			this->groupBoxCountries->Controls->Add(this->labelCountriesFileChoose);
			this->groupBoxCountries->Controls->Add(this->buttonCountriesFileChoose);
			this->groupBoxCountries->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBoxCountries->Location = System::Drawing::Point(12, 220);
			this->groupBoxCountries->Name = L"groupBoxCountries";
			this->groupBoxCountries->Size = System::Drawing::Size(425, 178);
			this->groupBoxCountries->TabIndex = 0;
			this->groupBoxCountries->TabStop = false;
			this->groupBoxCountries->Text = L"������";
			// 
			// labelCountriesAdd
			// 
			this->labelCountriesAdd->Location = System::Drawing::Point(25, 148);
			this->labelCountriesAdd->Name = L"labelCountriesAdd";
			this->labelCountriesAdd->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->labelCountriesAdd->Size = System::Drawing::Size(253, 24);
			this->labelCountriesAdd->TabIndex = 5;
			this->labelCountriesAdd->Text = L"���������";
			// 
			// buttonCountriesAdd
			// 
			this->buttonCountriesAdd->Location = System::Drawing::Point(315, 140);
			this->buttonCountriesAdd->Name = L"buttonCountriesAdd";
			this->buttonCountriesAdd->Size = System::Drawing::Size(94, 32);
			this->buttonCountriesAdd->TabIndex = 3;
			this->buttonCountriesAdd->Text = L"��������";
			this->buttonCountriesAdd->UseVisualStyleBackColor = true;
			this->buttonCountriesAdd->Click += gcnew System::EventHandler(this, &MainForm::buttonCountriesAdd_Click);
			// 
			// labelCountriesWriteContinent
			// 
			this->labelCountriesWriteContinent->AutoSize = true;
			this->labelCountriesWriteContinent->Location = System::Drawing::Point(299, 90);
			this->labelCountriesWriteContinent->Name = L"labelCountriesWriteContinent";
			this->labelCountriesWriteContinent->Size = System::Drawing::Size(79, 17);
			this->labelCountriesWriteContinent->TabIndex = 3;
			this->labelCountriesWriteContinent->Text = L"���������";
			// 
			// labelCountriesWriteCapital
			// 
			this->labelCountriesWriteCapital->AutoSize = true;
			this->labelCountriesWriteCapital->Location = System::Drawing::Point(168, 90);
			this->labelCountriesWriteCapital->Name = L"labelCountriesWriteCapital";
			this->labelCountriesWriteCapital->Size = System::Drawing::Size(64, 17);
			this->labelCountriesWriteCapital->TabIndex = 3;
			this->labelCountriesWriteCapital->Text = L"�������";
			// 
			// labelCountriesWriteCountry
			// 
			this->labelCountriesWriteCountry->AutoSize = true;
			this->labelCountriesWriteCountry->Location = System::Drawing::Point(29, 90);
			this->labelCountriesWriteCountry->Name = L"labelCountriesWriteCountry";
			this->labelCountriesWriteCountry->Size = System::Drawing::Size(56, 17);
			this->labelCountriesWriteCountry->TabIndex = 3;
			this->labelCountriesWriteCountry->Text = L"������";
			// 
			// textBoxCountriesWriteContinent
			// 
			this->textBoxCountriesWriteContinent->Location = System::Drawing::Point(299, 109);
			this->textBoxCountriesWriteContinent->Name = L"textBoxCountriesWriteContinent";
			this->textBoxCountriesWriteContinent->Size = System::Drawing::Size(110, 23);
			this->textBoxCountriesWriteContinent->TabIndex = 2;
			this->textBoxCountriesWriteContinent->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBox_OnlyLetters_KeyPress);
			// 
			// textBoxCountriesWriteCapital
			// 
			this->textBoxCountriesWriteCapital->Location = System::Drawing::Point(168, 109);
			this->textBoxCountriesWriteCapital->Name = L"textBoxCountriesWriteCapital";
			this->textBoxCountriesWriteCapital->Size = System::Drawing::Size(110, 23);
			this->textBoxCountriesWriteCapital->TabIndex = 1;
			this->textBoxCountriesWriteCapital->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBox_OnlyLetters_KeyPress);
			// 
			// textBoxCountriesWriteCountry
			// 
			this->textBoxCountriesWriteCountry->Location = System::Drawing::Point(29, 109);
			this->textBoxCountriesWriteCountry->Name = L"textBoxCountriesWriteCountry";
			this->textBoxCountriesWriteCountry->Size = System::Drawing::Size(110, 23);
			this->textBoxCountriesWriteCountry->TabIndex = 0;
			this->textBoxCountriesWriteCountry->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBox_OnlyLetters_KeyPress);
			// 
			// labelCountriesFileChoose
			// 
			this->labelCountriesFileChoose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelCountriesFileChoose->Location = System::Drawing::Point(148, 33);
			this->labelCountriesFileChoose->Name = L"labelCountriesFileChoose";
			this->labelCountriesFileChoose->Size = System::Drawing::Size(265, 49);
			this->labelCountriesFileChoose->TabIndex = 1;
			this->labelCountriesFileChoose->Text = L"���� �� ������";
			// 
			// buttonCountriesFileChoose
			// 
			this->buttonCountriesFileChoose->Location = System::Drawing::Point(25, 33);
			this->buttonCountriesFileChoose->Name = L"buttonCountriesFileChoose";
			this->buttonCountriesFileChoose->Size = System::Drawing::Size(117, 35);
			this->buttonCountriesFileChoose->TabIndex = 0;
			this->buttonCountriesFileChoose->TabStop = false;
			this->buttonCountriesFileChoose->Text = L"������� ����";
			this->buttonCountriesFileChoose->UseVisualStyleBackColor = true;
			this->buttonCountriesFileChoose->Click += gcnew System::EventHandler(this, &MainForm::buttonCountriesFileChoose_Click);
			// 
			// timer
			// 
			this->timer->Interval = 3000;
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(456, 24);
			this->menuStrip->TabIndex = 1;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�����ToolStripMenuItem });
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::�����ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->aboutToolStripMenuItem->Text = L"� ���������";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(456, 421);
			this->Controls->Add(this->groupBoxCountries);
			this->Controls->Add(this->groupBoxTowns);
			this->Controls->Add(this->menuStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->MaximumSize = System::Drawing::Size(1000, 1000);
			this->Name = L"MainForm";
			this->Text = L"������ ������� � �����";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBoxTowns->ResumeLayout(false);
			this->groupBoxTowns->PerformLayout();
			this->groupBoxCountries->ResumeLayout(false);
			this->groupBoxCountries->PerformLayout();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	// ���� � ������ ������� � ����� ��� ����� ����������
	private: String^ townsFileName = String::Empty;
	private: String^ countriesFileName = String::Empty;
	// ���������� ����
	private: OpenFileDialog^ fileDialog;
	// ������ ��� ������ � �����
	private: StreamWriter^ swTowns;
	private: StreamWriter^ swCountries;

			 

			 /// <summary>
			 /// ��� �������� �����
			 /// </summary>
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 // �������� ����������� ���� ������ �����
				 fileDialog = gcnew OpenFileDialog();
				 fileDialog->Filter = L"txt, csv files | *.txt; *.csv"; // ����������� �� ��� ����������� �����
				 // ��������� ���� � ����� � ������� ������� � �����
				 String^ dir = L"\\LABA_1_1\\LABA_1_1";
				 dir = Environment::CurrentDirectory->Remove(Environment::CurrentDirectory->Length - dir->Length);
				 fileDialog->InitialDirectory = dir->Insert(dir->Length, L"\\iofiles");
				 // ���������� ��������� ����� = false, ��� ��� ����� �� �������
				 ChangeEnable_Towns(false);
				 ChangeEnable_Countries(false);
				 labelTownsFileChoose->Text = "���� �� ������";
				 labelCountriesFileChoose->Text = "���� �� ������";
				 // ������ label'� ����� � �������� "��������"
				 labelTownsAdd->Text = String::Empty;
				 labelCountriesAdd->Text = String::Empty;

				 // �������� ������� ��� ������� label'��  ����� � �������� "��������"
				 timer->Enabled = true; // ������� ����, ��� ������� timer->Tick ����� ����������/�����������
				 timer->Interval = 3000; // �������� ����� �������������� timer->Tick
				 timer->Tick += gcnew EventHandler(this, &MainForm::Timer_Elapsed_Method); // ���������, ����� ����� ���������� ��� ������������ ������� timer1->Tick
				 
	}

			 /// <summary>
			 /// ���������/������������ ��������� ����� �������
			 /// <param name="enable"> True=������������, Flase=���������</param>
			 /// </summary>
	private: System::Void ChangeEnable_Towns(bool enable) {
				 textBoxTownsWriteTown->Enabled = enable;
				 textBoxTownsWritePeople->Enabled = enable;
				 textBoxTownsWriteCountry->Enabled = enable;
				 labelTownsWriteTown->Enabled = enable;
				 labelTownsWritePeople->Enabled = enable;
				 labelTownsWriteCountry->Enabled = enable;
				 labelTownsAdd->Enabled = enable;
				 buttonTownsAdd->Enabled = enable;
	}
			 /// <summary>
			 /// ���������/������������ ��������� ����� �����
			 /// <param name="enable">True=������������ Flase=���������</param>
			 /// </summary>
	private: System::Void ChangeEnable_Countries(bool enable) {
				 textBoxCountriesWriteCountry->Enabled = enable;
				 textBoxCountriesWriteCapital->Enabled = enable;
				 textBoxCountriesWriteContinent->Enabled = enable;
				 labelCountriesWriteCountry->Enabled = enable;
				 labelCountriesWriteCapital->Enabled = enable;
				 labelCountriesWriteContinent->Enabled = enable;
				 labelCountriesAdd->Enabled = enable;
				 buttonCountriesAdd->Enabled = enable;
	}
			 /// <summary>
			 /// ������� ����� ����� � GroupBox �������
			 /// </summary>
	private: System::Void ClearInputs_Towns() {
				 textBoxTownsWriteTown->Clear();
				 textBoxTownsWritePeople->Clear();
				 textBoxTownsWriteCountry->Clear();
	}
			 /// <summary>
			 /// ������� ����� ����� � GroupBox �����
			 /// </summary>
	private: System::Void ClearInputs_Countries() {
				 textBoxCountriesWriteCountry->Clear();
				 textBoxCountriesWriteCapital->Clear();
				 textBoxCountriesWriteContinent->Clear();
	}
			 /// <summary>
			 /// ������� �� ���������� timer->Tick ���������� ������ � �������� label'�
			 /// </summary>
	private: System::Void Timer_Elapsed_Method(System::Object^  sender, System::EventArgs^  e) {
				 timer->Stop();
				 labelTownsAdd->Text = String::Empty;
				 labelCountriesAdd->Text = String::Empty;
	}

			 /// <summary>
			 /// ����� ����� �������
			 /// </summary>
private: System::Void buttonTownsFileChoose_Click(System::Object^  sender, System::EventArgs^  e) {
			 // ������������ ���������� ���� ������ �����
			 fileDialog->Title = L"������� ���� �������";
			 System::Windows::Forms::DialogResult res = this->fileDialog->ShowDialog();
			 // ���� �� ������
			 if (res == System::Windows::Forms::DialogResult::Cancel)
				 return; 
			 townsFileName = fileDialog->FileName; // ������ ���� � ����� �������
			 //���� ���� ��� ������ ��� ������ �����
			 if (String::Equals(townsFileName, countriesFileName)) {
				 System::Windows::Forms::MessageBox::Show(L"���� " + countriesFileName + L" ������ ��� ������ ���������� � �������, ��� ������ ������������", L"������!");
				 return;
			 }
			 res = System::Windows::Forms::MessageBox::Show(L"�� ������ ���������� ���������� � ���� ����?\n\n�� - ���������� ���������� � ����\n��� - ������������ ���� ����\n������ - ������ ������ �����", L"����� ������ � ������ �������", System::Windows::Forms::MessageBoxButtons::YesNoCancel);
			 // ������ � ��/����-������
			 bool append;
			 if (res == System::Windows::Forms::DialogResult::Yes)
				 append = true;
			 else if (res == System::Windows::Forms::DialogResult::No)
				 append = false;
			 else return;
			 // ���� ����� ������ ��� ������������ - ������� �����
			 if (swTowns != nullptr)
				 swTowns->Close();
			 swTowns = gcnew StreamWriter(townsFileName, append); //���� append=true, �� ��������, ����� ����������
			 labelTownsFileChoose->Text = townsFileName;
			 ChangeEnable_Towns(true); // ��������� ��������� ����� ���������� � �������
}
		 /// <summary>
		 /// ���������� ����� ������ � ���� �������
		 /// </summary>
private: System::Void buttonTownsAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			 // �������� ������� ��������� ��������� ����
			 if (textBoxTownsWriteTown->Text == String::Empty) {
				 System::Windows::Forms::MessageBox::Show(L"�������� ���� \"�����\" �� �������", L"������!");
				 textBoxTownsWriteTown->Focus();
				 return;
			 }
			 // ������� ������ ���������� �����
			 if (textBoxTownsWritePeople->Text == String::Empty)
				 textBoxTownsWritePeople->Text = "-";
			 if (textBoxTownsWriteCountry->Text == String::Empty)
				 textBoxTownsWriteCountry->Text = "-";
			 // ������ ����� ����� StreamWriter, ��� ������� � ������� ����� �����
			 swTowns->WriteLine(textBoxTownsWriteTown->Text + ";" + textBoxTownsWritePeople->Text + ";" + textBoxTownsWriteCountry->Text);
			 swTowns->Flush();
			 ClearInputs_Towns();
			 textBoxTownsWriteTown->Focus();
			 labelTownsAdd->Text = L"���������� ���� ���������";
			 timer->Start(); // ������ ������� ��� label'�
}

		 /// <summary>
		 /// ����� ����� �����
		 /// </summary>
private: System::Void buttonCountriesFileChoose_Click(System::Object^  sender, System::EventArgs^  e) { // ������ buttonTownsFileChoose_Click
			 // ������������ ���������� ���� ������ �����
			 fileDialog->Title = L"������� ���� �����";
			 System::Windows::Forms::DialogResult res = this->fileDialog->ShowDialog();
			 if (res == System::Windows::Forms::DialogResult::Cancel)
				 return;
			 countriesFileName = fileDialog->FileName;
			 // ���� ���� ��� ������ ��� ������ �������
			 if (String::Equals(townsFileName, countriesFileName)) { 
				 System::Windows::Forms::MessageBox::Show(L"���� " + countriesFileName + L" ������ ��� ������ ���������� � �������, ��� ������ ������������", L"������!");
				 return;
			 }
			 res = System::Windows::Forms::MessageBox::Show(L"�� ������ ���������� ���������� � ���� ����?\n\n�� - ���������� ���������� � ����\n��� - ������������ ���� ����\n������ - ������ ������ �����", L"����� ������ � ������ �������", System::Windows::Forms::MessageBoxButtons::YesNoCancel);
			 // ������ � ��/����-������
			 bool append;
			 if (res == System::Windows::Forms::DialogResult::Yes)
				 append = true;
			 else if (res == System::Windows::Forms::DialogResult::No)
				 append = false;
			 else return;
			 // ���� ����� ������ ��� ������������ - ������� �����
			 if (swCountries != nullptr)
				 swCountries->Close();
			 swCountries = gcnew StreamWriter(countriesFileName, append);
			 labelCountriesFileChoose->Text = countriesFileName;
			 ChangeEnable_Countries(true);
}
		 /// <summary>
		 /// ���������� ����� ������ � ���� �����
		 /// </summary>
private: System::Void buttonCountriesAdd_Click(System::Object^  sender, System::EventArgs^  e) { // ������ buttonTownsAdd_Click
			 // �������� ������� ��������� ��������� ����
			 if (textBoxCountriesWriteCountry->Text == String::Empty) {
				 System::Windows::Forms::MessageBox::Show(L"�������� ���� \"������\" �� �������", L"������!");
				 textBoxCountriesWriteCountry->Focus();
				 return;
			 }
			 // ������� ������ ���������� �����
			 if (textBoxCountriesWriteCapital->Text == String::Empty)
				 textBoxCountriesWriteCapital->Text = "-";
			 if (textBoxCountriesWriteContinent->Text == String::Empty)
				 textBoxCountriesWriteContinent->Text = "-";
			 swCountries->WriteLine(textBoxCountriesWriteCountry->Text + ";" + textBoxCountriesWriteCapital->Text + ";" + textBoxCountriesWriteContinent->Text);
			 swCountries->Flush();
			 ClearInputs_Countries();
			 textBoxCountriesWriteCountry->Focus();
			 labelCountriesAdd->Text = L"���������� ���� ���������";
			 timer->Start(); // ������ ������� ��� label'�
}
		 /// <summary>
		 /// ����������� �� ���� � textBox'� - ������ �����
		 /// </summary>
private: System::Void textBox_OnlyLetters_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!Char::IsLetter(e->KeyChar) && !(e->KeyChar == (char)8)) // (char)8 = Backspace
				 e->Handled = true;
}
		 /// <summary>
		 /// ����������� �� ���� � textBox'� - ������ �����
		 /// </summary>
private: System::Void textBox_OnlyDigits_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (!Char::IsDigit(e->KeyChar) && !(e->KeyChar == (char)8)) 
				 e->Handled = true;
}
		 /// <summary>
		 /// � ���������
		 /// </summary>
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show(L"������ ������� � �����\n������������� ��� ������ ���������� � ������� � ������� � ��������� �����\n������ 1.3\n� ������� ����, 2018.\n�� ��� ����� ��������, �� �� �������� ��� ����.",L"� ���������");
}

private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MainForm::~MainForm();
}
};
}