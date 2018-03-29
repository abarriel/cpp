#include "MiningBarge.hpp"

/* Constructors */
MiningBarge::MiningBarge(void) {
	std::cout << "(MiningBarge) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
MiningBarge& MiningBarge::operator=(MiningBarge const & rhs) {
	std::cout << "(MiningBarge) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, MiningBarge const &i) {
	out << "(MiningBarge) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

MiningBarge::MiningBarge(MiningBarge const & src) {
	std::cout << "(MiningBarge) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
MiningBarge::~MiningBarge(void) {
	std::cout << "(MiningBarge) destructor MiningBarge called" << std::endl;
    return ;
}
