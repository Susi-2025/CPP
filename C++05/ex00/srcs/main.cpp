
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "-------------NORMAL CASES-----------------" << std::endl;
    try{
        Bureaucrat a("A", 8);
        std::cout << "a bureaucrat is: " << a << std::endl;
        std::cout << a << std::endl;
        Bureaucrat b(a);
        std::cout << "b bureaucrat is: " << b << std::endl;
        a.incrementGrade();
        std::cout << "new a bureaucrat is: " << a << std::endl;
        b.decrementGrade();
        std::cout << "new b bureaucrat is: " << b << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 0] " << e.what() << std::endl;
    }

    std::cout << "-------------TOO HIGH CASES-----------------" << std::endl;
    try{
        Bureaucrat a("A", 0);
        std::cout << "a bureaucrat is: " << a << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 1] " << e.what() << std::endl;
    }

    std::cout << "-------------TOO LOW CASES-----------------" << std::endl;
    try{
        Bureaucrat a("A", 151);
        std::cout << "a bureaucrat is: " << a << std::endl;
    } catch (std::exception& e) {
        std::cout << "[ERROR 1] " << e.what() << std::endl;
    }
}