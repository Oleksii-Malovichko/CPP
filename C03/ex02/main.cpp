#include "FragTrap.hpp"

int main()
{
	FragTrap c1("Jack");
	FragTrap c2("Bob");

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
	std::cout << "\n--- HIGH FIVE ---" << std::endl;
	c1.highFivesGuys();
	c2.highFivesGuys();
	std::cout << "\n--- ENERGY DRAIN TEST ---" << std::endl;
    for (int i = 0; i < 12; i++)
	{
        c1.attack("target");
	}
	std::cout << "\n--- COPY & ASSIGNMENT TEST ---" << std::endl;
	FragTrap c3 = c1;
	FragTrap c4;
	c4 = c2;
}