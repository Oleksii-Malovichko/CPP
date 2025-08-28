#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copied." << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongCat assigned." << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow (WrongCat)" << std::endl;
}