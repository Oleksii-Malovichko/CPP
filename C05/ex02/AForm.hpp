#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	const std::string name;
	bool isSigned; // default status: no
	const int gradeToSign;
	const int gradeToExecute;
	protected:
		virtual void executeAction() const = 0;
	public:
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		void beSigned(const Bureaucrat &b);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		// new
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);