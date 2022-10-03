#include <iostream>
#include <SDL.h>
#include <SDL_net.h>

IPaddress ip;
const int port = 1234;
int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Could not initialise" << std::endl;
		system("pause");
		return 0;
	}

	else if (SDLNet_Init() == 1)
	{
		std::cout << "SDL net could not initialise" << std::endl;
		system("pause");
		return 0;
	}

	TCPsocket listenSocket = nullptr;
	TCPsocket clientSocket = nullptr;

	listenSocket = SDLNet_TCP_Open(&ip);
	if (!listenSocket)
	{
		clientSocket = SDLNet_TCP_Accept(listenSocket);
		std::cout << ".";
		SDL_Delay(500);
	}
	while (!clientSocket)
	{
		clientSocket = SDLNet_TCP_Accept(listenSocket);
		std::cout << ".";
		SDL_Delay(500);
	}

	SDLNet_TCP_Close(listenSocket);
	std::cout << std::endl << "Client Connected." << std::endl << std::endl;
	SDLNet_Quit();
	SDL_Quit();
	return 0;
}