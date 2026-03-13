
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "-------Memory address printout-----" << std::endl;
	std::cout << "Mem address of string variable:\t"<< &str << std::endl;
	std::cout << "Mem address hold by stringPTR:\t"<< stringPTR << std::endl;
	std::cout << "Mem address hold by stringREF:\t"<< &stringREF << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::cout << "-------Value printout-----" << std::endl;
	std::cout << "The value of string variable:\t"<< str << std::endl;
	std::cout << "The value pointed by stringPTR:\t"<< *stringPTR << std::endl;
	std::cout << "The value pointed by stringREF:\t"<< stringREF << std::endl;
	std::cout << "---------------------------" << std::endl;
	return 0;
}