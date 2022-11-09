#pragma once
#include <SDL.h>
#include <SDL_Net.h>
#include <iostream>
#include <thread>
#include <string>

class TCP
{
	//=============Host Mode=============
public:
	TCP() = default;
	~TCP() = default;
	bool HostInitialise();
	bool HostOpenSocket();
	void HostListenSocket();
	bool HostSendMessage();
	bool HostReceiveMessage();
	int m_port{ 2345 };

private:
	TCPsocket m_listenSocket = 0;
	TCPsocket m_clientSocket = 0;
	int m_maxSockets{ 6 };
	//=============Client mode=============
public:
	bool ClientInitialise();
	bool ClientSendMessage();
	bool ClientReceiveMessage();

private:
	IPaddress m_clientIp{};

	//=======Shared Access==========
public:
	void Shutdown();
	IPaddress m_serverIp{};
	//SDLNet_SocketSet m_checker{};  <--This would be useful to avoid blocking but there is no proper documentation
};