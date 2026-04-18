
#include "Intern.hpp"

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    AForm* res=nullptr;
    const std::string formNames[3]=
    {
        "shrubbery request",
        "robotomy request", 
        "presidential request"
    };
    try{
        int choice = 0;
        for (int i = 0; i < 4 ; i++)
        {
            if (i == 3){
                throw std::runtime_error("requested form doesn't exist");
            }
            if (formNames[i] == name){
               choice = i;
               break;
            }
        }
        switch(choice){
            case 0:
                res = new ShrubberyCreationForm(target);
                break;
            case 1:
                res = new RobotomyRequestForm(target);
                break;
            case 2:
                res = new PresidentialPardonForm(target);
                break;
        }
        std::cout << "Intern creates " << res->getName() << std::endl;
        return res;
    } catch (const std::exception& ) {
        std::cout << "Form create failed: ";
        throw;
    }
}