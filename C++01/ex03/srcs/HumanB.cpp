
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
: _name(name), _weapon_B(NULL)
{
	std::cout << "HumanB " << name << " Constructor called" << std::endl;

}

HumanB::~HumanB()
{
	std::cout << "HumanB Destructor called " << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon_B = &weapon;
	std::cout << "HumanB Set Weapon called " << std::endl;
}
	
void HumanB::attack()
{
	if (_weapon_B)
		std::cout << this->_name << " attacks with their "
			<<_weapon_B->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}