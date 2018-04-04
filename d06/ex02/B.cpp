#include "B.hpp"

/* Constructors */
B::B(void) {
	std::cout << "(B) default constructor called" << std::endl;
    return ;
}

/* function members */
// B::ERROR::~ERROR(void) throw() { }
// B::ERROR::ERROR(void) {  }
/* override */
B& B::operator=(B const &) {
	std::cout << "(B) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, B const &) {
	out << "(B) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

B::B(B const & src) {
	std::cout << "(B) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
B::~B(void) {
	std::cout << "(B) destructor B called" << std::endl;
    return ;
}
