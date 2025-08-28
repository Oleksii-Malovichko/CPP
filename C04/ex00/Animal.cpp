#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructed." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copied" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal assigned." << std::endl;
	return *this;
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