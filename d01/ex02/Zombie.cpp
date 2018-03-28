#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : name(name), type(type) {
    std::cout << name << " Zombie called" << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << this->name << " Zombie deleted" << std::endl;
}

void Zombie::announce(void) const {
    std::cout << "<" << this->name << " (" << this->type;
    std::cout << ")> Braiiiiiiinnnssss..." << std::endl;
}
