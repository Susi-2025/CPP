#pragma once
#include <string>

class AAnimal
{
	protected:
		std::string _type;
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal& other);
	
	public:
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		std::string getType() const;
		void setType(std::string const &type);
		
		virtual void makeSound() const = 0; // pure virtual->abstract

};