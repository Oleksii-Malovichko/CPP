#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string &name) : type(name) {}

const std::string &Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}

Weapon::~Weapon() {}