#include "MateriaSource.hpp"

/* Constructors */
MateriaSource::MateriaSource(void) {
	std::cout << "(MateriaSource) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
MateriaSource& MateriaSource::operator=(MateriaSource const & rhs) {
	std::cout << "(MateriaSource) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, MateriaSource const &i) {
	out << "(MateriaSource) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	std::cout << "(MateriaSource) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
MateriaSource::~MateriaSource(void) {
	std::cout << "(MateriaSource) destructor MateriaSource called" << std::endl;
    return ;
}
