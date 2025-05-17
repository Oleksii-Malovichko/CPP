#include "Zombie.hpp"

int main()
{
	Zombie *alloc = newZombie("heap: ");

	if (!alloc)
	{
		perror("malloc");
		return (1);
	}
	alloc->announce();
	delete alloc;

	randomChump("stack: ");
	return (0);
}