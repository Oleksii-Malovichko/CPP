#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie constructed" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	// this->name = name;
	std::cout << name << " constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "A zombie deconstructed" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}