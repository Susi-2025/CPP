
#include "../includes/HumanA.hpp"
#include "../includes/Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weaponA)
: _name(name), _weapon_A(weaponA)
{
	std::cout << "Human A " << name << " Constructor called" << std::endl;

}

HumanA::~HumanA()
{
	std::cout << "Human A Destructor called " << std::endl;
}
	
void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon_A.getType() << std::endl;
}