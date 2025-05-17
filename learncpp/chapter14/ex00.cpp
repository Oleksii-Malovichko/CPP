#include <iostream>
#include <string>

enum AnimalType
{
	snake,
	dog,
	chicken,
};

std::string animalName(AnimalType type)
{
	if (type == snake)
		return "snake";
	else if (type == dog)
		return "dog";
	else if (type == chicken)
		return "chicken";
	else
		return NULL;
}

int	numLegs(AnimalType type)
{
	if (type == snake)
		return 0;
	else if (type == dog)
		return 4;
	else if (type == chicken)
		return 2;
	else
		return 0;
}

int main()
{
	AnimalType animal = snake;
	std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs" << std::endl;
	return 0;
}