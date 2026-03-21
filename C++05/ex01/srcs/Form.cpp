#include "Form.hpp"

Form::Form(const std::string& name, const int grade_sign, const int grade_exec):
 _name(name), _signed(0) ,_grade_sign(grade_sign), _grade_exec(grade_exec){
	if (_grade_sign < 1 || _grade_exec < 1)
		throw GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other): _name(other._name), _signed(other._signed),
_grade_sign(other._grade_sign), _grade_exec(other._grade_exec){}

Form::~Form(){};

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeSign() const
{
	return _grade_sign;
}

int Form::getGradeExec() const
{
	return _grade_exec;
}

const char* Form::GradeTooHighException:: what() const noexcept{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException:: what() const noexcept{
	return "Grade is too low!";
}

void Form::beSigned(const Bureaucrat& b)
{
	if (_signed)
		return;

	if (b.getGrade() > _grade_sign)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& output)
{
	out << output.getName() << ", can be signed from grade: " << output.getGradeSign()
		<< ", can be executed from grade: " << output.getGradeExec()
		<< ", currently signed: " << (output.getSigned() ? "Yes" : "No");
	return out;
}