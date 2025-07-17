#include "Animal.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "Basic test:\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;
	// const Animal *ani = new Animal(); // now this string will break the whole code
	std::cout << "\nArray of Animals:\n";
	const int size = 10;
	Animal* animals[size];

	for (int i = 0; i < size / 2; ++i)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; ++i)
		animals[i] = new Cat();

	for (int i = 0; i < size; ++i)
		delete animals[i];

	std::cout << "\nDeep Copy Test:\n";
	Dog dog1;
	dog1.makeSound();
	Dog dog2 = dog1; // copy constructor
	dog2.makeSound();
	return 0;
}