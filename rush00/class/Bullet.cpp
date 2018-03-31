#include "Bullet.hpp"

/* Constructors */
Bullet::Bullet(int i): AEntity::AEntity(this, i) {
	// std::cout << "(Bullet) default constructor called" << std::endl;
    return ;
}

Bullet::Bullet(int i, bool e): AEntity::AEntity(this, i) {
	if(!e)
		this->isNeg = false;
	// std::cout << "(Bullet) default constructor called" << std::endl;
    return ;
}
//  .  .
// /\\//
// > () <
// \/()\/
/* function members */
bool Bullet::update() {
	clock_t t = clock();
	int y = 1;
	if (!(t % 2))  return true;
	// #define FPS(tms)  (clock() - tms > 4000)
	y = (!this->isNeg) ? -y : y;
	int yMax = Game::instance()->getY();
	// std::cout << "Bullet UPDATE" << std::endl;			
	if ((this->y + this->yMax + y) > yMax || (this->y + y) < 0)
	{
		Game::instance()->deleleEntity(this);
		return false;
	}
	else 
		this->y += y;
	// std::cout << "Bullet UPDATE" << std::endl;
	return true;
}

bool Bullet::update(int x, int y, bool isNeg) {
	(void)x;
	(void)y;
	(void)isNeg;
	return false;
}

/* override */
Bullet& Bullet::operator=(Bullet const & rhs) {
	std::cout << "(Bullet) assignation operator called";
	/* add logic */
	this->x = rhs.x;
	this->y = rhs.y;
	this->xMax = rhs.xMax;
	this->yMax = rhs.yMax;
	this->hp = rhs.hp;
	this->damageCost = rhs.damageCost;
	this->live = rhs.live;
	this->style = rhs.style;
	this->shape = rhs.shape;
	return *this;
}

Bullet* Bullet::clone() const {
	Bullet *clone = new Bullet(0);
	clone->x = this->x;
	clone->x = this->x;
	clone->y = this->y;
	clone->xMax = this->xMax;
	clone->yMax = this->yMax;
	clone->hp = this->hp;
	clone->damageCost = this->damageCost;
	clone->live = this->live;
	clone->shape = this->shape;
	clone->style = this->style;
	return clone;
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
