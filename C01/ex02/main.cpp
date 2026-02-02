#include <iostream>

int main()
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = var;

	std::cout << "Address of var: " << &var << std::endl;
	std::cout << "Address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << "The value of var: " << var << std::endl;
	std::cout << "The value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value of stringREF: " << stringREF << std::endl;
	
}