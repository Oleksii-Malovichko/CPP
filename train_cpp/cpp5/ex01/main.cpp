#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat alex("Alex", 10); // high level
		Bureaucrat bob("Bob", 100);

		Form form("Form", 50, 50);

		std::cout << alex << std::endl;
		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		// now we're trying to sign the form
		alex.signForm(form);
		std::cout << form << std::endl;

		// will cause an exception
		bob.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught in MAIN: " << e.what() << std::endl;
	}
	return 0;
}