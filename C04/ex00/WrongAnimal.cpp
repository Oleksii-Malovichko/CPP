#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal constructed." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructed." << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound (generic)" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructed." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow (WrongCat)" << std::endl;
}