
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern randomIntern;
    AForm *randomform = nullptr;

    {
        std::cout << "------------------------------" << std::endl;
        try{
            randomform = randomIntern.makeForm("shrubbery request", "home");
            Bureaucrat baby("Baby", 150);
            std::cout << *randomform << std::endl;
            std::cout << baby << std::endl;
            baby.signForm(*randomform);
            baby.executeForm(*randomform);
        } catch (const std::exception& e){
            std::cout << "[Error 1]: " << e.what() << std::endl;
        }
        delete randomform;
        randomform = nullptr;
    }
    {
        std::cout << "------------------------------" << std::endl;
        try{
            randomform = randomIntern.makeForm("robotomy request", "Bender");
            Bureaucrat baby("Parent", 50);
            std::cout << *randomform << std::endl;
            std::cout << baby << std::endl;
            baby.signForm(*randomform);
            baby.executeForm(*randomform);
        } catch (const std::exception& e){
            std::cout << "[Error 2]: " << e.what() << std::endl;
        }
        delete randomform;
        randomform = nullptr;
    }
      {
        std::cout << "------------------------------" << std::endl;
        try{
            randomform = randomIntern.makeForm("presidential request", "Bender");
            Bureaucrat baby("Family", 6);
            std::cout << *randomform << std::endl;
            std::cout << baby << std::endl;
            baby.signForm(*randomform);
            baby.executeForm(*randomform);
        } catch (const std::exception& e){
            std::cout << "[Error 3]: " << e.what() << std::endl;
        }
        delete randomform;
        randomform = nullptr;
    }
    return 0;
}