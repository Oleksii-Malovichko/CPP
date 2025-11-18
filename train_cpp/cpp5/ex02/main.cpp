#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL)); // for RobotomyRequestForm::executeAction

	try
	{
		Bureaucrat bob("Bob", 50);
		Bureaucrat alex("Alex", 1);
		Bureaucrat sophie("Sophie", 150);

		std::cout << std::endl;
		ShrubberyCreationForm shrubForm("home");
		RobotomyRequestForm robotForm("Marvin");
		PresidentialPardonForm pardonForm("Ford");

		std::cout << std::endl;

		std::cout << shrubForm << std::endl;
		std::cout << robotForm << std::endl;
		std::cout << pardonForm << std::endl;

		std::cout << std::endl << "== SIGNING FORMS ==" << std::endl;
		bob.signForm(shrubForm);
		bob.signForm(robotForm);
		bob.signForm(pardonForm);

		alex.signForm(shrubForm);
		alex.signForm(robotForm);
		alex.signForm(pardonForm);

		sophie.signForm(shrubForm);
		sophie.signForm(robotForm);
		sophie.signForm(pardonForm);

		std::cout << std::endl << "== EXECUTING FORMS ==" << std::endl;
		bob.executeForm(shrubForm);
		bob.executeForm(robotForm);
		bob.executeForm(pardonForm);

		alex.executeForm(shrubForm);
		alex.executeForm(robotForm);
		alex.executeForm(pardonForm);

		sophie.executeForm(shrubForm);
		sophie.executeForm(robotForm);
		sophie.executeForm(pardonForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught in main: " << e.what() << '\n';
	}
	return 0;
}