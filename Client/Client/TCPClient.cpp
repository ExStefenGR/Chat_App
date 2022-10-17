#include "TCPClient.h"

TCPClient::~TCPClient()
{
	SDLNet_Quit();
}

bool TCPClient::Initialise()
{
	if (SDLNet_Init() == 1)
	{
		std::cout << "SDL net could not initialise" << std::endl;
		return 1;
	}
	if (SDLNet_ResolveHost(&m_ip, "localhost", PORT) == -1)
	{
		std::cout << "could not establish connection with server" << std::endl;
		return 1;
	}
	m_socket = SDLNet_TCP_Open(&m_ip);
	if (!m_socket)
	{
		std::cout << "could not connect to server" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Connection to server successful" << std::endl;
		return 0;
	}
	return 0;
}

void TCPClient::Shutdown()
{
	SDLNet_TCP_Close(m_socket);
	SDLNet_Quit();
}

void TCPClient::SendMessage()
{
	std::string newMessage{};
	std::cin >> newMessage;
	int length = newMessage.length() + 1;
	if (SDLNet_TCP_Send(m_socket, newMessage.c_str(), 2000) > 2000)
	{
		std::cout << "Could not send message" << std::endl;
	}
	else
	{
		std::cout << "Message Sent" << std::endl;
		if (newMessage == "end")
		{
			Shutdown();
		}
	}
}

void TCPClient::ReceiveMessage()
{
	char message[2000];

	//receive a message from the client and store
	if (SDLNet_TCP_Recv(m_socket, message, 2000) <= 0)
	{
		std::cout << "message could not be received" << std::endl;
	}
	else
	{
		std::cout << "message from " << m_socket << ": " << message << std::endl;
		while (message != "end")
		{
			SendMessage();
		}
	}

}
