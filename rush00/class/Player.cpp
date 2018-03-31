#include "Player.hpp"

/* Constructors */
Player::Player(void): AEntity::AEntity(this) {
	// std::cout << "(Player) default constructor called" << std::endl;
    return ;
}

/* function members */

/* override */
Player& Player::operator=(Player const & rhs) {
	std::cout << "(Player) assignation operator called";
	/* add logic */
	this->x = rhs.x;
	this->y = rhs.y;
	this->size = rhs.size;
	this->hp = rhs.hp;
	this->damageCost = rhs.damageCost;
	this->live = rhs.live;
	this->shape = rhs.shape;
	this->style = rhs.style;
	return *this;
}

Player* Player::clone() const {
	Player *clone = new Player();
	/* should use = operate */
	clone->x = this->x;
	clone->x = this->x;
	clone->y = this->y;
	clone->size = this->size;
	clone->hp = this->hp;
	clone->damageCost = this->damageCost;
	clone->live = this->live;
	clone->shape = this->shape;
	clone->style = this->style;
	return clone;
}

std::ostream& operator<<(std::ostream& out, Player const &i) {
	out << "(Player) WARNING ! ADD A LOGIC <<" << std::endl;
	(void)i;
	return out;
}

Player::Player(Player const & src) {
	std::cout << "(Player) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Player::~Player(void) {
	std::cout << "(Player) destructor Player called" << std::endl;
    return ;
}
