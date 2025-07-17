#include "Animal.hpp"
#include "WrongAnimal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "\n------- WrongAnimal test -------" << std::endl;
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	delete wrongCat;

	// This is anxample of working of the classical polymorphism
	printf("\n-----------Classic polymorphism-----------\n");
	Animal *animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Animal();

	for (int i = 0; i < 4; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}