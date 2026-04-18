
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
}
        
Bureaucrat::Bureaucrat(const Bureaucrat& obj): _name(obj._name), _grade(obj._grade){}

Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const
{
    return this->_name;
}

int  Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade(){
    if (_grade <= 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade(){
    if (_grade >=150)
        throw GradeTooLowException();
    else
        _grade++;
}

const char* Bureaucrat::GradeTooHighException:: what() const noexcept{
    return "Grade is too high, 1 is the top!";
}

const char* Bureaucrat::GradeTooLowException:: what() const noexcept{
    return "Grade is too low, 150 is the bottom!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(AForm& obj)
{
    try{
        obj.beSigned(*this);
        std::cout << _name << " signed " << obj.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << obj.getName()
            << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form)
{
    try{
        form.execute(*this);
        std::cout << form.getName() << " is executed by " << _name << std::endl;
    }
    catch (std::exception& e) {
        std::cout << form.getName() << " couldn't be executed by " << _name << " because ";
        throw ; // 
    }
}