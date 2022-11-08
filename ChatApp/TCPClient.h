#pragma once
#include <SDL2_net.h>
#include <iostream>
class TCPClient
{
public:

	TCPClient() = default;
	~TCPClient();

	bool Initialise();
	void Shutdown();

	void SendMessage();
	void ReceiveMessage();

	int GetPort();

private:
	int m_port = 1234;

	IPaddress m_ip{};
	TCPsocket m_socket{};
};