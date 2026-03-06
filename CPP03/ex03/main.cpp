
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "Diamond.hpp"
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

	std::cout <<"---------Test for FragTrap-----------" << std::endl;

	FragTrap E("OP Bank");

	E.attack("Customer");
	E.takeDamage(50);
	E.beRepaired(45);
	E.highFivesGuys();

	std::cout << "--------- Test for DiamondTrap -----------" << std::endl;

	Diamond F("DiamondHero");

	F.attack("FinalBoss");
	F.takeDamage(30);
	F.beRepaired(20);

	F.whoamI();

	std::cout << "--------- Copy Tests -----------" << std::endl;

	Diamond G = F;
	G.whoamI();
	return 0;
}