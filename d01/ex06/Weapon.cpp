#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {
    // std::cout << "Constructor Weapon called" << std::endl;
}

Weapon::~Weapon(void) {
    // std::cout << "Destructor Weapon called" << std::endl;
}

const std::string Weapon::getType(void) const {
    return this->_type;
}

void Weapon::setType(std::string type) {
    this->_type = type;
    return ;
}
