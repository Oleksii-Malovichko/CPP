#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	AForm *createShrubbery(const std::string &target);
	AForm *createRobotomy(const std::string &target);
	AForm *createPresidential(const std::string &target);
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		
		AForm* makeForm(const std::string &formName, const std::string &target);
};

