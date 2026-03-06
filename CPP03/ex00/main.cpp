
#include "ClapTrap.hpp"

#include <iostream>

int main()
{
	ClapTrap A("Hive");

	A.attack("CPP");
	A.takeDamage(5);
	A.beRepaired(9);
	ClapTrap B = A;
	B.takeDamage(20);
	B.beRepaired(9);
	ClapTrap C(B);
	return 0;
}