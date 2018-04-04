#include "A.hpp"

/* Constructors */
A::A(void) {
	std::cout << "(A) default constructor called" << std::endl;
    return ;
}
/* function members */

/* override */
A& A::operator=(A const &) {
	std::cout << "(A) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, A const &) {
	out << "(A) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

A::A(A const & src) {
	std::cout << "(A) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
A::~A(void) {
	std::cout << "(A) destructor A called" << std::endl;
    return ;
}
