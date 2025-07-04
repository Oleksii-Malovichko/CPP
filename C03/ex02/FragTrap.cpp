#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_Frag")
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructed (default)." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << other.name << " copied." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructed." << std::endl;
}

void FragTrap::attack(const std::string& target)
{ 
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " can't attack (no energy or hit points)." << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "FragTrap " << name << " attacks " << target
	          << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}