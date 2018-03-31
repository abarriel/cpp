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
	p->setX() = this->x - 1;
	p->setY() = this->y / 2;
	p->getInfos();
	this->addEntity(p);
	delete p;
}

void Game::rmenu() {
	box(stdscr, '|', '-');
	mvprintw(0, this->y / 2 - 10, "*FT_RETRO*");
}

void Game::render() {
	Node *begin = this->e;
	clear();
	int i;
	i = 0;
	// this->rmenu(); /* clear print menu and box */
	AEntity *e;
	// this->startMessage();
	while (this->e){
		attron(COLOR_PAIR(2));
		e = this->e->entity;
		e->getInfos();
		mvprintw(e->getX() - e->getSize(), e->getY(), e->getShape().c_str());
		// printf("[%s]\n", e->getShape().c_str());
		// mvprintw(20, 20, e->getShape().c_str());
		this->e = this->e->next;
	}
	this->e = begin;
}

void Game::update(int direction) {
	(void)direction;
}
	// 	clear();
	// bg->putBackground();
	// g->putObjects();
	// g->putImage();
	// refresh();

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
bool& Game::setEnd() { return this->end; }

/* tools */

void Game::startMessage() {
	std::string file;
	
	file = Game::getFile("welcome");
    attron(COLOR_PAIR(1) | A_BLINK);	
	mvprintw((this->x / 2) - 10, 0,"%s",file.c_str());
	attroff(COLOR_PAIR(1) | A_BLINK);
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

std::string Game::getFile(std::string s) {
	std::ifstream ifs((std::string)"use/" + s);
    std::string file = "";
	std::string tmp;

    if (!ifs.is_open())
	{
		endwin();
		std::cout << "Wrong Path" << std::endl;
		exit(1);
	}
	while (std::getline(ifs,tmp))
	    file += tmp + "\n";
	ifs.close();
	return file;
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
