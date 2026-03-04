
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon_B(NULL){}

void HumanB::setWeapon(Weapon& weapon){
	weapon_B = &weapon;
}
void HumanB::attack(void){
	if (weapon_B)
		std::cout << name << " attacks with their " << weapon_B->getType() <<std::endl;
	else
		std::cout << name << " has no weapon!!" << std::endl;
}