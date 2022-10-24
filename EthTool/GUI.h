#pragma once

#include "udp.h"
#include <msclr\marshal_cppstd.h>

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

	private: System::Windows::Forms::TextBox^  textBoxDestPort;

	private: System::Windows::Forms::TextBox^  textBoxPayload;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

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
			this->textBoxDestPort = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPayload = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxDestAddr
			// 
			this->textBoxDestAddr->Location = System::Drawing::Point(143, 22);
			this->textBoxDestAddr->Name = L"textBoxDestAddr";
			this->textBoxDestAddr->Size = System::Drawing::Size(100, 20);
			this->textBoxDestAddr->TabIndex = 0;
			this->textBoxDestAddr->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(154, 100);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// textBoxDestPort
			// 
			this->textBoxDestPort->Location = System::Drawing::Point(143, 48);
			this->textBoxDestPort->Name = L"textBoxDestPort";
			this->textBoxDestPort->Size = System::Drawing::Size(100, 20);
			this->textBoxDestPort->TabIndex = 3;
			this->textBoxDestPort->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxPayload
			// 
			this->textBoxPayload->Location = System::Drawing::Point(143, 74);
			this->textBoxPayload->Name = L"textBoxPayload";
			this->textBoxPayload->Size = System::Drawing::Size(100, 20);
			this->textBoxPayload->TabIndex = 4;
			this->textBoxPayload->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(24, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Destination IP:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(10, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Destination Port:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(59, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Message:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(262, 154);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxPayload);
			this->Controls->Add(this->textBoxDestPort);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBoxDestAddr);
			this->Name = L"GUI";
			this->Text = L"Ethernet Tool";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// IP address
		String^ destAddr = System::Convert::ToString(textBoxDestAddr->Text);
		std::string ip = msclr::interop::marshal_as<std::string>(destAddr);
		const char* IP = ip.c_str();
		// Port
		int portNum = System::Convert::ToInt16(textBoxDestPort->Text);
		//int portNum = msclr::interop::marshal_as<int>(destPort);
		// Payload
		String^ message = System::Convert::ToString(textBoxPayload->Text);
		std::string msg = msclr::interop::marshal_as<std::string>(message);

		sendUDP(IP, portNum, msg);
	}
	};
}
