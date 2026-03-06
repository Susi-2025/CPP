
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(){ 
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	_name  ="default";
	_hit_pts = 100;
	_energy_pts = 50;
	_atk_dmg = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap " << name <<" Constructor called" << std::endl;
	_name  = name;
	_hit_pts = 100;
	_energy_pts = 50;
	_atk_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other){
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	std::cout << "ScavTrap " << other._name << " Copy Assignment Constructor called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << this->_name << " Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_atk_dmg << " points of damage!" << std::endl;
	 	this->_energy_pts--;
	}
	else if (this->_energy_pts <= 0 && this->_hit_pts > 0)
		std::cout << "ScavTrap " << this->_name <<" is End of energy!"<< std::endl;
	else if (this->_energy_pts <= 0 && this->_hit_pts <= 0)
		std::cout << "ScavTrap  " << this->_name << " is dead and can't attack!"<< std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}