
#include "ScavTrap.hpp"
#include <iostream>
#include <cmath>

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_name = "default";
	_hit_pts = 100;
	_energy_pts = 50;
	_atk_dmg = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap constructor called" << std::endl;
	_name = name;
	_hit_pts = 100;
	_energy_pts = 50;
	_atk_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy operator constructor called" << std::endl;
	if(this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name <<" destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit_pts <= 0)
		std::cout << "ScavTrap "<< _name << " is dead. Scope couldn't attack" << std::endl;
	if (_energy_pts <= 0)
		std::cout << "ScavTrap "<< _name << " has zero energy pts. Can't attack" << std::endl;
	if (_hit_pts > 0 && _energy_pts > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
		<< _atk_dmg << " points of damage!" << std::endl;
		_energy_pts--;
		std::cout << "His energy is: "<< _energy_pts << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (_hit_pts <= 0)
		std::cout << "ScavTrap "<< _name << " is dead. " << std::endl;
	else
		std::cout << "ScavTrap " << _name <<" is now in Gate keeper mode." << std::endl;
}