#pragma once

#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")

void openSocket();
void sendPackets();
void closeSocket();