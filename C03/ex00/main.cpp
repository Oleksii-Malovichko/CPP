#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Hitter 1");
	a.attack("Target");
	a.takeDamage(5);
	a.beRepaired(3);
	a.attack("Target2");

	std::cout << "-----------check errors------------" << std::endl;
	ClapTrap b("Clappy");
	for (int i = 0; i < 11; i++)
		b.attack("dummy");
	b.attack("no energy");
	b.takeDamage(10);
	b.attack("dead");
	b.beRepaired(5);
	return 0;
}