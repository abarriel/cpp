#include "IAsteroid.hpp"

/* Constructors */
IAsteroid::IAsteroid(void) {
	std::cout << "(IAsteroid) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
IAsteroid& IAsteroid::operator=(IAsteroid const & rhs) {
	std::cout << "(IAsteroid) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, IAsteroid const &i) {
	out << "(IAsteroid) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

IAsteroid::IAsteroid(IAsteroid const & src) {
	std::cout << "(IAsteroid) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
IAsteroid::~IAsteroid(void) {
	std::cout << "(IAsteroid) destructor IAsteroid called" << std::endl;
    return ;
}
