
#include "../includes/Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "N must be positive." << std::endl;
		return NULL;
	}

	Zombie* Horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		Horde[i].setName(name);
	}
	return Horde;
}