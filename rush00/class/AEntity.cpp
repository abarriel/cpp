#include "AEntity.hpp"
# include "Game.hpp"

/* Constructors */
int rands() {
    std::srand(static_cast<unsigned int>(std::clock())); 
	return std::rand();
}

AEntity::AEntity(void) {
	// std::cout << "(AEntity) default constructor called" << std::endl;
    return ;
}

void AEntity::init(int i) {
	this->shape = Game::instance()->getFile(entity[i].path);
	this->hp = entity[i].hp;
	this->x = 0;
	this->y = 0;
	this->style = entity[i].style;
	this->live = false;
	this->size = entity[i].size;
	this->damageCost = entity[i].damageCost;
}

AEntity::AEntity(Player *e) {
	int i = ENEMY_LEN + BULLET_LEN;
	(void)e;
	this->init(i);
    return ;
}

AEntity::AEntity(Enemy *e) {
	int i = rands() % ENEMY_LEN;
	(void)e;
	this->init(i);
	// std::cout << "(AEntity) okpokpokop constructor called" << std::endl;
    return ;
}

AEntity::AEntity(Bullet *e, int u) {
	int i = 5 + u;
	(void)e;
	this->init(i);
	// std::cout << "(AEntity) okpokpokop constructor called" << std::endl;
    return ;
}
// AEntity::AEntity(Player *p) : x(0), y(0), size(0), live(false) {
// 	// int i = rands() % 9;
// 	this->init(i);
// 	std::cout << "(AEntity) okpokpokop constructor called" << std::endl;
//     return ;
// }

void AEntity::getInfos() const {
	std::cout << "---------------------" << std::endl;
	std::cout << "x: " << this->x << std::endl;
	std::cout << "y: " << this->y << std::endl;
	std::cout << "hp: " << this->hp << std::endl;
	std::cout << "size: " << this->size << std::endl;
	std::cout << "damageCost: " << this->damageCost << std::endl;
	std::cout << "style: " << this->style << std::endl;
	std::cout << "shape: " << std::endl << this->shape << std::endl;
	std::cout << "---------------------" << std::endl;
}

/* function members */
void AEntity::takeDamage(int dama) {
	// this->hp -=
	(void)dama;
}

void AEntity::attack(AEntity* e) {
	e->takeDamage(this->damageCost);
}
// void attack(Enemy*);
// void attack(Player*);
void AEntity::update(Enemy *e) {
	(void)e;
	// 
}
void AEntity::update(Player *p) {
	(void)p;
	// 
}
void AEntity::update(Bullet *b) {
	(void)b;
	// 
}

void AEntity::render(){
// 
}

int AEntity::getX() const { return this->x; }
int AEntity::getY() const { return this->y; }
int AEntity::getHP() const { return this->hp; }
int AEntity::getSize() const { return this->size; }
int AEntity::getStyle() const { return this->style; }
int AEntity::getDamageCost() const { return this->damageCost; }
std::string AEntity::getShape() const { return this->shape; }
bool AEntity::getLive() const { return this->live; }

int& AEntity::setX() { return this->x; }
int& AEntity::setY() { return this->y; }
int& AEntity::setHP() { return this->hp; }
int& AEntity::setSize() { return this->size; }
int& AEntity::setStyle() { return this->style; }
int& AEntity::setDamageCost() { return this->damageCost; }
bool& AEntity::setLive() { return this->live; }

void AEntity::setShape(Enemy *e) {
	(void)e;
	std::cout << "setShape Enemy";
}

void AEntity::setShape(Player *p) {
	(void)p;
	std::cout << "setShape player";
}

void AEntity::setShape(Bullet *b) {
	(void)b;
	std::cout << "setShape Bullet";
}

/* override */
AEntity& AEntity::operator=(AEntity const & rhs) {
	std::cout << "(AEntity) assignation operator called";
	this->x = rhs.x;
	this->y = rhs.y;
	this->size = rhs.size;
	this->hp = rhs.hp;
	this->damageCost = rhs.damageCost;
	this->live = rhs.live;
	this->shape = rhs.shape;
	/* add logic */
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
	// std::cout << "(AEntity) destructor AEntity called" << std::endl;
    return ;
}
