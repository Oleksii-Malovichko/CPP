#pragma once

#include <iostream>
#include <string>

class Animal
{
	std::string type;
	public:
		Animal(std::string type);
		Animal();

		~Animal();
		static Animal *newAnimal(std::string type);
		void	makeSound();
		void	randomAnimal(std::string type);	
};

