#pragma once

#include "Weapon.hpp"

class HumanA
{
    Weapon &weapon;
    std::string name;
    public:
        // HumanA();
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void    attack() const;
};