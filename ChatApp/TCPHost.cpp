#include "TCPHost.h"

TCPHost::~TCPHost()
{
	SDLNet_Quit();
}

bool TCPHost::Initialise()
{
	if (SDLNet_Init() == 1)
	{
		std::cout << "SDL net could not initialise" << std::endl;
		system("pause");
		return false;
	}
	if (SDLNet_ResolveHost(&m_ip, nullptr, 1234) == -1)
	{
		//test
	}
	return true;
}

void TCPHost::Shutdown()
{
	SDLNet_Quit();
}

bool TCPHost::OpenSocket()
{
	if (SDLNet_Init() == 1)
	{
		std::cout << "SDL net could not initialise" << std::endl;
		return false;
	}
	if (SDLNet_ResolveHost(&m_ip, nullptr, m_port) == -1)
	{
		//could not create a server
		return false;
	}

	return 0;
}

void TCPHost::ListenSocket()
{
	listenSocket = SDLNet_TCP_Open(&m_ip);
	if (!listenSocket)
	{
		std::cout << "server socket closed for clients" << std::endl;
	}
	else
	{
		std::cout << "server socket open for clients" << std::endl;
	}
	while (!clientSocket)
	{
		clientSocket = SDLNet_TCP_Accept(listenSocket);
		std::cout << "." << std::endl;
		SDL_Delay(500u);
	}
}

void TCPHost::CloseSocket()
{
	SDLNet_TCP_Close(listenSocket);
	SDLNet_TCP_Close(clientSocket);
}

bool TCPHost::WelcomeMessage(std::string welcome)
{
	//store length of message
	int length = welcome.length() + 1;
	//send the above message to the client via the socket
	if (SDLNet_TCP_Send(clientSocket, welcome.c_str(), length) < length)
	{
		std::cout << "message not sent" << std::endl;
		return false;
	}
	std::cout << "message sent" << std::endl;
	return true;
}

bool TCPHost::SendMessage(std::string message)
{
	std::cout << "Host: ";
	std::cin >> message;
	int length = message.length() + 1;
	if (SDLNet_TCP_Send(clientSocket, message.c_str(), length) < length)
	{
		std::cout << "Error: message not sent" << std::endl;
		return false;
	}
	std::cout << "message sent" << std::endl;
	return true;
}

void TCPHost::ReceiveMessage()
{
	while (true)
	{
		if (SDLNet_TCP_Recv(clientSocket, &m_textRecv, 2000) > 2000)
		{
			std::cout << "Error: message not received fully" << std::endl;
		}
		else
		{
			std::cout << "Message from " << clientSocket << " " << m_textRecv << std::endl;
			if (m_textRecv == "end")
			{
				Shutdown();
			}
		}
	}
}

int TCPHost::GetPort()
{
	return m_port;
}
