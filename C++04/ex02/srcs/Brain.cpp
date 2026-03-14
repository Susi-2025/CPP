#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
}
	
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment called" << std::endl;
	if (this != &other)
	{
		std::cout << "Brain copy assignment called" << std::endl;
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(const std::string& str, int index)
{
	if (index < 0 || index > 99)
	{
		std::cout << "The index of idea in brain must be 0-100." << std::endl;
		return ;
	}
	this->_ideas[index] = str;
}

const std::string Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
	{
		std::cout << "The index of idea in brain must be 0-100." << std::endl;
		return "";
	}
	if (_ideas[index].empty())
	{
		std::cout << "The idea at index " << index << " is empty."<< std::endl;
		return "";
	}
	return (_ideas[index]);
}
