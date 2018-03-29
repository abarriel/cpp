#include "Ice.hpp"

/* Constructors */
Ice::Ice(void) {
	std::cout << "(Ice) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
Ice& Ice::operator=(Ice const & rhs) {
	std::cout << "(Ice) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, Ice const &i) {
	out << "(Ice) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

Ice::Ice(Ice const & src) {
	std::cout << "(Ice) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Ice::~Ice(void) {
	std::cout << "(Ice) destructor Ice called" << std::endl;
    return ;
}
