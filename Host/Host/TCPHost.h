#pragma once
#include <iostream>
#include <SDL_net.h>
constexpr auto PORT = 1234;
class TCPHost
{
public:
	TCPHost() = default;
	~TCPHost();

	bool Initialise();
	void Shutdown();
	bool OpenSocket();
	void ListenSocket();
	void CloseSocket();

	bool WelcomeMessage(std::string welcome);

	bool SendMessage(std::string message);
	void ReceiveMessage();
private:
	IPaddress m_ip{};
	TCPsocket listenSocket{};
	TCPsocket clientSocket{};
	char m_textRecv[2000]{};
	std::string m_textSend{};
};