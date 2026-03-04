
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
class Weapon{
private:
	std::string type;

public:
	void setType(std::string& weaponType);
	const std::string& getType();
}

#endif