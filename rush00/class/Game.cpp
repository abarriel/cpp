#include "Game.hpp"

Game *Game::p_instance = 0;
/* Constructors */
Game::Game(void): x(0), y(0), direction(0), end(false), maxEntity(0), e(NULL), lvl(1), score(0) {
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
	// delete p;
}

AEntity *Game::getEntity(AEntity *me) {
	Node *b;
	AEntity *cur;
	int x, y;

	b = this->e;
	while (this->e) {
		cur = this->e->entity;
		if (cur == me)
		{
			this->e = this->e->next;
			continue;
		}
		for (y = me->getY(); y < (me->getY() + me->getYmax()); y++) {
			if (y >= cur->getY() && y <= (cur->getY() + cur->getYmax()))
				{
					for (x = me->getX(); x < (me->getX() + me->getXmax()); x++) {
						if (x >= cur->getX() && x <= (cur->getX() + cur->getXmax()))
						{
							// std::cout << "HIT AT y: " << y << " x: " << x << std::endl;
							this->e = b;
							return cur;
						}
					}
				}
		} 
		this->e = this->e->next;
	}
	// std::cout << std::endl;
	this->e = b;
	return NULL;
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
void Game::printBG() {
	int y;
	int x;
	int i;

	for (i = 0; i < 30; i++)
	{
		y =	rand() % this->y;
		x = rand () % this->x;
		attron(COLOR_PAIR(10));	
		move(y, x);
		addch('*');
	}
}

void Game::rmenu() {
	// wborder(win, verch, verch, horch, horch, 0, 0, 0, 0).
// 
	box(stdscr, '*', ' ');
	// printf("%.*s", 5, "=================");
    attron(COLOR_PAIR(1));	
	mvprintw(0, (this->x / 4) + 16 , "LVL: %d", this->lvl > 4 ? 4 : this->lvl);
	//   printf("%2$d %1$d", a, b);m
	mvprintw(0, (this->x / 4) + 70 , "NEXT LVL: [%.*s", (this->ticks / 50), "####################################################");
	// mvprintw(0, (this->x / 4) + 70 , "NEXT LVL: [%.*s %s", (this->ticks / 60), "####################################################", "]");
    attron(COLOR_PAIR(2));	
	mvprintw(0, (this->x / 4) + 121, "] SCORE: %d", this->score);
	mvprintw(0, (this->x / 4) + 140 , "HP: %.*s", this->getPlayer()->getHP() / 2, "####################################################");
}

void Game::render() {
	Node *begin = this->e;
	int i;
	i = 0;
	AEntity *e;
	erase();
	this->printBG();
	while (this->e){
		
		e = this->e->entity;
		// e->getInfos();
		this->printShape(e);
		this->e = this->e->next;
	}
	this->e = begin;
	this->rmenu(); /* clear print menu and box */
}

# define POP_ENNEMY 12
# define SPEED_Y 2
# define SPEED_X 4

void Game::boss() {
	clear();
	Node *tmp;
	Node *b = this->e;
	std::string *file;
	int direct;
	int i = -1;
	file = Game::getFile("final_stage");
    attron(COLOR_PAIR(1) | A_BLINK);
	while (!file[++i].empty()) {
		mvprintw((this->y / 2) + i, (this->x / 2) - (file[i].length() / 2) ,file[i].c_str());
	}
	Node *ent = this->e->next;
	while (ent) {
		tmp = ent;
		this->deleleEntity(tmp->entity);
		ent = ent->next;
	}
	this->e = b;
	AEntity *left = new Enemy(0);	
	AEntity *right = new Enemy(1);	
	AEntity *boss = new Enemy(2);	
	left->setY() = 0;
	left->setX() = 0;
	b->entity->setX() = this->x / 2;
	b->entity->setY() = this->y - 1 - b->entity->getYmax();
	right->setY() = 0;
	right->setX() = this->x - right->getXmax();

	boss->setY() = 0;
	boss->setX() = this->x / 2 - boss->getXmax() / 2;
	this->addEntity(left);
	this->addEntity(right);
	this->addEntity(boss);
	while ((direct = getch()) != 's')
			;
	this->lvl = 5;
}

#define B_E 2

void Game::update(int direction) {
	Node *b = this->e;
	Node *ent = this->e->next;
	int i;
	int bullet_ennemy = B_E;
	int enemy_creation = POP_ENNEMY * this->lvl;
	switch (direction) {
		case KEY_LEFT:
			this->getPlayer()->update(SPEED_X, 0, true);
			break;
		case KEY_RIGHT:
			this->getPlayer()->update(SPEED_X, 0, false);
			break;
		case KEY_DOWN:
			this->getPlayer()->update(0, SPEED_Y, false);
			break;
		case KEY_UP:
			this->getPlayer()->update(0, SPEED_Y, true);
			break;
		case 'c':
		{
			if ((this->ticks % 5)) break;			
			AEntity *b = new Bullet(2, false);
			b->setX() = this->getPlayer()->getX() + (this->getPlayer()->getXmax() / 2);
			b->setY() = this->getPlayer()->getY() - b->getYmax() - 2;
			this->addEntity(b);
			delete b;
			break;
		}
		case 'v':
		{
			if((this->ticks % 2)) break;
			AEntity *b = new Bullet(1, false);
			b->setX() = this->getPlayer()->getX() + (this->getPlayer()->getXmax() / 2);
			b->setY() = this->getPlayer()->getY() - b->getYmax() - 2 ;
			this->addEntity(b);
			delete b;
			break;
		}
		case ' ':
		{
			AEntity *b = new Bullet(0, false);
			b->setX() = this->getPlayer()->getX() + (this->getPlayer()->getXmax() / 2);
			b->setY() = this->getPlayer()->getY() - b->getYmax() - 2;
			this->addEntity(b);
			delete b;
			break;
		}
		default:
			break;
	} 
	if (this->lvl == 4) return this->boss();
	if (this->lvl >= 5 && ((rand() % 6) == 5)) {
		while(bullet_ennemy--) {
			AEntity *b = new Bullet(0, true);
			b->setX() = (((rand()) % (this->x - 40)) + 40);
			b->setY() = 65;
			Game::instance()->addEntity(b);
		}
		bullet_ennemy = B_E;
	}
	else if (!(this->ticks % 200) && this->lvl < 4)
	{
		while(enemy_creation--) {
			AEntity *b = new Enemy();
			i = (rand() / 54 + this->ticks) % this->x;
			i = (i == 0) ? 1 : i;
			if ((i + b->getXmax()) >= this->x)
				b->setX() = i - b->getXmax();
			else 
				b->setX() = i;
			if (b->getDamageCost() > 30)
				{
					i = (rand() / 54 + this->ticks) % (this->y / 4);
					if ((i + b->getYmax()) >= (this->y / 4))
					b->setY() = i - b->getYmax();
					else
					b->setY() = i;
				}
			else {
				i = (rand() / 54 + this->ticks) % (this->y / 3);
				if ((i + b->getYmax()) >= (this->y / 3))
					b->setY() = i - b->getYmax();
				else
					b->setY() = i;
			}
			this->addEntity(b);
			delete b;
		}
		enemy_creation = POP_ENNEMY * this->lvl;
	}
	while (ent) {
		ent->entity->update();
		ent = ent->next;
	}
	if (this->ticks > 1000)
	{
		this->lvl += 1;
		this->ticks = 0;
	}
	this->e = b;
}

/* accesors */
int Game::getScore() const { return this->score; }
int Game::getlvl() const { return this->lvl; }

int& Game::setScore() { return this->score; }
int& Game::setlvl()  { return this->lvl; }

Node* Game::getEntity() { return this->e; }
AEntity* Game::getPlayer() { return this->e->entity; }
int Game::getDir() const { return this->direction; }
int Game::getX(void) const { return this->x; }
int Game::getY(void) const { return this->y; }
int Game::getTicks(void) const { return this->ticks; }
int Game::getMaxEntity() const{ return this->maxEntity; }
bool Game::getEnd() const { return this->end; }
int& Game::setDir() { return this->direction; }
int& Game::setX() { return this->x; }
int& Game::setMaxEntity() { return this->maxEntity; }
int& Game::setY() { return this->y; }
int& Game::setTicks() { return this->ticks; }
bool& Game::setEnd() { return this->end; }

/* tools (yes i know it's dump to use endmessage startmessage and winmessage ahah too lazy*/
void Game::winMessage() {
	std::string *file;
	int i = -1;
	file = Game::getFile("end");
    attron(COLOR_PAIR(2));
	while (!file[++i].empty()) {
		mvprintw((this->y / 2) + i, (this->x / 2) - (file[i].length() / 2) ,file[i].c_str());
	}
	standend();
}

void Game::endMessage() {
	std::string *file;
	int i = -1;
	file = Game::getFile("gameover");
    attron(COLOR_PAIR(1) | A_BLINK);
	while (!file[++i].empty()) {
		mvprintw((this->y / 2) + i, (this->x / 2) - (file[i].length() / 2) ,file[i].c_str());
	}
	standend();
}

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
			delete tmp->entity;
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
