#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <thread>
#include "TCPHost.h"
int main(int argc, char* argv[])
{
	TCPHost host;
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Could not initialise" << std::endl;
		system("pause");
		return 0;
	}
	host.Initialise();
	host.OpenSocket();
	host.ListenSocket();
	host.WelcomeMessage("Hellooooooooo");
	std::thread t1(&TCPHost::ReceiveMessage,&host);
	SDL_Quit();
	return 0;
}