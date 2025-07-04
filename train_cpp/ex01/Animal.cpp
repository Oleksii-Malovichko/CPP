#include "Animal.hpp"

void	Animal::makeSound()
{
	std::cout << type << " make sound" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
}