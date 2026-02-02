#include "ClapTrap.hpp"

int main()
{
	ClapTrap c1("Jack");
	ClapTrap c2("Bob");

	std::cout << "\n--- ATTACK TEST ---" << std::endl;
	c1.attack("Bob");
	std::cout << "\n--- DAMAGE TEST ---" << std::endl;
	c2.takeDamage(5);
	std::cout << "\n--- REPAIR TEST ---" << std::endl;
	c2.beRepaired(3);
	std::cout << "\n--- DAMAGE UNTIL DEATH ---" << std::endl;
	c2.takeDamage(20);
	std::cout << "\n--- TRY ACTIONS WHEN DEAD ---" << std::endl;
	c2.attack("Jack");
	c2.beRepaired(5);
	std::cout << "\n--- ENERGY DRAIN TEST ---" << std::endl;
    for (int i = 0; i < 11; i++)
	{
        c1.attack("target");
	}
	std::cout << "\n--- COPY & ASSIGNMENT TEST ---" << std::endl;
	ClapTrap c3 = c1;
	ClapTrap c4;
	c4 = c2;
}