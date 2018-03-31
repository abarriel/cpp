#include "Game.hpp"

Game *Game::p_instance = 0;
/* Constructors */
Game::Game(void): x(0), y(0), direction(0), end(false), maxEntity(0), e(NULL) {
	std::cout << "Game just start" << std::endl;
    return ;
}

Game *Game::instance() { /* singleton */
	if (!Game::p_instance) Game::p_instance = new Game;
	return Game::p_instance;
}

void Game::init(){
	AEntity *p = new Player();
	std::cout <<  "lenght: "<< std::endl;
	p->setX() = this->x / 2;
	p->setY() = this->y - 1 - p->getYmax();
	// p->getInfos();
	this->ticks = 0;
	this->addEntity(p);
	delete p;
}

void Game::printShape(AEntity *e) const {
	int i = -1;
    attron(COLOR_PAIR(e->getStyle()));
	// std::cout << "max x :" << this->x << " max y:" << this->y << std::endl;
	// std::cout << "y:" << e->getY() << " x:" << e->getX() << std::endl;
	while (!e->getShape()[++i].empty()) {
		mvprintw(e->getY() + i, e->getX() ,e->getShape()[i].c_str());
	}
	standend();	
}

void Game::rmenu() {
	box(stdscr, '*', '-');
	mvprintw(0, this->y / 2 - 10, "*FT_RETRO*");
}

void Game::render() {
	Node *begin = this->e;
	int i;
	i = 0;
	this->rmenu(); /* clear print menu and box */
	AEntity *e;
	clear();
	while (this->e){
		
		e = this->e->entity;
		// e->getInfos();
		this->printShape(e);
		this->e = this->e->next;
	}
	this->e = begin;
}
#include <unistd.h>
#include <stdio.h>
#define POP_ENNEMY 4  
void Game::update(int direction) {
	Node *b = this->e;
	Node *ent = this->e->next;
	int i;
	int enemy_creation = POP_ENNEMY;
	switch (direction) {
		default:
			break;
		case KEY_LEFT:
			this->getPlayer()->update(2, 0, true);
			break;
		case KEY_RIGHT:
			this->getPlayer()->update(2, 0, false);
			break;
		case KEY_DOWN:
			this->getPlayer()->update(0, 1, false);
			break;
		case KEY_UP:
			this->getPlayer()->update(0,1, true);
			break;
		case ' ':
		{
			AEntity *b = new Bullet(0, false);
			b->setX() = this->getPlayer()->getX() + (this->getPlayer()->getXmax() / 2);
			b->setY() = this->getPlayer()->getY() - 1;
			this->addEntity(b);
			delete b;
			break;
		}
		case 'e':
		{
			break;
		}
	} 
	if (!(ticks % 500))
	{
		while(enemy_creation--) {
			AEntity *b = new Enemy();
			i = (rand() / 54 + this->ticks) % this->x;
			if ((i + b->getXmax()) >= this->x)
				b->setX() = i - b->getXmax();
			else 
				b->setX() = i;
			i = (rand() / 54 + this->ticks) % (this->y / 3);
			if ((i + b->getYmax()) >= (this->y / 3))
				b->setY() = i - b->getYmax();
			else
				b->setY() = i;
			this->addEntity(b);
			delete b;
		}
		this->ticks = 0;
		enemy_creation = POP_ENNEMY;
	}
	while (ent) {
		// {
			//  AEntity *e = new Enemy();
			//  b->setX() 
		// 	//  delete e;
		// }
		ent->entity->update();
		ent = ent->next;
	}
	this->e = b;
}

/* accesors */
Node* Game::getEntity() { return this->e; }
AEntity* Game::getPlayer() { return this->e->entity; }
int Game::getDir() const { return this->direction; }
int Game::getX(void) const { return this->x; }
int Game::getY(void) const { return this->y; }
int Game::getMaxEntity() const{ return this->maxEntity; }
bool Game::getEnd() const { return this->end; }
int& Game::setDir() { return this->direction; }
int& Game::setX() { return this->x; }
int& Game::setMaxEntity() { return this->maxEntity; }
int& Game::setY() { return this->y; }
int& Game::setTicks() { return this->ticks; }
bool& Game::setEnd() { return this->end; }

/* tools */

void Game::startMessage() {
	std::string *file;
	int i = -1;
	file = Game::getFile("welcome");
    attron(COLOR_PAIR(1) | A_BLINK);
	while (!file[++i].empty()) {
		mvprintw((this->y / 2) + i, (this->x / 2) - (file[i].length() / 2) ,file[i].c_str());
	}
	standend();
}

void Game::deleleEntity(AEntity *unit) {
	Node *tmp;
	Node **list = &this->e;
	while (*list)
	{
		if ((*list)->entity == unit)
		{
			tmp = (*list);
			(*list) = (*list)->next;
			delete tmp->entity; // segv
			delete tmp;
		}
		else
			list = &(*list)->next;
	}
	(void)unit;
}

void Game::addEntity(AEntity* unit) {
	Node *begin = this->e;
	Node *nw = new Node();
	nw->entity = unit->clone();
	nw->next = NULL;
	if (!this->e) {
			this->e = nw;
			return ;
	}
	while (this->e->next)
		this->e = this->e->next;
	this->e->next = nw;
	this->e = begin;
	return ;
}

std::string *Game::getFile(std::string s) {
	std::ifstream ifs((std::string)"use/" + s);
    std::string file = "";
	std::string tmp;
	int i = 0;

    if (!ifs.is_open())
	{
		endwin();
		std::cout << "Wrong Path" << std::endl;
		exit(1);
	}
	while (std::getline(ifs,tmp))
	{
		i++;
	 	file += tmp + "\n";
	}
	std::stringstream ss(file);
	std::string *array = new std::string[i + 1];
	i = -1;
	while(std::getline(ss, array[++i])) ;
	ifs.close();
	return array;
}

/* override */
Game& Game::operator=(Game const & rhs) {
	std::cout << "(Game) assignation operator called";
	this->x = rhs.x;
	this->y = rhs.y;
	this->e = rhs.e;
	this->direction = rhs.direction;
	this->end = rhs.end;
	return *this;
}

std::ostream& operator<<(std::ostream& out, Game const &i) {
	out << "(Game) WARNING ! ADD A LOGIC <<" << std::endl;
	(void)i;
	return out;
}

Game::Game(Game const & src) {
	std::cout << "(Game) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Game::~Game(void) {
	Node     *current;
	Node     *next;

   	current = this->e;
   	while (current) 
   	{
       next = current->next;
	   delete current->entity;
	   delete current;
       current = next;
   	}
	std::cout << "Game Ended" << std::endl;
    return ;
}
