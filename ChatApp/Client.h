#pragma once
#include <iostream>
#include "TCP.h"
class Client
{
public:

	Client() = default;
	~Client() = default;

	void ClientMain();
private:
	TCP client{};
};

