
#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

#include <iostream>
int main()
{
	{
		std::cout << "-----Test with Human A---" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		std::cout << "-------------------------" << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "------Test with Human B ---" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		std::cout << "-------------------------" << std::endl;
	}
	return 0;
}