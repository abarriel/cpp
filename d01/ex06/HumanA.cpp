#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {
    // std::cout << "Constructor HumanA called" << std::endl;
}

void HumanA::attack(void) const{
    std::cout << this->_name  << " attacks with his " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(void) {
    // std::cout << "Destructor HumanA called" << std::endl;
}
