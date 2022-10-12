#pragma once

namespace EthTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
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
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxDestAddr;
	protected:

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBoxDummy;

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
			this->textBoxDestAddr = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBoxDummy = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBoxDestAddr
			// 
			this->textBoxDestAddr->Location = System::Drawing::Point(60, 41);
			this->textBoxDestAddr->Name = L"textBoxDestAddr";
			this->textBoxDestAddr->Size = System::Drawing::Size(100, 20);
			this->textBoxDestAddr->TabIndex = 0;
			this->textBoxDestAddr->Text = L"192.168.2.239";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(85, 77);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// textBoxDummy
			// 
			this->textBoxDummy->Location = System::Drawing::Point(40, 123);
			this->textBoxDummy->Name = L"textBoxDummy";
			this->textBoxDummy->Size = System::Drawing::Size(173, 20);
			this->textBoxDummy->TabIndex = 2;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(283, 201);
			this->Controls->Add(this->textBoxDummy);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxDestAddr);
			this->Name = L"GUI";
			this->Text = L"Ethernet Tool";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ destAddr = System::Convert::ToString(textBoxDestAddr->Text);
		textBoxDummy->Text = System::Convert::ToString(destAddr);
	}
	};
}
