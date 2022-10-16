#pragma once
#include <SDL_net.h>
#include <iostream>
constexpr auto PORT = 1234;
class TCPClient
{
public:
	TCPClient();
	~TCPClient();

	int Connect();
	void SendMessage();

private:
	IPaddress ip{};
	TCPsocket socket{};
};