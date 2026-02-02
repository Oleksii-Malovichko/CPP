#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm " << name << " created" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}


void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->gradeToSign)
	{
		throw GradeTooLowException();
	}
	isSigned = true;
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm " << f.getName()
	<< ", signed: " << (f.getIsSigned() ? "yes" : "no") // otherwise it will return 0 or 1
	<< ", grade required to sign: " << f.getGradeToSign()
	<< ", grade required to execute: " << f.getGradeToExecute();
	return out;
}


// // the realisation of this func will be in only heirs classes (наследниках), in such way i dont need to create one more clear virtual func 
void AForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}