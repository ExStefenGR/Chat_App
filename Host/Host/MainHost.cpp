#include <SDL.h>
#include <iostream>
#include "TCPHost.h"
int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Could not initialise" << std::endl;
		system("pause");
		return 0;
	}
	TCPHost HostConnection;
	HostConnection.WelcomeMessage("Howdy doo");
	SDL_Quit();
	return 0;
}