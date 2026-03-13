#include <iostream>
#include "../includes/Harl.hpp"

int main()
{
	Harl Harl_test;
	std::cout << "----------Debug testing---------" << std::endl;
	Harl_test.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "----------Info testing---------" << std::endl;
	Harl_test.complain("INFO");
	std::cout << std::endl;

	std::cout << "----------Warning testing---------" << std::endl;
	Harl_test.complain("WARNING");
	std::cout << std::endl;

	std::cout << "----------Error testing---------" << std::endl;
	Harl_test.complain("ERROR");
	std::cout << std::endl;

	return 0;
}