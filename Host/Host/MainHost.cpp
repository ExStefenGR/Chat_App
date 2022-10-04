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
	}
	if (SDLNet_ResolveHost(&ip, nullptr, 1234) == -1)
	{
		//could not create a server
	}
	TCPsocket listenSocket = SDLNet_TCP_Open(&ip);
	if (!listenSocket)
	{
		std::cout << "server socket closed for clients" << std::endl;
	}
	else
	{
		std::cout << "server socket open for clients" << std::endl;
	}
	TCPsocket clientSocket = 0;
	while (!clientSocket)
	{
		clientSocket = SDLNet_TCP_Accept(listenSocket);
		std::cout << "." << std::endl;
		SDL_Delay(500u);
	}
	//create a message to be sent to the client
	std::string message = "Hello and welcome to the chat!";
	//store length of message for use below
	int length = message.length() + 1;
	//send the above message to the client via the socket
	if (SDLNet_TCP_Send(clientSocket, message.c_str(), length) < length)
	{
		std::cout << "message not sent" << std::endl;
	}
	else
	{
		std::cout << "message sent" << std::endl;
	}
	system("pause");
	SDLNet_TCP_Close(listenSocket);
	SDLNet_Quit();
	SDL_Quit();
	return 0;
}