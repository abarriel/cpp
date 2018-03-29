#include "AMateria.hpp"

/* Constructors */
AMateria::AMateria(void) {
	std::cout << "(AMateria) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
AMateria& AMateria::operator=(AMateria const & rhs) {
	std::cout << "(AMateria) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, AMateria const &i) {
	out << "(AMateria) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

AMateria::AMateria(AMateria const & src) {
	std::cout << "(AMateria) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
AMateria::~AMateria(void) {
	std::cout << "(AMateria) destructor AMateria called" << std::endl;
    return ;
}
