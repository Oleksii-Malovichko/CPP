#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Hitter 1");
	a.attack("Target");
	a.takeDamage(5);
	a.beRepaired(3);
	a.attack("Target2");
	return 0;
}