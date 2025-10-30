#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wepon)
{
    std::cout << "HumanA constructed" << std::endl;
    this->weapon = wepon;
}

HumanA::~HumanA()
{
    std::cout << "HumanA deconstructed" << std::endl;
}

void    HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}