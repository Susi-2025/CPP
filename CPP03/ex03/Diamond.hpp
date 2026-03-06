
#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class Diamond : public ScavTrap, public FragTrap{
	private:
		std::string _name;
	public:
		Diamond();
		Diamond(std::string name);
		~Diamond();
		Diamond (const Diamond& other);
		Diamond& operator=(const Diamond& other);
		void attack(const std::string& target);
		void whoamI(void);
};

#endif