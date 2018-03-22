#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : name(name), type(type) {
    std::cout << "Zombie called" << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie deleted" << std::endl;
}

void Zombie::announce(void) const {
    std::cout << "<" << this->name << " (" << this->type;
    std::cout << ")> > Braiiiiiiinnnssss..." << std::endl;
}
