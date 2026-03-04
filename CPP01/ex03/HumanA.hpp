#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA{
	private:
		std::string name;
		Weapon& weapon_A;
	public:
		HumanA(std::string name, Weapon& weapon_A);
		void attack(void);
};

#endif