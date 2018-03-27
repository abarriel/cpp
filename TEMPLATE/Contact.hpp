// Contact
#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact {
public:
    Contact(void); // Canonical
    Contact(Contact const & src); // Canonical
    ~Contact(void); // Canonical
    Contact& operator=(Contact const & rhs); // Canonical
private:
};
// std::ostream& operator<<(std::ostream& o, Contact const &i);
#endif