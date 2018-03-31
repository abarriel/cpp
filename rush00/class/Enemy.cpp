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
bool Enemy::update(int x, int y, bool isNeg) {
	x = (isNeg) ? -x : x;
	y = (isNeg) ? -y : y;
	int xMax = Game::instance()->getX();
	int yMax = Game::instance()->getY();
	// std::cout << "ENEMY UPDATE" << std::endl;			
	if ((this->y + this->yMax + y) > yMax || (this->y + y) < 0)
		return false;
	else 
		this->y += y;
	if ((this->x + this->xMax + x) > xMax || (this->x + x) < 0)
		return false;
	else
		this->x += x;	
	return true;
}

bool Enemy::update() {
	// std::cout << "AENTITY UPDATE" << std::endl;
	return true;
}
/* override */
Enemy& Enemy::operator=(Enemy const & rhs) {
	std::cout << "(Enemy) assignation operator called";
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

Enemy* Enemy::clone() const {
	Enemy *clone = new Enemy();
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
	// std::cout << "(Enemy) destructor Enemy called" << std::endl;
    return ;
}
