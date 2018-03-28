// Peon
#ifndef PEON_HPP
#define PEON_HPP
#include <iostream>

class Peon {
public:
    Peon(void); // Canonical constructor default (void!!!!!!)
    Peon(Peon const & src); // Canonical
    ~Peon(void); // Canonical
    Peon& operator=(Peon const & rhs); // Canonical
private:
};
// std::ostream& operator<<(std::ostream& o, Peon const &i);
#endif
