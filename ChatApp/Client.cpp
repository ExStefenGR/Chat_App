#include "Client.h"

Client::Client()
{
}

Client::~Client()
{
}

int Client::ClientMain()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Could not initialise" << std::endl;
		system("pause");
		return 0;
	}
	m_clientConnection.Initialise();
	m_clientConnection.ReceiveMessage();
	SDL_Quit();
	return 0;
}
