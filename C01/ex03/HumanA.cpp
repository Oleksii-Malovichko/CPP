#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name)
{
    std::cout << "HumanA constructed" << std::endl;
    // this->weapon = wepon; // ошибка!!! реферные ссылки нужно инициализировать в списке инициализации
}

HumanA::~HumanA()
{
    std::cout << "HumanA deconstructed" << std::endl;
}

void    HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}