#include "Host.h"

void Host::HostMain()
{
	host.HostInitialise();
	host.HostOpenSocket();
	host.HostListenSocket();
	while (true)
	{
		std::thread t3(&TCP::HostReceiveMessage, host);
		t3.detach();
		std::thread t4(&TCP::HostSendMessage, host);
		t4.join();
	}
}
