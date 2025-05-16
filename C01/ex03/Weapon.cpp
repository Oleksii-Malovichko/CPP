#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string str)
{
	this->str = str;
}

const std::string &Weapon::getType() const
{
	return (str);
}

void Weapon::setType(std::string name)
{
	this->str = name;
}

Weapon::~Weapon() {}