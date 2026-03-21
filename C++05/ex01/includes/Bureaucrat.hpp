
#pragma once
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;
	public:
		Bureaucrat() = delete;
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other) = delete;

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(Form& f) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
