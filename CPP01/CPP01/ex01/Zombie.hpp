
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie{
private:
	std::string name;
public:
	Zombie(); //default constructor for creating array of Zombie
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif