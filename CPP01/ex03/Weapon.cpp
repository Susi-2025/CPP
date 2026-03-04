
#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
	: type(weaponType)
{
}

void Weapon::setType(std::string weaponType) {
	type = weaponType;
}
const std::string& Weapon::getType() {
	return type;
};
