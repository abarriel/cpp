// Fixed
#include "ClassFixed.hpp"
#include <iostream>

Fixed::Fixed(void): _raw(0), _bits(8) {
    (void)Fixed::_bits;
    std::cout << "Default Constructor Fixed called" << std::endl;
}

Fixed::Fixed(Fixed const & src): _bits(8) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(Fixed const & rhs) {
    std::cout << "Assignation operator called" << std::endl;
    this->_raw += rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw) {
    this->_raw = raw;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor Fixed called" << std::endl;
}
