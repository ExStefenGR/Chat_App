#include "Host.h"

Host::Host()
{
}

Host::~Host()
{
	SDL_Quit();
}

int Host::HostMain()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Could not initialise" << std::endl;
		system("pause");
		return 1;
	}
	host.Initialise();
	host.OpenSocket();
	host.ListenSocket();
	host.WelcomeMessage("Hellooooooooo");
	std::thread t1(&TCPHost::ReceiveMessage, &host);
	return 0;
}
