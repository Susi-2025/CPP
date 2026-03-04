
#include <iostream>
#include "Harl.hpp"

int main(int ac, char** av)
{
	Harl Harl_test;
	std::string level;

	if (ac != 2)
	{
		std::cout << "Usage ./harlFilter <level>" << std::endl;
		return 1;
	}
	Harl_test.complain(av[1]);
	return 0;
}