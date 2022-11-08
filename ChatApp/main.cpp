#include "Host.cpp"
#include "Client.cpp"
#include <iostream>
int main(int argc, char* argv[])
{
	int mode{};
	std::cout << "Please select Mode: " << std::endl;
	std::cout << "1. Host Mode" << std::endl;
	std::cout << "2. Client Mode" << std::endl;

	while (true)
	{
		std::cin >> mode;

		if (mode == 1)
		{
			//Host mode
		}
		else if (mode == 2)
		{
			//Client mode
		}
		else
		{
			std::cin.clear();
		}
	}
	return 0;
}
