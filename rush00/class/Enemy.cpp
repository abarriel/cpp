#include "Enemy.hpp"

/* Constructors */

Enemy::Enemy(void): AEntity::AEntity(this) {
	// srand (time(NULL));
	// srand (time(NULL));
    // const std::string name[7] = { "allan", "michael", "ilan", "chamo", "superman", "nek", "dracula" };
	// AEntity::init(this, );
	// std::cout << "(Enemy) default constructor called" << std::endl;
    return ;
}
/* function members */

/* override */
Enemy& Enemy::operator=(Enemy const & rhs) {
	std::cout << "(Enemy) assignation operator called";
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

Enemy* Enemy::clone() const {
	Enemy *clone = new Enemy();
	return clone;
}

std::ostream& operator<<(std::ostream& out, Enemy const &i) {
	out << "(Enemy) WARNING ! ADD A LOGIC <<" << std::endl;
	(void)i;	
	return out;
}

Enemy::Enemy(Enemy const & src) {
	std::cout << "(Enemy) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Enemy::~Enemy(void) {
	std::cout << "(Enemy) destructor Enemy called" << std::endl;
    return ;
}
