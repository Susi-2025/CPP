#pragma once
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();

		std::string getType() const;
		// void setType(std::string const &type);
		
		void makeSound() const;

};