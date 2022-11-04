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
	const char* IP;
	int portNum;
	std::string msg;
	//void open();
	//void tx();
	//void close();

//private:
	SOCKET UDPSocketClient;

	void open()
	{
		//Initiate Winsock dll.
		WSADATA WinSockData;

		WSAStartup(MAKEWORD(2, 2), &WinSockData);
		std::cout << "WSAStarup success" << std::endl;

		//Create socket.
		UDPSocketClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		std::cout << "Send socket opened." << std::endl;

		//Struct with destination parameters.
		struct sockaddr_in sock;
		sock.sin_family = AF_INET;
		sock.sin_addr.s_addr = inet_addr(IP);
		sock.sin_port = htons(portNum);
	}

	void close()
	{
		//Close socket.
		closesocket(UDPSocketClient);
		std::cout << "Send socket closed." << std::endl;

		//Terminate Winsock dll.
		WSACleanup();
		std::cout << "Clean up success" << std::endl;
	}
};