#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(void);
		HumanA(std::string str, Weapon &weapon);
		void	attack();
		void	setWeapon(Weapon club);
		~HumanA();
};

#endif