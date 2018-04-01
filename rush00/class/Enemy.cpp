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
Enemy::Enemy(int i): AEntity::AEntity(this, i) {
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

#define MOV_X 2
#define MOV_Y MOV_X

bool Enemy::update() {
	AEntity *e;
	int ti;
	int mov_x = MOV_X;
	int xMax = Game::instance()->getX();
	int yMax = Game::instance()->getY();
	int mov_y = MOV_Y;
	ti = (rand() % 100) + 100;
	if(this->getDamageCost() > 10000) goto end;
	if (this->getDamageCost() < 30 && !(Game::instance()->getTicks() % 20)) {
		if ((this->y + this->yMax + mov_y) >= yMax)
		{
			Game::instance()->deleleEntity(this);						
			return false;
		}
		else
			this->y += mov_y;
		// if (mthis->x += mov_x;
	}
	if(!(Game::instance()->getTicks() % ti)) {
		if ((this->x + this->xMax + mov_x) > xMax || (this->x + mov_x) < 0)
			return false;
		else
		{
			if(!(ti % 3))
				this->x += mov_x;	
			else
				this->x -= mov_x;	
		}
	}
	if (this->getDamageCost() > 30 && !(Game::instance()->getTicks() % ti))
	{
		AEntity *b = new Bullet(0, true);
		b->setX() = this->x + (this->xMax / 2);
		b->setY() = this->y + (this->yMax) + 10;
		Game::instance()->addEntity(b);
		delete b;
	}
	if (this->hp <= 0)
	{
		Game::instance()->deleleEntity(this);
		return false;
	}
	end:
	if ((e = Game::instance()->getEntity(this)))
	{
		e->setHP() -= this->getDamageCost();
		this->setHP() -= e->getDamageCost();
		if (e->getHP() <= 0)
			 Game::instance()->deleleEntity(e);
		if (this->getHP() <= 0)
			 Game::instance()->deleleEntity(this);
		return false;
	}
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
	int direct;
	if (this->hp <= 0)
		Game::instance()->setScore() += 13;
	if (this->damageCost == 99999998)
	{
		clear();
		Game::instance()->winMessage();
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
	}
    return ;
}
