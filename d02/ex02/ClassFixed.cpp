// Fixed
#include "ClassFixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_bits = 8;

#define FRAC(v) (1 << v)
#define INT_FIXED(x, bits) ((x) << bits)
#define FIXED_INT(x, bits) ((x) >> bits)
#define FLOAT_FIXED(x, bits) (x * FRAC(bits))
#define FIXED_FLOAT(x, bits) (((float)(x)) / FRAC(bits))

// #define FIXED_MULT(x, y) ((x)*(y) >> FRACT_BITS)
// #define FIXED_DIV(x, y) (((x)<<FRACT_BITS) / (y))

Fixed::Fixed(void): _raw(0) {
    (void)Fixed::_bits;
    // std::cout << "Default Constructor Fixed called" << std::endl;
}

Fixed::Fixed(int const value): _raw(INT_FIXED(value, this->_bits)) {
    std::cout << "Int Constructor Fixed called with " << value << " to " << this->_raw << std::endl;
}

Fixed::Fixed(float const value): _raw(roundf(FLOAT_FIXED(value, this->_bits))) {
    std::cout << "Float Constructor Fixed called with " << value << " to " << this->_raw << std::endl;
}

Fixed::Fixed(Fixed const & src) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(Fixed const & rhs) {
    // std::cout << "Assignation operator called" << std::endl;
    this->_raw = rhs.getRawBits();
    return *this;
}

bool Fixed::operator>(Fixed const & rhs) {
    return this->_raw > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs) {
    return this->_raw < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs) {
    return this->_raw >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs) {
    return this->_raw <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs) {
    return this->_raw == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs) {
    return this->_raw != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const & rhs) {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) {
    this->_raw /= rhs.getRawBits();
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old(*this);
    --(*this);
    return old;
}

Fixed Fixed::operator--() {
    this->_raw--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old(*this);
    ++(*this);
    return old;
}

Fixed Fixed::operator++() {
    this->_raw++;
    return *this;
}

Fixed& Fixed::min(Fixed &s1, Fixed &s2) {
    if(s1.getRawBits() < s2.getRawBits())
        return s1;
    return s2;
}

const Fixed& Fixed::min(Fixed const & s1, Fixed const &s2) {
    if(s1.getRawBits() < s2.getRawBits())
        return s1;
    return s2;
}

Fixed& Fixed::max(Fixed &s1, Fixed &s2) {
    if(s1.getRawBits() > s2.getRawBits())
        return s1;
    return s2;
}

const Fixed& Fixed::max(Fixed const & s1, Fixed const &s2) {
    if(s1.getRawBits() > s2.getRawBits())
        return s1;
    return s2;
}

int Fixed::getRawBits() const{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw) {
    this->_raw = raw;
}

float Fixed::toFloat(void) const {
    return FIXED_FLOAT(this->_raw, this->_bits);
}

int Fixed::toInt(void) const {
    return FIXED_FLOAT(this->_raw, this->_bits);
}

std::ostream& operator<<(std::ostream& o, Fixed const &i) {
    o << i.toFloat();
    return o;
}

Fixed::~Fixed(void) {
    // std::cout << "Destructor Fixed called" << std::endl;
}
