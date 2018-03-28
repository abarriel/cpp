#include "SuperMutant.hpp"

/* Constructors */
SuperMutant::SuperMutant(void) {
	std::cout << "(SuperMutant) default constructor called" << std::endl;
    return ;
}

SuperMutant::SuperMutant(SuperMutant const & src) {
	std::cout << "(SuperMutant) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* override */
SuperMutant& SuperMutant::operator=(SuperMutant const & rhs) {
	std::cout << "(SuperMutant) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, SuperMutant const &i) {
	out << "(SuperMutant) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

/* Destructors */
SuperMutant::~SuperMutant(void) {
	std::cout << "(SuperMutant) destructor SuperMutant called" << std::endl;
    return ;
}
