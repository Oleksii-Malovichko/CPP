#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructed." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructed." << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound (generic)" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}