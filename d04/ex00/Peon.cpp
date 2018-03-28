// Peon
#include "Peon.hpp"
#include <iostream>

Peon::Peon(void) {
    std::cout << "Default Constructor Peon called(void)" << std::endl;
}

Peon::Peon(Peon const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Peon& Peon::operator=(Peon const & rhs) {
    std::cout << "Assignation operator called";
    return *this;
}

Peon::~Peon(void) {
    std::cout << "Destructor Peon called" << std::endl;
}
