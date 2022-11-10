#include <SDL.h>

#include <iostream>

#include "Client.h"
#include "Host.h"
int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        std::cout << "Could not initialise" << std::endl;
        system("pause");
        return 1;
    }
    int mode{};
    std::cout << "=============== Please select Mode: ===========================" << std::endl;
    std::cout << R"(|			1. Host Mode			|)" << std::endl;
    std::cout << R"(|			2. Client Mode			|)" << std::endl;
    std::cout << "===============================================================" << std::endl;

    while (true)
    {
        std::cin >> mode;

        if (mode == 1)
        {
            Host host{};
            host.HostMain();
        }
        else if (mode == 2)
        {
            Client client{};
            client.ClientMain();
        }
        else
        {
            std::cin.clear();
        }
    }
    return 0;
}
