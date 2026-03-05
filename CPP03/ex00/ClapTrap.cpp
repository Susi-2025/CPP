
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): _name("default"), _hit_pts(10), _energy_pts(10), _atk_dmg(0){
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
	_name = name;
	_hit_pts = 10;
	_energy_pts= 10;
	_atk_dmg = 0;
	std::cout << "ClapTrap " << name <<" Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap&  other){
	this->_name = other._name;
	this->_hit_pts = other._hit_pts;
	this->_energy_pts= other._energy_pts;
	this->_atk_dmg = other._atk_dmg;
	return *this;
}

ClapTrap:: ~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_pts > 0 && this->_hit_pts > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ",causing " << this->_atk_dmg << " points of damage!" << std::endl;
	 	this->_energy_pts--;
	}
	else if (this->_energy_pts < 0 && this->_hit_pts > 0)
		std::cout << "End of energy!"<< std::endl;
	else if (this->_energy_pts < 0 && this->_hit_pts <= 0)
		std::cout << "ClapTrap is dead and can't attack!"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_pts <= 0)
	{
		std::cout << "ClapTrap is already dead!"<< std::endl;
		return;
	}
	std::cout << "Take Damage!!"<< std::endl;
	this->_hit_pts -= amount;
	std::cout << "Health is " << this->_hit_pts << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_pts <= 0)
	{
		std::cout << "End of energy!"<< std::endl;
		return;
	}
	if (this->_hit_pts <= 0)
	{
		std::cout << "Already dead and can't be repaired!"<< std::endl;
		return;
	}
	std::cout << "beRepaired!!"<< std::endl;
	this->_hit_pts += amount;
	this->_energy_pts--;
	std::cout << "Health is " << this->_hit_pts << std::endl;
}