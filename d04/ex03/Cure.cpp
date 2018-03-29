#include "Cure.hpp"

/* Constructors */
Cure::Cure(void) {
	std::cout << "(Cure) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
Cure& Cure::operator=(Cure const & rhs) {
	std::cout << "(Cure) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, Cure const &i) {
	out << "(Cure) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

Cure::Cure(Cure const & src) {
	std::cout << "(Cure) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Cure::~Cure(void) {
	std::cout << "(Cure) destructor Cure called" << std::endl;
    return ;
}
