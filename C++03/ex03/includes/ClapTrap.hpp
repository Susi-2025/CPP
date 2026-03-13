#pragma once

#include <string>

class ClapTrap
{
	protected: 
		std::string _name;
		int _hit_pts;
		int _energy_pts;
		int _atk_dmg;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		virtual ~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

