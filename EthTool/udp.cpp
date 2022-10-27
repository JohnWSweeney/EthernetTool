#include "udp.h"

void sendUDP(const char* IP, int portNum, std::string msg)
{
	//Initiate Winsock dll.
	WSADATA WinSockData;
	SOCKET UDPSocketClient;
	WSAStartup(MAKEWORD(2, 2), &WinSockData);
	std::cout << "WSAStarup success" << std::endl;

	//Create socket.
	UDPSocketClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	std::cout << "Send socket opened." << std::endl;

	//Struct with destination parameters.
	struct sockaddr_in dest;
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(IP);
	dest.sin_port = htons(portNum);

	int len = msg.size();
	const char* msgPtr;
	msgPtr = msg.data();

	// TX
	sendto(UDPSocketClient, msgPtr, len, 0, (SOCKADDR *)& dest, sizeof(dest));

	//Close socket.
	closesocket(UDPSocketClient);
	std::cout << "Send socket closed." << std::endl;

	//Terminate Winsock dll.
	WSACleanup();
	std::cout << "Clean up success" << std::endl;
};

std::string listenUDP()
{
	//Initiate Winsock dll.
	WSADATA WinSockData;
	SOCKET UDPSocketServer;
	WSAStartup(MAKEWORD(2, 2), &WinSockData);
	std::cout << "WSAStarup success" << std::endl;

	//Create socket.
	UDPSocketServer = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	std::cout << "Listen server socket opened." << std::endl;

	//Struct with destination parameters.
	struct sockaddr_in listen;
	listen.sin_family = AF_INET;
	listen.sin_addr.s_addr = INADDR_ANY;
	listen.sin_port = htons(666);

	char rxbuf[512] = { 0 };
	int rxbuflen = sizeof(rxbuf);
	int rxbytes = 0;

	bind(UDPSocketServer, (SOCKADDR *)&listen, sizeof(listen));
	
	// RX
	while(true)
	{
		rxbytes = recv(UDPSocketServer, rxbuf, rxbuflen, 0);
		std::cout << "Payload:" << rxbuf << std::endl;
		std::cout << "Payload size:" << rxbytes << std::endl;
		//return rxbuf;
	};

	//Close socket.
	closesocket(UDPSocketServer);
	std::cout << "Socket closed." << std::endl;

	//Terminate Winsock dll.
	WSACleanup();
	std::cout << "Clean up success" << std::endl;
};
