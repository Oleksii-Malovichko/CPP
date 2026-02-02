#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name(name)
{
	// this->name = name;
	std::cout << name << " constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}