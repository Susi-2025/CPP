
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void )
{

	std::cout << "-------Test with create ClapTrap A, copy B, operator C-----" << std::endl;
	ClapTrap A("Hive");
	ClapTrap B(A);
	ClapTrap C("Byyyy");
	C = A;
	std::cout << std::endl;
	
	std::cout << "-------Test with normal ClapTrap A: atk, takeDMG and healed-----" << std::endl;
	A.attack("CPP");
	A.takeDamage(5);
	A.beRepaired(9);
	std::cout << std::endl;

	std::cout << "-------Test with normal ClapTrap B: atk, takeDMG and healed-----" << std::endl;
	B.attack("Helsin");
	B.takeDamage(20);
	B.beRepaired(9);
	B.attack("Aarg");
	B.takeDamage(10);
	std::cout << std::endl;

	std::cout <<"---------Test for FragTrap with name Bocal----------------------------" << std::endl;

	FragTrap F("Bocal");

	F.attack("Joensu");
	F.takeDamage(5);
	F.beRepaired(9);
	F.highFivesGuys();

	std::cout << std::endl;

	std::cout <<"---------Test for FragTrap Copy----------------------------" << std::endl;
	FragTrap G(F);

	G.takeDamage(200);
	G.beRepaired(9);
	G.highFivesGuys();
	
	std::cout << std::endl;

	return 0;
}
