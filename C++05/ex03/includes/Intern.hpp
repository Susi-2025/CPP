
#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    public:
        Intern() = default;
        Intern (const Intern& other)= default;
        Intern& operator=(const Intern& other) = default;
        ~Intern() =default ;
    
        AForm* makeForm(const std::string& name, const std::string &target);

};