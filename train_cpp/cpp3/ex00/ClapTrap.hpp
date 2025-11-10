#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
	public:
		ClapTrap(); // конструктор по умолчанию
		ClapTrap(const std::string &name); // конструктор с именем
		ClapTrap(const ClapTrap &other); // копирующий конструктор
		ClapTrap &operator=(const ClapTrap &other); // оператор присваивания
		~ClapTrap(); // деструктор
	
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};