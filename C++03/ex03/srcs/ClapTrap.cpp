
#include "ClapTrap.hpp"
#include <iostream>
#include <cmath>

ClapTrap::ClapTrap()
	: _name("default"), _hit_pts(10), _energy_pts(10), _atk_dmg(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name), _hit_pts(10), _energy_pts(10), _atk_dmg(0)
{
	std::cout << "ClapTrap Constructor " << _name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if(this != &other){
		this->_name = other._name;
		this->_hit_pts = other._hit_pts;
		this->_energy_pts = other._energy_pts;
		this->_atk_dmg = other._atk_dmg;
	}
	return *this;
}
	
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap "<< _name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit_pts <= 0)
	{
		std::cout << "ClapTrap "<< _name << " is dead. Scope couldn't attack" << std::endl;
	}
	else if (_hit_pts > 0 && _energy_pts <= 0)
		std::cout << "ClapTrap "<< _name << " has zero energy pts. Can't attack" << std::endl;
	else if (_hit_pts > 0 && _energy_pts > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
		<< _atk_dmg << " points of damage!" << std::endl;
		_energy_pts--;
		std::cout << "His energy is: "<< _energy_pts << std::endl;
		std::cout << target << " lost " << _atk_dmg << " hit points!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_pts <= 0)
		std::cout << "ClapTrap "<< _name << " is already dead. Can't be damaged anymore" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " was attacked with " << amount
		<< " points of damage!" << std::endl;
		_hit_pts -= amount;
		if (_hit_pts <= 0)
			std::cout << "ClapTrap "<< _name << " is dead due to takeDamage" << std::endl;
		std::cout << "His health is: "<< _hit_pts << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_pts <= 0)
		std::cout << "ClapTrap "<< _name << " is already dead. Can't heal anymore"
		<< std::endl;
	else
	{
		if (_energy_pts <= 0)
			std::cout << "ClapTrap has zero energy pts. Can't heal itself" << std::endl;
		else
		{
			if (amount <= 0)
				std::cout << "Couldn't heal. Poisonous heal" << std::endl;
			else
			{
				std::cout << "ClapTrap " << _name << " was healed with " << amount
				<< " points of health!" << std::endl;
				_hit_pts += amount;
				std::cout << "His health is: "<< _hit_pts << std::endl;
				_energy_pts--;
				std::cout << "His energy is: "<< _energy_pts << std::endl;
			}
		}
	}
}
