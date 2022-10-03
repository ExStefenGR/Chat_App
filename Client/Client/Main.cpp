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

	const std::string ipAddress = "localHost";
	TCPsocket socket = nullptr;

	if (SDLNet_ResolveHost(&ip, ipAddress.c_str(), port) == -1)
	{
		std::cout << "Could not enstablish connection" << std::endl;
		system("Pause");
		return 0;
	}
	socket = SDLNet_TCP_Open(&ip);
	if (!socket)
	{
		std::cout << "Could not connect" << std::endl;
		system("pause");
		return 0;
	}

	std::cout << "connect to server" << std::endl;

	SDLNet_Quit();
	SDL_Quit();
	system("pause");
	return 0;
}