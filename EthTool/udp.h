#pragma once

#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")

void sendUDP(const char* IP, int portNum, std::string msg);
void streamUDP(const char* IP, int portNum);
void listenUDP(int listenPortNumUDP, System::ComponentModel::BackgroundWorker^ workerListenUDP, System::ComponentModel::DoWorkEventArgs ^ e);

class socketUDP
{
public:
	int portNum;

	//WSADATA WinSockData;
	SOCKET UDPSocketServer;

	void open()
	{
		//Initiate Winsock dll.
		WSADATA WinSockData;
		//SOCKET UDPSocketServer;
		WSAStartup(MAKEWORD(2, 2), &WinSockData);
		std::cout << "WSAStarup success" << std::endl;

		//Create socket.
		UDPSocketServer = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		std::cout << "Listen server socket opened." << std::endl;

		//Struct with destination parameters.
		struct sockaddr_in listen;
		listen.sin_family = AF_INET;
		listen.sin_addr.s_addr = INADDR_ANY;
		listen.sin_port = htons(portNum);

		bind(UDPSocketServer, (SOCKADDR *)&listen, sizeof(listen));

		//return UDPSocketServer;
	};

	void listen(System::ComponentModel::BackgroundWorker^ workerListenUDP, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		char rxbuf[512] = { 0 };
		int rxbuflen = sizeof(rxbuf);
		int rxbytes;

		while (true)
		{
			if (workerListenUDP->CancellationPending)
			{
				e->Cancel = true;
				return;
			}
			rxbytes = recv(UDPSocketServer, rxbuf, rxbuflen, 0);
			if (rxbytes > 0)
			{
				std::cout << "Payload:" << rxbuf << std::endl;
				std::cout << "Payload size:" << rxbytes << std::endl;
			}
		}
	};

	void close()
	{
		//Close socket.
		closesocket(UDPSocketServer);
		std::cout << "Send socket closed." << std::endl;

		//Terminate Winsock dll.
		WSACleanup();
		std::cout << "Clean up success" << std::endl;
	}
};