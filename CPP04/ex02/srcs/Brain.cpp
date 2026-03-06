#include "../includes/Brain.hpp"
#include <iostream>

Brain::Brain(){
	std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain Copy Assigment Constructor Called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain Destructor Called" << std::endl;
}

void Brain::setIdea(int i, std::string idea)
{
	std::cout << "Set Ideas at " << i << " position." << std::endl;
	_ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{	
	std::cout << "Get Ideas at " << i << " position." << std::endl;
	return _ideas[i];
}