#include "Player.hpp"
/* Constructors */
Player::Player(void): AEntity::AEntity(this) {
	// std::cout << "(Player) default constructor called" << std::endl;
    return ;
}

bool Player::update() {
	std::cout << "AENTITY UPDATE" << std::endl;
	return true;
}
/* function members */
bool Player::update(int x, int y, bool isNeg) {
	x = (isNeg) ? -x : x;
	y = (isNeg) ? -y : y;
	int xMax = Game::instance()->getX();
	int yMax = Game::instance()->getY();
	if ((this->y + this->yMax + y) > yMax || (this->y + y) < 1)
		return false;
	else 
		this->y += y;
	if ((this->x + this->xMax + x) > xMax || (this->x + x) < 1)
		return false;
	else
		this->x += x;	
	return true;
}

/* override */
Player& Player::operator=(Player const & rhs) {
	std::cout << "(Player) assignation operator called";
	/* add logic */
	this->x = rhs.x;
	this->y = rhs.y;
	this->xMax = rhs.xMax;
	this->yMax = rhs.yMax;
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
	clone->xMax = this->xMax;
	clone->yMax = this->yMax;
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
	int direct;
	// std::cout << this->hp << std::endl;	
	if(this->hp > 0)
		return ;
	clear();
	Game::instance()->endMessage();
	refresh();
	while (1)
	{
		direct = getch();
		if (direct == 'q')
		{
			clear();
			endwin();
			exit(0);
		}
	}
    return ;
}
