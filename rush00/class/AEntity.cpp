#include "AEntity.hpp"
# include "Game.hpp"

/* Constructors */
int rands() {
    std::srand(static_cast<unsigned int>(std::clock())); 
	return std::rand();
}

AEntity::AEntity(void) {
    return ;
}

void AEntity::init(int i) {
	this->shape = Game::instance()->getFile(entity[i].path);
	this->hp = entity[i].hp;
	this->x = 0;
	this->y = 0;
	this->style = entity[i].style;
	this->live = false;
	this->isNeg = true;
	this->xMax = entity[i].xMax;
	this->yMax = entity[i].yMax;
	this->damageCost = entity[i].damageCost;
}

AEntity::AEntity(Player *e) {
	int i = ENEMY_LEN + BULLET_LEN;
	(void)e;
	this->init(i);
    return ;
}

AEntity::AEntity(Enemy *e, int i) {
	(void)e;
	this->init( 5 + i);
    return ;
}

AEntity::AEntity(Enemy *e) {
	int i = rands() % 5;
	(void)e;
	this->init(i);
    return ;
}

AEntity::AEntity(Bullet *e, int u) {
	int i = ENEMY_LEN + u;
	(void)e;
	this->init(i);
    return ;
}

void AEntity::getInfos() const {
	int i = -1;
	std::cout << "---------------------" << std::endl;
	std::cout << "x: " << this->x << std::endl;
	std::cout << "y: " << this->y << std::endl;
	std::cout << "hp: " << this->hp << std::endl;
	std::cout << "yMax: " << this->yMax << std::endl;
	std::cout << "xMax: " << this->xMax << std::endl;
	std::cout << "damageCost: " << this->damageCost << std::endl;
	std::cout << "style: " << this->style << std::endl;
	std::cout << "shape: " << std::endl;
	while (!this->shape[++i].empty())
		std::cout << this->shape[i] << std::endl;
	std::cout << "---------------------" << std::endl;
}

/* function members */
void AEntity::takeDamage(int dama) {
	// this->hp -=
	this->hp -= dama;
}

// void attack(Enemy*);
bool AEntity::update() {
	std::cout << "AENTITY UPDATE" << std::endl;
	return true;
}
// void attack(Player*);
bool AEntity::update(int x, int y, bool isNeg) {
	(void)x;
	(void)y;
	(void)isNeg;
	return true;
}

int AEntity::getX() const { return this->x; }
int AEntity::getY() const { return this->y; }
int AEntity::getHP() const { return this->hp; }
int AEntity::getYmax() const { return this->yMax; }
int AEntity::getXmax() const { return this->xMax; }
int AEntity::getStyle() const { return this->style; }
int AEntity::getDamageCost() const { return this->damageCost; }
std::string *AEntity::getShape() const { return this->shape; }
bool AEntity::getLive() const { return this->live; }

int& AEntity::setX() { return this->x; }
int& AEntity::setY() { return this->y; }
int& AEntity::setHP() { return this->hp; }
int& AEntity::setStyle() { return this->style; }
int& AEntity::setDamageCost() { return this->damageCost; }
bool& AEntity::setLive() { return this->live; }
/* override */
AEntity& AEntity::operator=(AEntity const & rhs) {
	std::cout << "(AEntity) assignation operator called";
	this->x = rhs.x;
	this->y = rhs.y;
	this->xMax = rhs.xMax;
	this->yMax = rhs.yMax;
	this->hp = rhs.hp;
	this->damageCost = rhs.damageCost;
	this->live = rhs.live;
	this->isNeg = rhs.isNeg;
	this->shape = rhs.shape;
	return *this;
}

std::ostream& operator<<(std::ostream& out, AEntity const &i) {
	out << "(AEntity) WARNING ! ADD A LOGIC <<" << std::endl;
	(void)i;
	return out;
}

AEntity::AEntity(AEntity const & src) {
	std::cout << "(AEntity) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
AEntity::~AEntity(void) {
	// std::cout << "(AEntity) destructor constructor called" << std::endl;
    return ;
}
