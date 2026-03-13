
#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), 
	ScavTrap(), FragTrap(), _name("default")
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	_hit_pts = 100;
	_energy_pts = 50;
	_atk_dmg = 30;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"),
	ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	_hit_pts = 100;
	_energy_pts = 50;
	_atk_dmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), 
	ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "Diamond copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Diamond copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
		return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name <<" destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap whose name is " << _name << std::endl; 
	std::cout <<" My ClapTrap name is: " << ClapTrap::_name << std::endl;
}