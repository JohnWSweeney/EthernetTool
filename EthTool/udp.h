#pragma once

#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")

void sendUDP(const char* IP, int portNum, std::string msg);
std::string listenUDP(int portNum);
void echoUDP();