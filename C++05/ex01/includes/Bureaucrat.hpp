
#pragma once

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat{

    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat() = delete;
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& obj);
        Bureaucrat& operator=(const Bureaucrat& obj) = delete;
        ~Bureaucrat();

        const std::string& getName() const;
        int  getGrade() const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException: public std::exception{
            const char* what() const noexcept override;
        };
        class GradeTooLowException: public std::exception{
            const char* what() const noexcept override;
        };

        void signForm(Form& obj);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);