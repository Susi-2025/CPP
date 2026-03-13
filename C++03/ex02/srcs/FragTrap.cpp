
#include "FragTrap.hpp"
#include <iostream>
#include <cmath>

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_name = "default";
	_hit_pts = 100;
	_energy_pts = 100;
	_atk_dmg = 30;
}
	
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_name = name;
	_hit_pts = 100;
	_energy_pts = 100;
	_atk_dmg = 30;
}
	
FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}
		
FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy operator constructor called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name <<" destructor called" << std::endl;
}
	
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap request a positive high-fives" << std::endl;
}