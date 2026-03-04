
#include "Weapon.h"

Weapon::setType(std::string& weaponType) {
	type = weaponType;
}
const std::string& Weapon::getType() {
	return type;
};
