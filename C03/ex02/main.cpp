#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap basic("BasicBot");
	basic.attack("Enemy");

	std::cout << "----------------------" << std::endl;

	ScavTrap scav("Guardian");
	scav.attack("Intruder");
	scav.guardGate();

	std::cout << "----------------------" << std::endl;

	FragTrap frag("Bomber");
	frag.attack("Target");
	frag.highFivesGuys();

	std::cout << "----------------------" << std::endl;

	return 0;
}