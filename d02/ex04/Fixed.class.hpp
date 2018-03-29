// Fixed
#ifndef CLASSFIXED_HPP
#define CLASSFIXED_HPP
#include <iostream>

class Fixed {
public:
    Fixed(void); // Canonical
    Fixed(int const value);
    Fixed(float const value);
    Fixed(Fixed const & src); // Canonical
    ~Fixed(void); // Canonical
    float toFloat(void) const ;
    int toInt(void) const ;
    Fixed& operator=(Fixed const & rhs); // Canonical
    //  >, <, >=, <=, == and !=. comparaison
    bool operator>(Fixed const & rhs);
    bool operator<(Fixed const & rhs);
    bool operator>=(Fixed const & rhs);
    bool operator<=(Fixed const & rhs);
    bool operator==(Fixed const & rhs);
    bool operator!=(Fixed const & rhs);
    // +, -, *, and /
    Fixed operator+(Fixed const & rhs);
    Fixed operator-(Fixed const & rhs);
    Fixed operator*(Fixed const & rhs);
    Fixed operator/(Fixed const & rhs);
    // ++a, --a, a++, b++
    //prefix
    Fixed operator++(int);
    Fixed operator++();
    Fixed operator--(int);
    Fixed operator--();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    static Fixed& min(Fixed &s1, Fixed &s2);
    static const Fixed& min(Fixed const & s1, Fixed const &s2);
    static Fixed& max(Fixed &s1, Fixed &s2);
    static const Fixed& max(Fixed const & s1, Fixed const &s2);

private:
    int _raw;
    static const int  _bits;
};
std::ostream& operator<<(std::ostream& o, Fixed const &i);
#endif
