
#include "Zombie.hpp"

int main(){
	Zombie* horde_zombie = zombieHorde(8, "Hell");
	for(int i = 0; i < 8; i++)
	{
		horde_zombie[i].announce();
	}
	delete[] horde_zombie;
	return 0;
}