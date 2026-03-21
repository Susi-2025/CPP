
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){}
		
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){}
		

const char* Bureaucrat::GradeTooHighException:: what() const noexcept{
	return "Grade is too high, 1 is the top!";
}

const char* Bureaucrat::GradeTooLowException:: what() const noexcept{
	return "Grade is too low, 150 is the bottom!";
}

const std::string& Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incrementGrade(){
	if (_grade < 1)
		throw GradeTooHighException();
	else
		--_grade;
}

void Bureaucrat::decrementGrade(){
	if (_grade > 150)
		throw GradeTooLowException();
	else
		++_grade;

}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj){
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << " .";
	return out;
}