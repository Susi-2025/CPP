
#include "ClapTrap.hpp"
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
	return 0;
}
