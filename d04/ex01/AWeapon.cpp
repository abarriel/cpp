#include "AWeapon.hpp"

/* Constructors */
AWeapon::AWeapon(void) {
	std::cout << "(AWeapon) default constructor called" << std::endl;
    return ;
}

AWeapon::AWeapon(AWeapon const & src) {
	std::cout << "(AWeapon) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* override */
AWeapon& AWeapon::operator=(AWeapon const & rhs) {
	std::cout << "(AWeapon) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, AWeapon const &i) {
	out << "(AWeapon) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

/* Destructors */
AWeapon::~AWeapon(void) {
	std::cout << "(AWeapon) destructor AWeapon called" << std::endl;
    return ;
}
