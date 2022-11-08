#pragma once
#include "TCPHost.h"
#include <thread>
class Host
{
public:

	Host();
	~Host();

	int HostMain();

private:
	TCPHost host{};
};

