#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file(target + "_shrubbery");
	if (!file)
	{
		std::cerr << "Failed to create file" << std::endl;
		return ;
	}
	// just an ascii tree which i could find in Internet
	file << "        *\n";
	file << "       ***\n";
	file << "      *****\n";
	file << "     *******\n";
	file << "    *********\n";
	file << "   ***********\n";
	file << "  *************\n";
	file << " ***************\n";
	file << "       |||\n";
	file << "       |||\n";
	file.close();
}