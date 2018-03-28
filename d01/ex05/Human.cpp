#include <iostream>
#include "Human.hpp"

Human::Human(void) {
    std::cout << "Human called" << std::endl;
}

const Brain	&Human::getBrain( void ) const {
    return this->brain;
}

const Brain *Human::identify(void) const {
    return this->brain.identify();
}

Human::~Human(void) {
    std::cout << "Human deleted" << std::endl;
}
