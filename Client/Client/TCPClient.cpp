#include "TCPClient.h"

TCPClient::TCPClient()
{
	if (SDLNet_Init() == 1)
	{
		std::cout << "SDL net could not initialise" << std::endl;
		system("pause");
	}
}
TCPClient::~TCPClient()
{
	SDLNet_Quit();
}

int TCPClient::Connect()
{
	if (SDLNet_ResolveHost(&ip, "localhost", PORT) == -1)
	{
		std::cout << "could not establish connection with server" << std::endl;
		return 0;
	}
	socket = SDLNet_TCP_Open(&ip);
	if (!socket)
	{
		std::cout << "could not connect to server" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Connection to server successful" << std::endl;
		SendMessage();
	}
}

void TCPClient::SendMessage()
{
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
	system("pause");
}
