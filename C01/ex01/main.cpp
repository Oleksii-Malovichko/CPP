#include "Zombie.hpp"

int main()
{
	int n = 5;
	Zombie *horde = zombieHorde(n, "Horde ");
	if (!horde)
	{
		perror("malloc");
		return 1;
	}
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}