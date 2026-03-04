
#include <iostream>
#include "Harl.hpp"

int main()
{
	Harl Harl_test;
	std::cout << "Debug testing:" << std::endl;
	Harl_test.complain("DEBUG");
	std::cout << "Info testing:" << std::endl;
	Harl_test.complain("INFO");
	std::cout << "Warning testing:" << std::endl;
	Harl_test.complain("WARNING");
	std::cout << "Error testing:" << std::endl;
	Harl_test.complain("ERROR");
	return 0;
}