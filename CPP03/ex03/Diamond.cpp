
#include "Diamond.hpp"
#include <string>
#include <iostream>

Diamond::Diamond()
{
	std::cout << "Diamond Default Constructor called" << std::endl;
	_name = "default";
	this->_hit_pts = FragTrap::_hit_pts;
	this->_energy_pts = ScavTrap::_energy_pts;
	this->_atk_dmg = FragTrap::_atk_dmg;
}

Diamond::Diamond(std::string name) 
	: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap " << name <<" Constructor called" << std::endl;
	_name = name;
	_hit_pts = FragTrap::_hit_pts;
	_energy_pts = ScavTrap::_energy_pts;
	_atk_dmg = FragTrap::_atk_dmg;
}

Diamond::Diamond(const Diamond& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other)
{	std::cout << "DiamondTrap " << other._name << " Copy Constructor called" << std::endl;
	*this = other;
}

Diamond& Diamond::operator=(const Diamond& other)
{	
	std::cout << "DiamondTrap " << other._name << " Copy Assignment Constructor called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

Diamond::~Diamond(){
	std::cout << "DiamondTrap " << _name <<" Destructor called" << std::endl;
}

void Diamond::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void Diamond::whoamI()
{
	std::cout << "I am DiamondTrap with the name is: " << _name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}
