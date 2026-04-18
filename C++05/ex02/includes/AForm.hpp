
#pragma once

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class AForm{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _sign_grade;
        const int           _exec_grade;

    protected:
        virtual void executeAction() const = 0; // execute # actions in # forms

    public:
        AForm() = delete;
        AForm& operator=(const AForm& other) = delete;
        AForm(const std::string& name, const int sign_grade, const int exec_grade);
        AForm(const AForm& other);
        virtual ~AForm();

        const std::string& getName() const;
        bool getSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        class GradeTooHighException: public std::exception{
            const char* what() const noexcept override;
        };

        class GradeTooLowException: public std::exception{
            const char* what() const noexcept override;
        };

        class FormNotSignedException: public std::exception{
            const char* what() const noexcept override;
        };

        void beSigned(const Bureaucrat& obj);
        void execute(Bureaucrat const & executor) const;

        virtual const std::string& getTarget() const = 0; // need for abstract
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);