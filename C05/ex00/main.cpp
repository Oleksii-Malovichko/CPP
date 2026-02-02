#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		Bureaucrat sam("Sam", 5);
		sam = bob;
		std::cout << sam << std::endl; // now the grade must be 2 (copy from bob)
		bob.incrementGrade(); // will be 1
		std::cout << bob << std::endl;
	
		std::cout << "-------CREATING COPY--------" << std::endl;
		Bureaucrat copy(bob);
		std::cout << copy << std::endl; // it's already bob!

		copy.incrementGrade(); // will be 0 andddd the exception!
		std::cout << copy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "-------------------" << std::endl;
	try
	{
		Bureaucrat alex("Alex", 151); // the constructor in this case must not be working!!!
		std::cout << alex << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
	}
	return 0;
}