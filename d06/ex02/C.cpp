#include "C.hpp"

/* Constructors */
C::C(void) {
	std::cout << "(C) default constructor called" << std::endl;
    return ;
}

/* function members */
// C::ERROR::~ERROR(void) throw() { }
// C::ERROR::ERROR(void) {  }
/* override */
C& C::operator=(C const &) {
	std::cout << "(C) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, C const &) {
	out << "(C) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

C::C(C const & src) {
	std::cout << "(C) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
C::~C(void) {
	std::cout << "(C) destructor C called" << std::endl;
    return ;
}
