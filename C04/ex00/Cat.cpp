#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copied." << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Cat assigned." << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructed." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
