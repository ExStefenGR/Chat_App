#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include "TCPClient.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Could not initialise" << std::endl;
		system("pause");
		return 0;
	}
	TCPClient clientConnection;
	clientConnection.Initialise();
	clientConnection.ReceiveMessage();
	SDL_Quit();
	return 0;
}