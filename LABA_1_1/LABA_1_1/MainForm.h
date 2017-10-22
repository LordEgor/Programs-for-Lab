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
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBoxTowns;
	private: System::Windows::Forms::Label^  labelTownsAdd;
	private: System::Windows::Forms::Button^  buttonTownsAdd;
	private: System::Windows::Forms::Label^  labelTownsWriteCountry;
	private: System::Windows::Forms::Label^  labelTownsWritePeople;
	private: System::Windows::Forms::Label^  labelTownsWriteTown;
	private: System::Windows::Forms::TextBox^  textBoxTownsWriteCountry;

	private: System::Windows::Forms::TextBox^  textBoxTownsWritePeople;

	private: System::Windows::Forms::TextBox^  textBoxTownsWriteTown;

	private: System::Windows::Forms::Label^  labelTownsFileChoose;
	private: System::Windows::Forms::Button^  buttonTownsFileChoose;
	private: System::Windows::Forms::GroupBox^  groupBoxCountries;
	private: System::Windows::Forms::Label^  labelCountriesAdd;
	private: System::Windows::Forms::Button^  buttonCountriesAdd;
	private: System::Windows::Forms::Label^  labelCountriesWriteContinent;
	private: System::Windows::Forms::Label^  labelCountriesWriteCapital;
	private: System::Windows::Forms::Label^  labelCountriesWriteCountry;
	private: System::Windows::Forms::TextBox^  textBoxCountriesWriteContinent;
	private: System::Windows::Forms::TextBox^  textBoxCountriesWriteCapital;
	private: System::Windows::Forms::TextBox^  textBoxCountriesWriteCountry;
	private: System::Windows::Forms::Label^  labelCountriesFileChoose;
	private: System::Windows::Forms::Button^  buttonCountriesFileChoose;

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
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
			this->groupBoxTowns->SuspendLayout();
			this->groupBoxCountries->SuspendLayout();
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
			this->groupBoxTowns->Location = System::Drawing::Point(46, 25);
			this->groupBoxTowns->Name = L"groupBoxTowns";
			this->groupBoxTowns->Size = System::Drawing::Size(628, 178);
			this->groupBoxTowns->TabIndex = 0;
			this->groupBoxTowns->TabStop = false;
			this->groupBoxTowns->Text = L"������";
			// 
			// labelTownsAdd
			// 
			this->labelTownsAdd->AutoSize = true;
			this->labelTownsAdd->Location = System::Drawing::Point(385, 143);
			this->labelTownsAdd->Name = L"labelTownsAdd";
			this->labelTownsAdd->Size = System::Drawing::Size(82, 17);
			this->labelTownsAdd->TabIndex = 5;
			this->labelTownsAdd->Text = L"���������";
			// 
			// buttonTownsAdd
			// 
			this->buttonTownsAdd->Location = System::Drawing::Point(473, 140);
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
			this->textBoxTownsWriteCountry->TabIndex = 3;
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
			this->labelTownsFileChoose->AutoSize = true;
			this->labelTownsFileChoose->Location = System::Drawing::Point(168, 42);
			this->labelTownsFileChoose->Name = L"labelTownsFileChoose";
			this->labelTownsFileChoose->Size = System::Drawing::Size(118, 17);
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
			this->groupBoxCountries->Location = System::Drawing::Point(46, 234);
			this->groupBoxCountries->Name = L"groupBoxCountries";
			this->groupBoxCountries->Size = System::Drawing::Size(628, 178);
			this->groupBoxCountries->TabIndex = 0;
			this->groupBoxCountries->TabStop = false;
			this->groupBoxCountries->Text = L"������";
			// 
			// labelCountriesAdd
			// 
			this->labelCountriesAdd->AutoSize = true;
			this->labelCountriesAdd->Location = System::Drawing::Point(385, 143);
			this->labelCountriesAdd->Name = L"labelCountriesAdd";
			this->labelCountriesAdd->Size = System::Drawing::Size(82, 17);
			this->labelCountriesAdd->TabIndex = 5;
			this->labelCountriesAdd->Text = L"���������";
			// 
			// buttonCountriesAdd
			// 
			this->buttonCountriesAdd->Location = System::Drawing::Point(473, 140);
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
			this->labelCountriesFileChoose->AutoSize = true;
			this->labelCountriesFileChoose->Location = System::Drawing::Point(148, 44);
			this->labelCountriesFileChoose->Name = L"labelCountriesFileChoose";
			this->labelCountriesFileChoose->Size = System::Drawing::Size(118, 17);
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
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(807, 473);
			this->Controls->Add(this->groupBoxCountries);
			this->Controls->Add(this->groupBoxTowns);
			this->Name = L"MainForm";
			this->Text = L"������ ������";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBoxTowns->ResumeLayout(false);
			this->groupBoxTowns->PerformLayout();
			this->groupBoxCountries->ResumeLayout(false);
			this->groupBoxCountries->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion





	private: String^ townsFileName;
	private: String^ countriesFileName;
	private: OpenFileDialog^ fileDialog;

	private: StreamWriter^ swTowns;
	private: StreamWriter^ swCountries;





	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 fileDialog = gcnew OpenFileDialog();
				 fileDialog->Filter = L"txt, csv files | *.txt; *.csv";
				 fileDialog->Title = L"������� ���� �������";
				 fileDialog->InitialDirectory = Environment::CurrentDirectory;
				 ChangeVisibility_Towns(false);
				 ChangeVisibility_Countries(false);
	}	  
	
	private: System::Void ChangeVisibility_Towns(bool enable) {
				 textBoxTownsWriteTown->Enabled = enable;
				 textBoxTownsWritePeople->Enabled = enable;
				 textBoxTownsWriteCountry->Enabled = enable;
				 labelTownsWriteTown->Enabled = enable;
				 labelTownsWritePeople->Enabled = enable;
				 labelTownsWriteCountry->Enabled = enable;
				 labelTownsAdd->Enabled = enable;
				 buttonTownsAdd->Enabled = enable;
	}
	private: System::Void ChangeVisibility_Countries(bool enable) {
				 textBoxCountriesWriteCountry->Enabled = enable;
				 textBoxCountriesWriteCapital->Enabled = enable;
				 textBoxCountriesWriteContinent->Enabled = enable;
				 labelCountriesWriteCountry->Enabled = enable;
				 labelCountriesWriteCapital->Enabled = enable;
				 labelCountriesWriteContinent->Enabled = enable;
				 labelCountriesAdd->Enabled = enable;
				 buttonCountriesAdd->Enabled = enable;
	}
			 
	private: System::Void ClearInputs_Towns() {
				 textBoxTownsWriteTown->Clear();
				 textBoxTownsWritePeople->Clear();
				 textBoxTownsWriteCountry->Clear();
	}
	private: System::Void ClearInputs_Countries() {
				 textBoxCountriesWriteCountry->Clear();
				 textBoxCountriesWriteCapital->Clear();
				 textBoxCountriesWriteContinent->Clear();
	}



