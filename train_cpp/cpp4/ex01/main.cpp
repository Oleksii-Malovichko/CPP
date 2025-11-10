#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();
	// delete meta;
	// delete j;
	// delete i;
	// return 0;
	std::cout << "==CREATING ANIMALS ARRAY==" << std::endl;
	const int size = 10;
	Animal *animals[size];
	// первый 5 - собаки, остальные - коты
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "\n==DELETING ANIMALS ARRAY==" << std::endl;
	for (int i = 0; i < size; i++)
	{
		delete animals[i];
	}
	std::cout << "==DEEP COPY TEST==" << std::endl;
	Dog originalDog;
	Dog copyDog = originalDog;

	std::cout << "\nChecking if brains are diff objects in memory..." << std::endl;
	if (&originalDog == &copyDog)
		std::cout << "THEY ARE THE SAME (ERROR)" << std::endl;
	else
		std::cout << "THEY ARE DIFFERENT (OK)" << std::endl;
}