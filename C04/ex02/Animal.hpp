#pragma once

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void makeSound() const = 0; // делает класс абстрактным, теперь к нему напрямую нельзя получуть доступ (только к его наследникам)
		std::string getType() const;
};
