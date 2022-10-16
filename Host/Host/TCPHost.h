#pragma once
#include <iostream>
#include <SDL_net.h>
constexpr auto PORT = 1234;
class TCPHost
{
public:
	TCPHost();
	~TCPHost();

	void OpenSocket();
	void WelcomeMessage(std::string welcome);
private:
	IPaddress ip;
	TCPsocket listenSocket{};
	TCPsocket clientSocket{};
};