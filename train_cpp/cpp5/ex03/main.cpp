#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;

	std::cout << "\n==== TEST 1: Correct form creation ====\n";
	try
	{
		AForm* f1 = intern.makeForm("shrubbery creation", "Home");
		std::cout << *f1 << std::endl;
		delete f1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		AForm* f2 = intern.makeForm("robotomy request", "Bender");
		std::cout << *f2 << std::endl;
		delete f2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		AForm* f3 = intern.makeForm("presidential pardon", "Morty");
		std::cout << *f3 << std::endl;
		delete f3;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==== TEST 2: Wrong form name ====\n";
	try
	{
		AForm* bad = intern.makeForm("wrong name", "Nobody");
		delete bad;
	}
	catch (std::exception &e)
	{	
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n==== TEST 3: Sign + Execute created forms ====\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		AForm* form = intern.makeForm("robotomy request", "RoboTarget");
	
		std::cout << *form << std::endl;
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\n==== TEST 4: Intern creates all forms in loop ====\n";
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++) {
		try
		{
			AForm* f = intern.makeForm(names[i], "TargetXYZ");
			std::cout << "Created: " << f->getName() << std::endl;
			delete f;
		}
		 catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}

// int main()
// {
// 	srand(time(NULL)); // for RobotomyRequestForm::executeAction

// 	try
// 	{
// 		Bureaucrat bob("Bob", 50);
// 		Bureaucrat alex("Alex", 1);
// 		Bureaucrat sophie("Sophie", 150);


// 		std::cout << std::endl;
// 		ShrubberyCreationForm shrubForm("home");
// 		RobotomyRequestForm robotForm("Marvin");
// 		PresidentialPardonForm pardonForm("Ford");

// 		std::cout << std::endl;

// 		std::cout << shrubForm << std::endl;
// 		std::cout << robotForm << std::endl;
// 		std::cout << pardonForm << std::endl;

// 		std::cout << std::endl << "== SIGNING FORMS ==" << std::endl;
// 		bob.signForm(shrubForm);
// 		bob.signForm(robotForm);
// 		bob.signForm(pardonForm);

// 		alex.signForm(shrubForm);
// 		alex.signForm(robotForm);
// 		alex.signForm(pardonForm);

// 		sophie.signForm(shrubForm);
// 		sophie.signForm(robotForm);
// 		sophie.signForm(pardonForm);

// 		std::cout << std::endl << "== EXECUTING FORMS ==" << std::endl;
// 		bob.executeForm(shrubForm);
// 		bob.executeForm(robotForm);
// 		bob.executeForm(pardonForm);

// 		alex.executeForm(shrubForm);
// 		alex.executeForm(robotForm);
// 		alex.executeForm(pardonForm);

// 		sophie.executeForm(shrubForm);
// 		sophie.executeForm(robotForm);
// 		sophie.executeForm(pardonForm);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "Exception caught in main: " << e.what() << '\n';
// 	}
// 	return 0;
// }