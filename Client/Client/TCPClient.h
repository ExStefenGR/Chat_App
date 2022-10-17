#pragma once
#include <SDL_net.h>
#include <iostream>
constexpr auto PORT = 1234;
class TCPClient
{
public:
	TCPClient() = default;
	~TCPClient();

	bool Initialise();
	void Shutdown();

	void SendMessage();
	void ReceiveMessage();


private:
	IPaddress m_ip{};
	TCPsocket m_socket{};
};