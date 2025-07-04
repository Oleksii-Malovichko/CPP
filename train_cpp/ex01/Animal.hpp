#pragma once

#include <iostream>
#include <string>

class Animal
{
	private:
		std::string type;
	public:
		Animal(std::string type);
		void	makeSound();
};