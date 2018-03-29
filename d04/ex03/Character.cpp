#include "Character.hpp"

/* Constructors */
Character::Character(void) {
	std::cout << "(Character) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
Character& Character::operator=(Character const & rhs) {
	std::cout << "(Character) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, Character const &i) {
	out << "(Character) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

Character::Character(Character const & src) {
	std::cout << "(Character) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Character::~Character(void) {
	std::cout << "(Character) destructor Character called" << std::endl;
    return ;
}
