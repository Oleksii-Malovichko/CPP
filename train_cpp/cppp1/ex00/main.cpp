#include "Zombie.hpp"

int main()
{
	Zombie *z1 = newZombie("Heap");
	if (!z1)
		return 1;
	z1->announce();
	
	randomChump("Stack");
	delete z1;
	return 0;
}