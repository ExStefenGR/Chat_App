#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include "TCPClient.h"
class Client
{
public:

	Client();
	~Client();

	int ClientMain();

private:
	TCPClient m_clientConnection{};
};

