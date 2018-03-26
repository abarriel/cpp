// Fixed
#ifndef CLASSCONTACT_HPP
#define CLASSCONTACT_HPP
#include <iostream>

class Fixed {
public:
    Fixed(void); // Canonical
    Fixed(Fixed const & src); // Canonical
    ~Fixed(void); // Canonical
    Fixed& operator=(Fixed const & rhs); // Canonical
private:
};
// std::ostream& operator<<(std::ostream& o, Fixed const &i);
#endif
