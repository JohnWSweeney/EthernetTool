#include "udp.h"

WSADATA WinSockData;
SOCKET UDPSocketClient;

void openSocket()
{
	//Initiate Winsock dll.
	WSAStartup(MAKEWORD(2, 2), &WinSockData);
	std::cout << "WSAStarup success" << std::endl;

	//Create socket.
	UDPSocketClient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	std::cout << "Socket opened." << std::endl;
};

void sendPackets()
{
	//Struct with destination parameters.
	struct sockaddr_in dest;
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr("192.168.2.239");
	dest.sin_port = htons(666);

	std::string txbuf = "hell yeah fuckin right.";
	int txbuflen = txbuf.size();
	const char* txbufptr;
	txbufptr = txbuf.data();


	char rxbuf[512] = { 0 };
	int rxbuflen = sizeof(rxbuf);

	int txbytes = 0;
	int rxbytes = 0;

	// TX
	sendto(UDPSocketClient, txbufptr, txbuflen, 0, (SOCKADDR *)& dest, sizeof(dest));

	// RX
	do {
		rxbytes = recv(UDPSocketClient, rxbuf, rxbuflen, 0);
		std::cout << "Payload:" << rxbuf << std::endl;
		std::cout << "Payload size:" << rxbytes << std::endl;
	} while (rxbytes > 0);
};

void closeSocket()
{
	//Close socket.
	closesocket(UDPSocketClient);
	std::cout << "Socket closed." << std::endl;

	//Terminate Winsock dll.
	WSACleanup();
	std::cout << "Clean up success" << std::endl;
};
