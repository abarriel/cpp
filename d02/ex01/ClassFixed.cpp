// Fixed
#include "ClassFixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed(void): _raw(0) {
    (void)Fixed::_bits;
    std::cout << "Default Constructor Fixed called" << std::endl;
}

Fixed::Fixed(int const value): _raw(value) {
    std::cout << "Int Constructor Fixed called" << std::endl;
}

Fixed::Fixed(float const value): _raw(value / (1 << 8)) {
    std::cout << "Float Constructor Fixed called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
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

float Fixed::toFloat(void) const {
    return this->_raw;
}

int Fixed::toInt(void) const {
    return this->_raw;
}

std::ostream& operator<<(std::ostream& o, Fixed const &i) {
    o << i.toFloat();
    return o;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor Fixed called" << std::endl;
}
