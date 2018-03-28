#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) {
    std::cout << "Zombie called" << std::endl;
}

void Zombie::initZombie(std::string name, std::string type){
    this->name = name;
    this->type = type;
}

Zombie::~Zombie(void) {
    std::cout << "Zombie deleted" << std::endl;
}

void Zombie::announce(void) const {
    std::cout << "<" << this->name << " (" << this->type;
    std::cout << ")> Braiiiiiiinnnssss..." << std::endl;
}
