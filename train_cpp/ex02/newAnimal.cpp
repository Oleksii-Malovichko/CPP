#include "newAnimal.hpp"

Animal::Animal(std::string type) : type(type) {}

Animal::Animal() {};

Animal::~Animal() {}

Animal *Animal::newAnimal(std::string type)
{
	return (new Animal(type));
}