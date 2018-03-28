#include "PowerFist.hpp"

/* Constructors */
PowerFist::PowerFist(void) {
	std::cout << "(PowerFist) default constructor called" << std::endl;
    return ;
}

PowerFist::PowerFist(PowerFist const & src) {
	std::cout << "(PowerFist) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* override */
PowerFist& PowerFist::operator=(PowerFist const & rhs) {
	std::cout << "(PowerFist) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, PowerFist const &i) {
	out << "(PowerFist) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

/* Destructors */
PowerFist::~PowerFist(void) {
	std::cout << "(PowerFist) destructor PowerFist called" << std::endl;
    return ;
}
