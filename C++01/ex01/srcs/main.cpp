
#include "../includes/Zombie.hpp"

#include <iostream>
int main()
{
	int no = 8;
	std::string name = "Bee";

	std::cout << "Test with Horde 0---" << std::endl;

	Zombie* test_horde_0 = zombieHorde(0, name);
	
	delete[] test_horde_0;

	std::cout << "Test with Horde 8---" << std::endl;
	Zombie* test_horde_1 = zombieHorde(no, name);

	std::cout << "Horde Annouce---" << std::endl;
	for (int i = 0; i < no; i++)
	{
		test_horde_1[i].announce();
	}
	std::cout << "Horde Delete---" << std::endl;
	delete[] test_horde_1;
	return 0;
}