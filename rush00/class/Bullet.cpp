#include "Bullet.hpp"

/* Constructors */
Bullet::Bullet(int i): AEntity::AEntity(this, i) {
	// std::cout << "(Bullet) default constructor called" << std::endl;
    return ;
}

Bullet::Bullet(int i, bool e): AEntity::AEntity(this, i) {
	if(e == true)
		this->isNeg = true;
	else 
		this->isNeg = false;
	// std::cout << "(Bullet) default constructor called" << std::endl;
    return ;
}
/* function members */
bool Bullet::update() {
	clock_t t = clock();
	AEntity *e;
	int y = 1;
	if (!(t % 2)) return true;
	y = (!this->isNeg) ? -y : y;
	int yMax = Game::instance()->getY();
	if ((e = Game::instance()->getEntity(this))) {
		e->setHP() -= this->getDamageCost();
		this->setHP() -= e->getDamageCost();
		if (e->getHP() <= 0)
			 Game::instance()->deleleEntity(e);
		if (this->getHP() <= 0)
			 Game::instance()->deleleEntity(this);
		return false;
	}
	else if ((this->y + this->yMax + y) > yMax || (this->y + y) < 0)
	{
		Game::instance()->deleleEntity(this);
		return false;
	}
	else 
		this->y += y;
	return true;
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
	this->isNeg = rhs.isNeg;
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
	clone->isNeg = this->isNeg;
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
	// std::cout << "(Bullet) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Bullet::~Bullet(void) {
	// std::cout << "(Bullet) destructor Bullet called" << std::endl;
    return ;
}
