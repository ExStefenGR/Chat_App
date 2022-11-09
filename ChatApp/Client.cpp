#include "Client.h"

void Client::ClientMain()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Could not initialise" << std::endl;
	}
	client.ClientInitialise();
	while (true)
	{
		std::thread t2(&TCP::ClientSendMessage, client);
		t2.detach();
		std::thread t1(&TCP::ClientReceiveMessage, client);
		t1.join();
	}
}
