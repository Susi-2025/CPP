
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(): name("") {}
Zombie::Zombie(std::string name): name(name) {}
Zombie::~Zombie(){
	std::cout << " has been destroy" << std::endl;
}

void Zombie::announce(void){
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;	
};