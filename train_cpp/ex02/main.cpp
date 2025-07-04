#include "newAnimal.hpp"

int main()
{
	Animal animal;
	animal.randomAnimal("Cat");

	Animal *animal2 = Animal::newAnimal("Dog");
	animal2->makeSound();
	delete animal2;
	return 0;
}