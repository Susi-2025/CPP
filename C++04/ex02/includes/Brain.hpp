#pragma once
#include <string>

class Brain
{
	protected:
		std::string _ideas[100];
	
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
		
		void setIdea(const std::string& str, int i);
		const std::string getIdea(int i) const;
};