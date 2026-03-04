
#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name ){
	if (N <= 0)
		return NULL;
	
	Zombie* horde = new Zombie[N];
	for(int i = 0; i < N; i++)
	{
		horde[i] = Zombie(name);
		std::cout << "Zombie " << i << " is created" << std::endl;
		//zombie.annouce();
	}
	return horde;
}