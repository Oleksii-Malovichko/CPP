#include "Animal.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructed." << std::endl;
	brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assigned." << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructed." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
