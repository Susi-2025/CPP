#pragma once
#include <string>

class AAnimal
{
	protected:
		std::string _type;
	
	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		std::string getType() const;
		// void setType(std::string const &type);
		
		virtual void makeSound() const = 0; // pure virtual->abstract

};