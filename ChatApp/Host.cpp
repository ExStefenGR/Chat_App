#include "Host.h"

void Host::HostMain()
{
	host.HostInitialise();
	host.HostOpenSocket();
	std::thread t5(&TCP::HostListenSocket,&host);
	t5.join();
	while (true)
	{
		std::thread t3(&TCP::HostReceiveMessage,&host);
		std::thread t4(&TCP::HostSendMessage,&host);
		t4.detach();
		t3.join();
	}
}
