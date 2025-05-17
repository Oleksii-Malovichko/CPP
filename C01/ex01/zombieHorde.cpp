#include "Zombie.hpp"

void	Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cout << "Value must be more than 0!" << std::endl;
		return (NULL);
	}
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return horde;
}