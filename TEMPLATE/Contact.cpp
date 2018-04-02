#include "Contact.hpp"

/* Constructors */
Contact::Contact(void) {
	std::cout << "(Contact) default constructor called" << std::endl;
    return ;
}

/* function members */
// Contact::ERROR::~ERROR(void) throw() { }
// Contact::ERROR::ERROR(void) {  }
/* override */
Contact& Contact::operator=(Contact const & rhs) {
	std::cout << "(Contact) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, Contact const &i) {
	out << "(Contact) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

Contact::Contact(Contact const & src) {
	std::cout << "(Contact) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Contact::~Contact(void) {
	std::cout << "(Contact) destructor Contact called" << std::endl;
    return ;
}
