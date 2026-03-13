#include <iostream>
#include "../includes/Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage ./harlFiter <message>" << std::endl;
		return 1;
	}

	std::string message(av[1]);
	Harl Harl_test;

	if (message != "DEBUG" && message != "INFO" && message != "ERROR" && message != "WARNING")
		message = "UNKNOWN";

	Harl_test.complain(message);
	return 0;
}