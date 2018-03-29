#include "IMiningLaser.hpp"

/* Constructors */
IMiningLaser::IMiningLaser(void) {
	std::cout << "(IMiningLaser) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
IMiningLaser& IMiningLaser::operator=(IMiningLaser const & rhs) {
	std::cout << "(IMiningLaser) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, IMiningLaser const &i) {
	out << "(IMiningLaser) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

IMiningLaser::IMiningLaser(IMiningLaser const & src) {
	std::cout << "(IMiningLaser) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
IMiningLaser::~IMiningLaser(void) {
	std::cout << "(IMiningLaser) destructor IMiningLaser called" << std::endl;
    return ;
}
