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
	private: System::Windows::Forms::TextBox^  textBoxDestPort;
	private: System::Windows::Forms::TextBox^  textBoxDestMsg;
	private: System::Windows::Forms::Label^  labelDstIP;
	private: System::Windows::Forms::Label^  labelDstPort;
	private: System::Windows::Forms::Label^  labelMessage;
	private: System::Windows::Forms::Button^  buttonListenUDP;
	private: System::Windows::Forms::TextBox^  textBoxListenMsgUDP;
	private: System::Windows::Forms::TextBox^  textBoxListenPort;
	private: System::Windows::Forms::Label^  labelListenMsg;
	private: System::Windows::Forms::Label^  labelListenPort;
	private: System::Windows::Forms::TabControl^  tabControlUDPvsTCP;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabControl^  tabControlUDPtypes;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::CheckBox^  checkBoxDesc;
	private: System::Windows::Forms::TextBox^  textBoxEndInt;
	private: System::Windows::Forms::TextBox^  textBoxStartInt;
	private: System::Windows::Forms::Label^  labelEndInt;
	private: System::Windows::Forms::CheckBox^  checkBoxLoop;
	private: System::Windows::Forms::Label^  labelStartInt;
	private: System::Windows::Forms::Label^  labelLocalIP;
	private: System::Windows::Forms::TextBox^  textBoxLocalIP;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorkerListenUDP;

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
			this->textBoxDestMsg = (gcnew System::Windows::Forms::TextBox());
			this->labelDstIP = (gcnew System::Windows::Forms::Label());
			this->labelDstPort = (gcnew System::Windows::Forms::Label());
			this->labelMessage = (gcnew System::Windows::Forms::Label());
			this->buttonListenUDP = (gcnew System::Windows::Forms::Button());
			this->textBoxListenMsgUDP = (gcnew System::Windows::Forms::TextBox());
			this->textBoxListenPort = (gcnew System::Windows::Forms::TextBox());
			this->labelListenMsg = (gcnew System::Windows::Forms::Label());
			this->labelListenPort = (gcnew System::Windows::Forms::Label());
			this->tabControlUDPvsTCP = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabControlUDPtypes = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->labelEndInt = (gcnew System::Windows::Forms::Label());
			this->checkBoxLoop = (gcnew System::Windows::Forms::CheckBox());
			this->labelStartInt = (gcnew System::Windows::Forms::Label());
			this->textBoxEndInt = (gcnew System::Windows::Forms::TextBox());
			this->textBoxStartInt = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBoxDesc = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->labelLocalIP = (gcnew System::Windows::Forms::Label());
			this->textBoxLocalIP = (gcnew System::Windows::Forms::TextBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->backgroundWorkerListenUDP = (gcnew System::ComponentModel::BackgroundWorker());
			this->tabControlUDPvsTCP->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControlUDPtypes->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBoxDestAddr
			// 
			this->textBoxDestAddr->Location = System::Drawing::Point(137, 18);
			this->textBoxDestAddr->Name = L"textBoxDestAddr";
			this->textBoxDestAddr->Size = System::Drawing::Size(100, 20);
			this->textBoxDestAddr->TabIndex = 0;
			this->textBoxDestAddr->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// buttonSendUDP
			// 
			this->buttonSendUDP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonSendUDP->Location = System::Drawing::Point(8, 148);
			this->buttonSendUDP->Name = L"buttonSendUDP";
			this->buttonSendUDP->Size = System::Drawing::Size(345, 27);
			this->buttonSendUDP->TabIndex = 1;
			this->buttonSendUDP->Text = L"Send";
			this->buttonSendUDP->UseVisualStyleBackColor = true;
			//this->buttonSendUDP->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// textBoxDestPort
			// 
			this->textBoxDestPort->Location = System::Drawing::Point(137, 44);
			this->textBoxDestPort->Name = L"textBoxDestPort";
			this->textBoxDestPort->Size = System::Drawing::Size(100, 20);
			this->textBoxDestPort->TabIndex = 3;
			this->textBoxDestPort->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxDestMsg
			// 
			this->textBoxDestMsg->Location = System::Drawing::Point(137, 70);
			this->textBoxDestMsg->Name = L"textBoxDestMsg";
			this->textBoxDestMsg->Size = System::Drawing::Size(202, 20);
			this->textBoxDestMsg->TabIndex = 4;
			this->textBoxDestMsg->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// labelDstIP
			// 
			this->labelDstIP->AutoSize = true;
			this->labelDstIP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDstIP->Location = System::Drawing::Point(18, 18);
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
			this->labelDstPort->Location = System::Drawing::Point(4, 44);
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
			this->labelMessage->Location = System::Drawing::Point(53, 70);
			this->labelMessage->Name = L"labelMessage";
			this->labelMessage->Size = System::Drawing::Size(78, 20);
			this->labelMessage->TabIndex = 7;
			this->labelMessage->Text = L"Message:";
			this->labelMessage->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// buttonListenUDP
			// 
			this->buttonListenUDP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonListenUDP->Location = System::Drawing::Point(8, 148);
			this->buttonListenUDP->Name = L"buttonListenUDP";
			this->buttonListenUDP->Size = System::Drawing::Size(345, 27);
			this->buttonListenUDP->TabIndex = 8;
			this->buttonListenUDP->Text = L"Listen";
			this->buttonListenUDP->UseVisualStyleBackColor = true;
			this->buttonListenUDP->Click += gcnew System::EventHandler(this, &GUI::buttonListenUDP_Click);
			// 
			// textBoxListenMsgUDP
			// 
			this->textBoxListenMsgUDP->Location = System::Drawing::Point(137, 70);
			this->textBoxListenMsgUDP->Name = L"textBoxListenMsgUDP";
			this->textBoxListenMsgUDP->Size = System::Drawing::Size(202, 20);
			this->textBoxListenMsgUDP->TabIndex = 9;
			this->textBoxListenMsgUDP->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxListenPort
			// 
			this->textBoxListenPort->Location = System::Drawing::Point(137, 44);
			this->textBoxListenPort->Name = L"textBoxListenPort";
			this->textBoxListenPort->Size = System::Drawing::Size(100, 20);
			this->textBoxListenPort->TabIndex = 10;
			this->textBoxListenPort->Text = L"789";
			this->textBoxListenPort->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// labelListenMsg
			// 
			this->labelListenMsg->AutoSize = true;
			this->labelListenMsg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelListenMsg->Location = System::Drawing::Point(53, 70);
			this->labelListenMsg->Name = L"labelListenMsg";
			this->labelListenMsg->Size = System::Drawing::Size(78, 20);
			this->labelListenMsg->TabIndex = 12;
			this->labelListenMsg->Text = L"Message:";
			this->labelListenMsg->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// labelListenPort
			// 
			this->labelListenPort->AutoSize = true;
			this->labelListenPort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelListenPort->Location = System::Drawing::Point(42, 44);
			this->labelListenPort->Name = L"labelListenPort";
			this->labelListenPort->Size = System::Drawing::Size(89, 20);
			this->labelListenPort->TabIndex = 11;
			this->labelListenPort->Text = L"Listen Port:";
			this->labelListenPort->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tabControlUDPvsTCP
			// 
			this->tabControlUDPvsTCP->Controls->Add(this->tabPage1);
			this->tabControlUDPvsTCP->Controls->Add(this->tabPage2);
			this->tabControlUDPvsTCP->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlUDPvsTCP->Location = System::Drawing::Point(0, 0);
			this->tabControlUDPvsTCP->Name = L"tabControlUDPvsTCP";
			this->tabControlUDPvsTCP->SelectedIndex = 0;
			this->tabControlUDPvsTCP->Size = System::Drawing::Size(384, 243);
			this->tabControlUDPvsTCP->TabIndex = 13;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tabControlUDPtypes);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(376, 217);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"UDP";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabControlUDPtypes
			// 
			this->tabControlUDPtypes->Controls->Add(this->tabPage3);
			this->tabControlUDPtypes->Controls->Add(this->tabPage4);
			this->tabControlUDPtypes->Controls->Add(this->tabPage5);
			this->tabControlUDPtypes->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControlUDPtypes->Location = System::Drawing::Point(3, 3);
			this->tabControlUDPtypes->Name = L"tabControlUDPtypes";
			this->tabControlUDPtypes->SelectedIndex = 0;
			this->tabControlUDPtypes->Size = System::Drawing::Size(370, 211);
			this->tabControlUDPtypes->TabIndex = 13;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->labelEndInt);
			this->tabPage3->Controls->Add(this->checkBoxLoop);
			this->tabPage3->Controls->Add(this->labelStartInt);
			this->tabPage3->Controls->Add(this->textBoxEndInt);
			this->tabPage3->Controls->Add(this->textBoxStartInt);
			this->tabPage3->Controls->Add(this->comboBox1);
			this->tabPage3->Controls->Add(this->checkBoxDesc);
			this->tabPage3->Controls->Add(this->labelDstPort);
			this->tabPage3->Controls->Add(this->labelDstIP);
			this->tabPage3->Controls->Add(this->labelMessage);
			this->tabPage3->Controls->Add(this->textBoxDestMsg);
			this->tabPage3->Controls->Add(this->textBoxDestAddr);
			this->tabPage3->Controls->Add(this->textBoxDestPort);
			this->tabPage3->Controls->Add(this->buttonSendUDP);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(362, 185);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"Send";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// labelEndInt
			// 
			this->labelEndInt->AutoSize = true;
			this->labelEndInt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelEndInt->Location = System::Drawing::Point(66, 121);
			this->labelEndInt->Name = L"labelEndInt";
			this->labelEndInt->Size = System::Drawing::Size(65, 20);
			this->labelEndInt->TabIndex = 14;
			this->labelEndInt->Text = L"End Int:";
			this->labelEndInt->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// checkBoxLoop
			// 
			this->checkBoxLoop->AutoSize = true;
			this->checkBoxLoop->Location = System::Drawing::Point(248, 125);
			this->checkBoxLoop->Name = L"checkBoxLoop";
			this->checkBoxLoop->Size = System::Drawing::Size(50, 17);
			this->checkBoxLoop->TabIndex = 13;
			this->checkBoxLoop->Text = L"Loop";
			this->checkBoxLoop->UseVisualStyleBackColor = true;
			// 
			// labelStartInt
			// 
			this->labelStartInt->AutoSize = true;
			this->labelStartInt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelStartInt->Location = System::Drawing::Point(60, 94);
			this->labelStartInt->Name = L"labelStartInt";
			this->labelStartInt->Size = System::Drawing::Size(71, 20);
			this->labelStartInt->TabIndex = 12;
			this->labelStartInt->Text = L"Start Int:";
			this->labelStartInt->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// textBoxEndInt
			// 
			this->textBoxEndInt->Location = System::Drawing::Point(137, 122);
			this->textBoxEndInt->Name = L"textBoxEndInt";
			this->textBoxEndInt->Size = System::Drawing::Size(100, 20);
			this->textBoxEndInt->TabIndex = 11;
			this->textBoxEndInt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxStartInt
			// 
			this->textBoxStartInt->Location = System::Drawing::Point(137, 96);
			this->textBoxStartInt->Name = L"textBoxStartInt";
			this->textBoxStartInt->Size = System::Drawing::Size(100, 20);
			this->textBoxStartInt->TabIndex = 10;
			this->textBoxStartInt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Single", L"Stream" });
			this->comboBox1->Location = System::Drawing::Point(243, 18);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(96, 21);
			this->comboBox1->TabIndex = 9;
			this->comboBox1->Text = L"Single/Stream";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::comboBox1_SelectedIndexChanged);
			// 
			// checkBoxDesc
			// 
			this->checkBoxDesc->AutoSize = true;
			this->checkBoxDesc->Location = System::Drawing::Point(248, 99);
			this->checkBoxDesc->Name = L"checkBoxDesc";
			this->checkBoxDesc->Size = System::Drawing::Size(83, 17);
			this->checkBoxDesc->TabIndex = 8;
			this->checkBoxDesc->Text = L"Descending";
			this->checkBoxDesc->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->labelLocalIP);
			this->tabPage4->Controls->Add(this->textBoxLocalIP);
			this->tabPage4->Controls->Add(this->buttonListenUDP);
			this->tabPage4->Controls->Add(this->labelListenMsg);
			this->tabPage4->Controls->Add(this->textBoxListenMsgUDP);
			this->tabPage4->Controls->Add(this->labelListenPort);
			this->tabPage4->Controls->Add(this->textBoxListenPort);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(362, 185);
			this->tabPage4->TabIndex = 1;
			this->tabPage4->Text = L"Listen";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// labelLocalIP
			// 
			this->labelLocalIP->AutoSize = true;
			this->labelLocalIP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelLocalIP->Location = System::Drawing::Point(61, 18);
			this->labelLocalIP->Name = L"labelLocalIP";
			this->labelLocalIP->Size = System::Drawing::Size(70, 20);
			this->labelLocalIP->TabIndex = 14;
			this->labelLocalIP->Text = L"Local IP:";
			this->labelLocalIP->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// textBoxLocalIP
			// 
			this->textBoxLocalIP->Location = System::Drawing::Point(137, 18);
			this->textBoxLocalIP->Name = L"textBoxLocalIP";
			this->textBoxLocalIP->Size = System::Drawing::Size(100, 20);
			this->textBoxLocalIP->TabIndex = 13;
			// 
			// tabPage5
			// 
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(362, 185);
			this->tabPage5->TabIndex = 2;
			this->tabPage5->Text = L"Echo";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(376, 217);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"TCP";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// backgroundWorkerListenUDP
			// 
			this->backgroundWorkerListenUDP->WorkerSupportsCancellation = true;
			this->backgroundWorkerListenUDP->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::backgroundWorkerListenUDP_DoWork);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 243);
			this->Controls->Add(this->tabControlUDPvsTCP);
			this->Name = L"GUI";
			this->Text = L"Ethernet Tool";
			this->tabControlUDPvsTCP->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabControlUDPtypes->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	bool listening = false;
	bool desc;
	bool loop;
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (comboBox1->SelectedItem->ToString() == "Single")
		{
			textBoxDestMsg->Enabled = true;
			textBoxStartInt->Enabled = false;
			textBoxEndInt->Enabled = false;
			checkBoxDesc->Enabled = false;
			checkBoxLoop->Enabled = false;
			buttonSendUDP->Text = L"Send";
		}
		else if (comboBox1->SelectedItem->ToString() == "Stream")
		{
			textBoxDestMsg->Enabled = false;
			textBoxStartInt->Enabled = true;
			textBoxEndInt->Enabled = true;
			checkBoxDesc->Enabled = true;
			checkBoxLoop->Enabled = true;
			buttonSendUDP->Text = L"Stream";
		}
	}

	private: System::Void buttonListenUDP_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listening == false)
		{
			listening = true;
			buttonListenUDP->Text = L"Listening";
			int listenPortNumUDP = System::Convert::ToInt32(textBoxListenPort->Text);
			this->backgroundWorkerListenUDP->RunWorkerAsync(listenPortNumUDP);
		}
		else
		{
			listening = false;
			buttonListenUDP->Text = L"Listen";
			this->backgroundWorkerListenUDP->CancelAsync();
		}
	}

private: System::Void backgroundWorkerListenUDP_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	System::ComponentModel::BackgroundWorker^ workerListenUDP = dynamic_cast<BackgroundWorker^>(sender);
	socketUDP listenUDP;
	listenUDP.portNum= safe_cast<Int32>(e->Argument);
	listenUDP.open();
	listenUDP.listen(workerListenUDP, e);
	listenUDP.close();
}

};
}
