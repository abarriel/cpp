#include "PlasmaRifle.hpp"

/* Constructors */
PlasmaRifle::PlasmaRifle(void) {
	std::cout << "(PlasmaRifle) default constructor called" << std::endl;
    return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) {
	std::cout << "(PlasmaRifle) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* override */
PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const & rhs) {
	std::cout << "(PlasmaRifle) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, PlasmaRifle const &i) {
	out << "(PlasmaRifle) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

/* Destructors */
PlasmaRifle::~PlasmaRifle(void) {
	std::cout << "(PlasmaRifle) destructor PlasmaRifle called" << std::endl;
    return ;
}
