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
    int getRawBits(void) const;
    void setRawBits(int const raw);
private:
    int _raw;
    const int  _bits;
};
std::ostream& operator<<(std::ostream& o, Fixed const &i);
#endif
