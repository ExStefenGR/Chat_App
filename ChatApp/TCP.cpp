#include "TCP.h"

bool TCP::HostInitialise()
{
	if (SDLNet_Init() == -1)
	{
		std::cout << "Error Initialising: " << SDLNet_GetError() << std::endl;
	}
	if (SDLNet_ResolveHost(&m_serverIp, nullptr, m_port) == -1)
	{
		std::cout << "Could not create Server" << std::endl;
		std::cout << "Error: " << SDLNet_GetError() << std::endl;
		return false;
	}
	// Setting Sockets
	return true;
}

bool TCP::HostOpenSocket()
{
	m_listenSocket = SDLNet_TCP_Open(&m_serverIp);
	if (!m_listenSocket)
	{
		std::cout << "Error: " << SDLNet_GetError() << std::endl;
	}
	else
	{
		std::cout << "Socket Open to clients" << std::endl;
	}
	return false;
}

void TCP::HostListenSocket()
{
	m_clientSocket = nullptr;
	while (!m_clientSocket)
	{
		m_clientSocket = SDLNet_TCP_Accept(m_listenSocket);
		std::cout << "." << std::endl;
		SDL_Delay(500u);
	}
	m_listenSocket = m_clientSocket;
}

bool TCP::HostSendMessage()
{
	std::string serverMessage;
	std::getline(std::cin, serverMessage);
	if (int length = serverMessage.length() + 1; SDLNet_TCP_Send(m_clientSocket, serverMessage.c_str(), length) < length)
	{
		std::cout << "Error: message not sent" << std::endl;
		return false;
	}
	std::cout << "Message sent!" << std::endl;
	serverMessage.clear();
	return true;
}

bool TCP::HostReceiveMessage()
{
	char response[2000]{0};
	if (SDLNet_TCP_Recv(m_clientSocket, response, 2000) <= 0)
	{
		std::cout << "Failed to receive from Client" << std::endl;
		Shutdown();
		return false;
	}
	std::cout << "Message received from Client: " << response << std::endl;
	return true;
}

bool TCP::ClientInitialise()
{
	if (SDLNet_Init() == 1)
	{
		std::cout << "SDL net could not initialise" << std::endl;
		return true;
	}
	if (SDLNet_ResolveHost(&m_clientIp, "localhost", m_port) == -1)
	{
		std::cout << "could not establish connection with server" << std::endl;
		return true;
	}
	m_clientSocket = SDLNet_TCP_Open(&m_clientIp);
	while (!m_clientSocket)
	{
		std::cout << "could not connect to server, retrying... Error : " << SDLNet_GetError() << std::endl;
		m_clientSocket = SDLNet_TCP_Open(&m_clientIp);
	}
	std::cout << "Connection to server successful" << std::endl;
	return false;
}

bool TCP::ClientSendMessage()
{
	std::string message;
	std::getline(std::cin, message);
	if (int length = message.length() + 1; SDLNet_TCP_Send(m_clientSocket, message.c_str(), length) < length)
	{
		std::cout << "Failed to send to server" << std::endl;
		return false;
	}
	std::cout << "Message sent!" << std::endl;
	message.clear();
	return true;

}

bool TCP::ClientReceiveMessage()
{
	char response[2000]{0};
	if (SDLNet_TCP_Recv(m_clientSocket, response, 2000) <= 0)
	{
		std::cout << "Failed to receive from Server" << std::endl;
		Shutdown();
		return false;
	}
	std::cout << "Message received from Server: " << response << std::endl;
	return true;
}

void TCP::Shutdown()
{
	SDLNet_TCP_Close(m_clientSocket);
	SDLNet_TCP_Close(m_listenSocket);
	SDLNet_Quit();
	SDL_Quit();
}
