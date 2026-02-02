#include "Zombie.hpp"

int main()
{
	// Zombie *z1 = newZombie("Heap");
	// if (!z1)
	// 	return 1;
	// z1->announce();
	
	// randomChump("Stack");
	// delete z1;

	Zombie *horde = zombieHorde(5, "Name");
	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
	return 0;
}