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
	private: System::Windows::Forms::Button^  buttonSendUDP;
	protected:



	private: System::Windows::Forms::TextBox^  textBoxDestPort;

	private: System::Windows::Forms::TextBox^  textBoxPayload;
	private: System::Windows::Forms::Label^  labelDstIP;
	private: System::Windows::Forms::Label^  labelDstPort;
	private: System::Windows::Forms::Label^  labelMessage;




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
			this->buttonSendUDP = (gcnew System::Windows::Forms::Button());
			this->textBoxDestPort = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPayload = (gcnew System::Windows::Forms::TextBox());
			this->labelDstIP = (gcnew System::Windows::Forms::Label());
			this->labelDstPort = (gcnew System::Windows::Forms::Label());
			this->labelMessage = (gcnew System::Windows::Forms::Label());
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
			// buttonSendUDP
			// 
			this->buttonSendUDP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSendUDP->Location = System::Drawing::Point(154, 100);
			this->buttonSendUDP->Name = L"buttonSendUDP";
			this->buttonSendUDP->Size = System::Drawing::Size(75, 23);
			this->buttonSendUDP->TabIndex = 1;
			this->buttonSendUDP->Text = L"Send";
			this->buttonSendUDP->UseVisualStyleBackColor = true;
			this->buttonSendUDP->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
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
			// labelDstIP
			// 
			this->labelDstIP->AutoSize = true;
			this->labelDstIP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDstIP->Location = System::Drawing::Point(24, 22);
			this->labelDstIP->Name = L"labelDstIP";
			this->labelDstIP->Size = System::Drawing::Size(113, 20);
			this->labelDstIP->TabIndex = 5;
			this->labelDstIP->Text = L"Destination IP:";
			this->labelDstIP->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelDstPort
			// 
			this->labelDstPort->AutoSize = true;
			this->labelDstPort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDstPort->Location = System::Drawing::Point(10, 48);
			this->labelDstPort->Name = L"labelDstPort";
			this->labelDstPort->Size = System::Drawing::Size(127, 20);
			this->labelDstPort->TabIndex = 6;
			this->labelDstPort->Text = L"Destination Port:";
			this->labelDstPort->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelMessage
			// 
			this->labelMessage->AutoSize = true;
			this->labelMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMessage->Location = System::Drawing::Point(59, 72);
			this->labelMessage->Name = L"labelMessage";
			this->labelMessage->Size = System::Drawing::Size(78, 20);
			this->labelMessage->TabIndex = 7;
			this->labelMessage->Text = L"Message:";
			this->labelMessage->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(261, 154);
			this->Controls->Add(this->labelMessage);
			this->Controls->Add(this->labelDstPort);
			this->Controls->Add(this->labelDstIP);
			this->Controls->Add(this->textBoxPayload);
			this->Controls->Add(this->textBoxDestPort);
			this->Controls->Add(this->buttonSendUDP);
			this->Controls->Add(this->textBoxDestAddr);
			this->Name = L"GUI";
			this->Text = L"Ethernet Tool";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// Destination IP address
		String^ destAddr = System::Convert::ToString(textBoxDestAddr->Text);
		std::string ip = msclr::interop::marshal_as<std::string>(destAddr);
		const char* IP = ip.c_str();
		// Destination Port
		int portNum = System::Convert::ToInt16(textBoxDestPort->Text);
		// Message
		String^ message = System::Convert::ToString(textBoxPayload->Text);
		std::string msg = msclr::interop::marshal_as<std::string>(message);

		sendUDP(IP, portNum, msg);
	}
	};
}
