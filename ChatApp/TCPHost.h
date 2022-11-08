#pragma once
#include <iostream>
#include <>

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

	int GetPort();
private:
	IPaddress m_ip{};
	TCPsocket listenSocket{};
	TCPsocket clientSocket{};
	std::string m_textSend{};
	char m_textRecv[2000]{};
	int m_port = 1234;
};