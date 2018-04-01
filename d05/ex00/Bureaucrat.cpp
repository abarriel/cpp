#include "Bureaucrat.hpp"

/* Constructors */
Bureaucrat::Bureaucrat(void) {
	std::cout << "(Bureaucrat) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs) {
	std::cout << "(Bureaucrat) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const &i) {
	out << "(Bureaucrat) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	std::cout << "(Bureaucrat) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Bureaucrat::~Bureaucrat(void) {
	std::cout << "(Bureaucrat) destructor Bureaucrat called" << std::endl;
    return ;
}
