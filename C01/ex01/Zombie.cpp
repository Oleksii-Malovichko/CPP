#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << " A zombie is constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << " A zombie is deconstructed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << "BraiiiiiiinnnzzzZ..." << std::endl;
}
