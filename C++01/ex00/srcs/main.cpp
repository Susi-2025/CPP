
#include "../includes/Zombie.hpp"
#include <iostream>
int main()
{
	std::cout << "Stack---" << std::endl;
	
	Zombie A;
	A.announce();
	Zombie B("Zom_name");
	B.announce();
	randomChump("Random Zomb");

	std::cout << "Heap---" << std::endl;
	Zombie* C = newZombie("Zom_New");
	C->announce();

	delete C;
	return 0;
}