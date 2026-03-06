
#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap() : ClapTrap(){ 
	std::cout << "FragTrap Default Constructor called" << std::endl;
	_name  ="default";
	_hit_pts = 100;
	_energy_pts = 100;
	_atk_dmg = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap " << name <<" Constructor called" << std::endl;
	_name  = name;
	_hit_pts = 100;
	_energy_pts = 100;
	_atk_dmg = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other){
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	std::cout << "FragTrap " << other._name << " Copy Assignment Constructor called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << this->_name << " Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_atk_dmg << " points of damage!" << std::endl;
	 	this->_energy_pts--;
	}
	else if (this->_energy_pts <= 0 && this->_hit_pts > 0)
		std::cout << "FragTrap " << this->_name <<" is End of energy!"<< std::endl;
	else if (this->_energy_pts <= 0 && this->_hit_pts <= 0)
		std::cout << "FragTrap  " << this->_name << " is dead and can't attack!"<< std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " request a positive high-fives" << std::endl;
}