#include "TCPHost.h"

TCPHost::~TCPHost()
{
	SDLNet_TCP_Close(listenSocket);
	SDLNet_Quit();
}

void TCPHost::OpenSocket()
{
	if (SDLNet_Init() == 1)
	{
		std::cout << "SDL net could not initialise" << std::endl;
		system("pause");
	}
	if (SDLNet_ResolveHost(&ip, nullptr, PORT) == -1)
	{
		//could not create a server
	}
	listenSocket = SDLNet_TCP_Open(&ip);
	if (!listenSocket)
	{
		std::cout << "server socket closed for clients" << std::endl;
	}
	else
	{
		std::cout << "server socket open for clients" << std::endl;
	}
	clientSocket = 0;
	while (!clientSocket)
	{
		clientSocket = SDLNet_TCP_Accept(listenSocket);
		std::cout << "." << std::endl;
		SDL_Delay(500u);
	}
}

void TCPHost::WelcomeMessage(std::string welcome)
{
	//store length of message
	int length = welcome.length() + 1;
	//send the above message to the client via the socket
	if (SDLNet_TCP_Send(clientSocket, welcome.c_str(), length) < length)
	{
		std::cout << "message not sent" << std::endl;
	}
	else
	{
		std::cout << "message sent" << std::endl;
	}
	system("pause");
}