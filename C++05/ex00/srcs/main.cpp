
#include "Bureaucrat.hpp"


int main()
{
	try {
        Bureaucrat a("A", 5);
        std::cout << a << std::endl;
        for (int i = 5; i >= 0; i++) {
            a.incrementGrade();
            std::cout << a << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "[ERROR 0] " << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;
    try {
        Bureaucrat b("AB", 155);
        std::cout << b << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 1] " << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;
    try {
        Bureaucrat c("ABC", 0);
        std::cout << c << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 2] " << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;
    try {
        Bureaucrat a("Men", 42);
        std::cout << "Original: " << a << std::endl;
        Bureaucrat b = a;                     // copy ctor
        std::cout << "Copy Constructor used to create another object!" << std::endl;
        std::cout << "Copy: " << b << std::endl;   // same grade, same name
    } catch (const std::exception& e) {
        std::cout << "[ERROR 3] " << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;
    try {
        Bureaucrat employee(Bureaucrat("Hive", 150));
        std::cout << "Copy elision: no copy constructor used, target object created using parameterized constructor!" << std::endl;
        std::cout << employee << std::endl;
    } catch (const std::exception& e) {
        std::cout << "[ERROR 4] " << e.what() << std::endl;
    }
    
	return 0;
}