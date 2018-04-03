#include "Convert.hpp"

/* Constructors */
Convert::Convert(void) {
	std::cout << "(Convert) default constructor called" << std::endl;
    return ;
}

/* function members */
// Convert::ERROR::~ERROR(void) throw() { }
// Convert::ERROR::ERROR(void) {  }
/* override */
Convert& Convert::operator=(Convert const & rhs) {
	std::cout << "(Convert) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, Convert const &i) {
	out << "(Convert) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

Convert::Convert(Convert const & src) {
	std::cout << "(Convert) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Convert::~Convert(void) {
	std::cout << "(Convert) destructor Convert called" << std::endl;
    return ;
}
