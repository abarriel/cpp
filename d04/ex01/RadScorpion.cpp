#include "RadScorpion.hpp"

/* Constructors */
RadScorpion::RadScorpion(void) {
	std::cout << "(RadScorpion) default constructor called" << std::endl;
    return ;
}

RadScorpion::RadScorpion(RadScorpion const & src) {
	std::cout << "(RadScorpion) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* override */
RadScorpion& RadScorpion::operator=(RadScorpion const & rhs) {
	std::cout << "(RadScorpion) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, RadScorpion const &i) {
	out << "(RadScorpion) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

/* Destructors */
RadScorpion::~RadScorpion(void) {
	std::cout << "(RadScorpion) destructor RadScorpion called" << std::endl;
    return ;
}
