#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap basic("BasicBot");
	basic.attack("Enemy");
	basic.takeDamage(3);
	basic.beRepaired(2);

	std::cout << "----------------------" << std::endl;

	ScavTrap scav("Guardian");
	scav.attack("Intruder");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "----------------------" << std::endl;

	return 0;
}