#pragma once

#include <iostream>
#include <string>

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
	public:
		Dog();
		virtual ~Dog();
		void	makeSound() const override;
};

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		void	makeSound() const override;
};