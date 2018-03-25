#include <iostream>
#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain called" << std::endl;
    this->qi = 150;
    this->stupidity = 999;
}

const Brain *Brain::identify(void) const{
    return this;
}

Brain::~Brain(void) {
    std::cout << "Brain deleted" << std::endl;
}