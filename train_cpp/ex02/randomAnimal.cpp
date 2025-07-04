#include "newAnimal.hpp"

void	Animal::makeSound()
{
	std::cout << type << " make sound" << std::endl;
}

void	Animal::randomAnimal(std::string type)
{
	this->type = type;
	makeSound();
}