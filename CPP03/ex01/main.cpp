
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout <<"---------Test for ClapTrap-----------" << std::endl;

	ClapTrap A("Hive");

	A.attack("CPP");
	A.takeDamage(5);
	A.beRepaired(9);
	std::cout <<"---------Test for ClapTrap Copy Assignment----------" << std::endl;
	ClapTrap B = A;
	B.takeDamage(20);
	B.beRepaired(9);

	std::cout <<"---------Test for ScavTrap-----------" << std::endl;

	ScavTrap D("Bocal");

	D.attack("CPP");
	D.takeDamage(5);
	D.beRepaired(9);
	D.guardGate();	
	return 0;
}