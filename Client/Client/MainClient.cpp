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

	if (SDLNet_ResolveHost(&ip, "localhost", port) == -1)
	{
		std::cout << "could not establish connection with server" << std::endl;
		return 0;
	}
	TCPsocket socket = SDLNet_TCP_Open(&ip);
	if (!socket)
	{
		std::cout << "could not connect to server" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Connection to server successful" << std::endl;
	}
	char message[2000];
	//receive a message from the client and store
	if (SDLNet_TCP_Recv(socket, message, 2000) <= 0)
	{
		std::cout << "message could not be received" << std::endl;
	}
	else
	{
		std::cout << "message from " << socket << ": " << message << std::endl;
	}


	SDLNet_Quit();
	SDL_Quit();
	system("pause");
	return 0;
}