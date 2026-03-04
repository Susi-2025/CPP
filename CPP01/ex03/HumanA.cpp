#include "HumanA.hpp"

HumanA::HumanA(std::string& name, Weapon& weapon)
	: name(name), weapon_A(weapon)
{
}
HumanA::attack(){
	std::cout << name << " attacks with their " << weapon_A.getType() << std::endl;
}