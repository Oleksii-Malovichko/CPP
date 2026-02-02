#pragma once

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	const std::string name;
	int grade; // от 1 до 150
	public:
		// Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		virtual ~Bureaucrat(); // not necessary but for the future inheritances (maybe)

		void signForm(Form &form);
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		// nested classes for exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
				// {
				// 	return "Grade is too high!";
				// }
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
				// {
				// 	return "Grade is too low!";
				// }
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b); // for a beuty output