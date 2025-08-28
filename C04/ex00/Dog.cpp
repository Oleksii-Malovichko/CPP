#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copied." << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Dog assigned." << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructed." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

