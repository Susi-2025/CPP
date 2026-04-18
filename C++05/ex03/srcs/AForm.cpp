
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const int sign_grade, const int exec_grade):
    _name(name),
    _signed(false) ,
    _sign_grade(sign_grade),
    _exec_grade(exec_grade)
{
    if(_sign_grade < 1 || _exec_grade < 1)
        throw GradeTooHighException();
    if (_sign_grade > 150 || _exec_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other):
    _name(other._name), 
    _signed(other._signed) , 
    _sign_grade(other._sign_grade),
    _exec_grade(other._exec_grade){}

AForm:: ~AForm(){}

const std::string& AForm::getName() const{
    return _name;
}

bool AForm::getSigned() const{
    return _signed;
}
int AForm::getSignGrade() const{
    return _sign_grade;
}
int AForm::getExecGrade() const{
    return _exec_grade;
}

const char* AForm::GradeTooHighException:: what() const noexcept{
    return "Grade is too High!!!";
}

const char* AForm::GradeTooLowException:: what() const noexcept{
    return "Grade is too Low!!!";
}

const char* AForm::FormNotSignedException:: what() const noexcept{
    return "Form is not yet signed so couldn't be executed";
}

void AForm::beSigned(const Bureaucrat& obj)
{
    if (_signed)
        throw std::logic_error("Form already signed");
    if (obj.getGrade() <= this->getSignGrade())
        _signed = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const& executor) const{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _exec_grade)
        throw GradeTooLowException();
    executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj){
    os << obj.getName() << " can be signed from grade: " << obj.getSignGrade()
    << " can be executed from grade: " << obj.getExecGrade() 
    << " , is signed: " << (obj.getSigned() ? "Yes" : "No") << std::endl;
    return os;
}