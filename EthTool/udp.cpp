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
	std::cout << "Socket opened." << std::endl;

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
	std::cout << "Socket closed." << std::endl;

	//Terminate Winsock dll.
	WSACleanup();
	std::cout << "Clean up success" << std::endl;
};
