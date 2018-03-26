#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void attack() const;
        void setWeapon(Weapon &weapon); // only one instance of weapon is created

    private:
        std::string _name;
        Weapon *_weapon; // therefor i dont need to initialized in the constructor
};
#endif