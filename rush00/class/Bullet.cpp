#include "Bullet.hpp"

/* Constructors */
Bullet::Bullet(int i): AEntity::AEntity(this, i) {
	// srand (time(NULL));
    // const std::string name[7] = { "allan", "michael", "ilan", "chamo", "superman", "nek", "dracula" };
    // int random_number = std::rand(); 
	// AEntity::init(this, );
	std::cout << "(Bullet) default constructor called" << std::endl;
    return ;
}
//  .  .
// /\\//
// > () <
// \/()\/
/* function members */

/* override */
Bullet& Bullet::operator=(Bullet const & rhs) {
	std::cout << "(Bullet) assignation operator called";
	/* add logic */
	this->x = rhs.x;
	this->y = rhs.y;
	this->size = rhs.size;
	this->hp = rhs.hp;
	this->damageCost = rhs.damageCost;
	this->live = rhs.live;
	this->style = rhs.style;
	this->shape = rhs.shape;
	return *this;
}

std::ostream& operator<<(std::ostream& out, Bullet const &i) {
	out << "(Bullet) WARNING ! ADD A LOGIC <<" << std::endl;
	(void)i;	
	return out;
}

Bullet::Bullet(Bullet const & src) {
	std::cout << "(Bullet) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Bullet::~Bullet(void) {
	std::cout << "(Bullet) destructor Bullet called" << std::endl;
    return ;
}
