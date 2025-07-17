#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal(); // to do the destructor for cat and dog
		virtual void makeSound() const;
		std::string	getType() const;
};

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog();
		void	makeSound() const override;
};

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat();
		void	makeSound() const override;
};