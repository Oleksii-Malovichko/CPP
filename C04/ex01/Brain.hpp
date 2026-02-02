#pragma once

#include "Animal.hpp"
// #include "Cat.hpp"
// #include "Dog.hpp"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();
};