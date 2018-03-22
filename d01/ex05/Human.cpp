#include <iostream>
#include "Human.hpp"

Human::Human(void) {
    std::cout << "Human called" << std::endl;
}

Brain& Human::getBrain(void) {
    Brain *b;
    this->brain = b;
    return *b;
}

const std::string Human::identify(void) {
    return this->brain->identify();
}

Human::~Human(void) {
    std::cout << "Human deleted" << std::endl;
}