#include "Animal.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructed." << std::endl;
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assigned." << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructed." << std::endl;
}

void	Cat::makeSound() const
{
	delete brain;
	std::cout << "Meow!" << std::endl;
}
