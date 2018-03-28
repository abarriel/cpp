// Victim
#include "Victim.hpp"
#include <iostream>

Victim::Victim(void) {
    std::cout << "Default Constructor Victim called(void)" << std::endl;
}

Victim::Victim(std::string name): name(name) {
    std::cout << "Some random victim called "<< name << " just popped !" << std::endl;
}

Victim::Victim(Victim const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Victim& Victim::operator=(Victim const & rhs) {
    std::cout << "Assignation operator called";
    return *this;
}

std::string Victim::getName(void) const{
    return this->name;
}

std::ostream& operator<<(std::ostream& o, Victim const &i) {
    o << "I am " << i.getName() << " and I like otters !";
    return o;
}

Victim::~Victim(void) {
    std::cout << "Victim " << this->name << " just died for no apparent reason !" << std::endl;
}