private: System::Void buttonTownsFileChoose_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::Windows::Forms::DialogResult res = this->fileDialog->ShowDialog();
			 if (res == System::Windows::Forms::DialogResult::Cancel)
				 return;
			 townsFileName = fileDialog->FileName;
			 bool append = System::Windows::Forms::MessageBox::Show(L"�� ������ ���������� ����?\nYes - ��\tNo - ������������ ����", L"���������� �����", System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes;
			 swTowns = gcnew StreamWriter(townsFileName, append); //���� append==true, �� ��������, ����� ����������
			 labelTownsFileChoose->Text = townsFileName;
			 ChangeVisibility_Towns(true);
}
private: System::Void buttonTownsAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!File::Exists(countriesFileName)) {
				 System::Windows::Forms::MessageBox::Show(L"���� " + countriesFileName + L" �� ����������", L"������!");
				 return;
			 }
			 if (textBoxCountriesWriteCountry->Text == String::Empty) {
				 System::Windows::Forms::MessageBox::Show(L"�������� ���� \"������\" �� �������", L"������!");
				 return;
			 }
			 this->swTowns->WriteLine(textBoxTownsWriteTown->Text + ";" + textBoxTownsWritePeople->Text + ";" + textBoxTownsWriteCountry->Text);
			 swTowns->Flush();
			 ClearInputs_Towns();
			 textBoxTownsWriteCountry->Focus();
}
private: System::Void buttonCountriesFileChoose_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::Windows::Forms::DialogResult res = this->fileDialog->ShowDialog();
			 if (res == System::Windows::Forms::DialogResult::Cancel)
				 return;
			 countriesFileName = fileDialog->FileName;
			 bool append = System::Windows::Forms::MessageBox::Show(L"�� ������ ���������� ����?\nYes - ��\tNo - ������������ ����", L"���������� �����", System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes;
			 swCountries = gcnew StreamWriter(townsFileName, append);
			 labelCountriesFileChoose->Text = countriesFileName;
			 ChangeVisibility_Countries(true);
}
private: System::Void buttonCountriesAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!File::Exists(countriesFileName)) {
				 System::Windows::Forms::MessageBox::Show(L"���� " + countriesFileName + L" �� ����������", L"������!");
				 return;
			 }
			 if (textBoxCountriesWriteCountry->Text == String::Empty) {
				 System::Windows::Forms::MessageBox::Show(L"�������� ���� \"������\" �� �������", L"������!");
				 return;
			 }
			 this->swCountries->WriteLine(textBoxCountriesWriteCountry + ";" + textBoxCountriesWriteCapital + ";" + textBoxCountriesWriteContinent);
			 swCountries->Flush();
			 ClearInputs_Countries();
			 textBoxCountriesWriteCountry->Focus();
}
private: System::Void textBox_OnlyLetters_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (Char::IsDigit(e->KeyChar)) // �������� ������ �����
				 e->Handled = true;
}
private: System::Void textBox_OnlyDigits_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (Char::IsLetter(e->KeyChar)) // �������� ������ �����
				 e->Handled = true;
}
};
}
// ����� ������� � ���� ���������, ��� �������� ���� (������ ��� �����) �� ������
// ���� ������, �� messageBox "�������� ���� �����/������ �� ���������"
//
// realised in line 426, not copied
// ok

// ��������� ������������� ����� ����� �������
// ���� ����� ���, �� ��������� "���� ��� �����"
//
// realised in line 422, not copied
// ok

// ��� �������� ����� ������������� ��������� ����� ����� false
// ������� �� �������� ����� ������ �����
//
// realised in line 356-7
// ok

// ����� �������� ������ � ���� ������� ���� ����� � ������������� ����� �� ������ ���� (������������������.�������.�����)
//
// realised in line 431
// ok

// ������� ����������� ������������� Tab'�� �� ����� ����� � ������ �����
//
// ����� done

// ���� ������ ����/���� (����� ����)
//
// done


//--------------------------------------------------------------------------------------------


// ������������ ���� ���, ����� ����� ����� ���������� �������, ��� ��� ��������� ����������

// �������������� �� ��� ����