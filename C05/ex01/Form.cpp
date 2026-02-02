#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form " << name << " created" << std::endl;
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}


void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
	{
		throw GradeTooLowException();
	}
	isSigned = true;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form " << f.getName()
	<< ", signed: " << (f.getIsSigned() ? "yes" : "no") // otherwise it will return 0 or 1
	<< ", grade required to sign: " << f.getGradeToSign()
	<< ", grade required to execute: " << f.getGradeToExecute();
	return out;
}