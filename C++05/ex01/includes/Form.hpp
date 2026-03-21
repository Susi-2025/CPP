
#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; 

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exec;
	
		public:
			Form() = delete;
			~Form();
			Form(const std::string& name, const int grade_sign, const int grade_exec);
			Form(const Form& other);
			Form& operator=(const Form& other) = delete;

			const std::string& getName() const;
			bool getSigned() const;
			int getGradeSign() const;
			int getGradeExec() const;

			class GradeTooHighException : public std::exception{
				public:
					const char* what() const noexcept override;
			};
			class GradeTooLowException: public std::exception{
				public:
					const char* what() const noexcept override;
			};
			void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const Form& output);