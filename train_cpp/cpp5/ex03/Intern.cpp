#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other; // nothing to copy (no fields in this constructor)
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string arr_allow_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm* (Intern::*actions[])(const std::string &) = 
	{
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential,
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == arr_allow_names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*actions[i])(target);
		}
	}
	std::cerr << "[ERROR] Intern couldn't find the form " << formName << std::endl;
	return nullptr;
}