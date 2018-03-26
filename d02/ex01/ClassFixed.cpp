// Fixed
#include "ClassFixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
    std::cout << "Constructor Fixed called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(Fixed const & rhs) {
    std::cout << "Assignation operator called";
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor Fixed called" << std::endl;
}
