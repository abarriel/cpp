#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name): _name(name) {
    // std::cout << "Constructor HumanB called" << std::endl;
}

void HumanB::attack(void) const {
    std::cout << this->_name  << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

HumanB::~HumanB(void) {
    // std::cout << "Destructor HumanB called" << std::endl;
}