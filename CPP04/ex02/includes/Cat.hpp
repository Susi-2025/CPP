#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "../includes/Brain.hpp"
#include "../includes/Animal.hpp"

class Cat: public Animal{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		
		void makeSound() const override;
		void setIdea(int i, std::string idea);
		std::string getIdea(int i) const;
};

#endif