#include <iostream>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
    // std::cout << "ZombieEvent called" << std::endl;
    this->type = "default";
}

ZombieEvent::~ZombieEvent(void) {
    // std::cout << "ZombieEvent deleted" << std::endl;
}

void ZombieEvent::setZombieType(std::string type) {
    this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
    Zombie *zombie = new Zombie(name, this->type);

    return zombie;
}
