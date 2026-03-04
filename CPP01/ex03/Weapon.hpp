
#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon{
private:
	std::string type;

public:
	Weapon(std::string weaponType);
	void setType(std::string weaponType);
	const std::string& getType();
};

#endif