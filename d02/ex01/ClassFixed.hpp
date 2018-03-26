// Fixed
#ifndef CLASSFIXED_HPP
#define CLASSFIXED_HPP
#include <iostream>

class Fixed {
public:
    Fixed(void); // Canonical
    Fixed(Fixed const & src); // Canonical
    ~Fixed(void); // Canonical
    Fixed& operator=(Fixed const & rhs); // Canonical
    int getRawBits(void) const;
    void setRawBits(int const raw);
private:
    int _value;
    const int  _bits;
};
// std::ostream& operator<<(std::ostream& o, Fixed const &i);
#endif
