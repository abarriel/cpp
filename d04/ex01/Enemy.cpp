#include "Enemy.hpp"

/* Constructors */
Enemy::Enemy(void) {
	std::cout << "(Enemy) default constructor called" << std::endl;
    return ;
}

Enemy::Enemy(Enemy const & src) {
	std::cout << "(Enemy) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* override */
Enemy& Enemy::operator=(Enemy const & rhs) {
	std::cout << "(Enemy) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, Enemy const &i) {
	out << "(Enemy) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

/* Destructors */
Enemy::~Enemy(void) {
	std::cout << "(Enemy) destructor Enemy called" << std::endl;
    return ;
}
