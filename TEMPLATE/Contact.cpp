// Contact
#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {
    std::cout << "Default Constructor Contact called(void)" << std::endl;
}

Contact::Contact(Contact const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Contact& Contact::operator=(Contact const & rhs) {
    std::cout << "Assignation operator called";
    return *this;
}

Contact::~Contact(void) {
    std::cout << "Destructor Contact called" << std::endl;
}