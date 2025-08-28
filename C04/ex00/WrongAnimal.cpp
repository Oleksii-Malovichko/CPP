#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "WrongAnimal constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copied." << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongAnimal assigned." << std::endl;
	return *this;
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
