#pragma once

#include "Weapon.hpp"

class HumanB
{
    Weapon *weapon;
    std::string name;
    public:
        // HumanB();
        HumanB(std::string name);
        ~HumanB();
        void attack() const;
        void setWeapon(Weapon &weapon);
};