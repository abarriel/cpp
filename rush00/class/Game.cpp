#include "Game.hpp"

/* Constructors */
Game *Game::p_instance = 0;
Game::Game(void): x(0), y(0), direction(0), end(false), maxEntity(0), e(NULL) {
	std::cout << "Game just start" << std::endl;
	// AEntity e = new Player();
	// AEntity *e = new Player();
	(void)e;
	// this->addEntity(e);
    return ;
}
Game::Game(int x, int y): x(x), y(y), direction(0), end(false),  maxEntity(0), e(NULL) {
	std::cout << "Game just start" << std::endl;
    return ;
}

Game *Game::instance() { /* singleton */
	if (!Game::p_instance)
		Game::p_instance = new Game;
	return Game::p_instance;
}
void Game::init(){
	AEntity *p = new Player();
	AEntity *e = new Enemy();
	this->addEntity(p);	
	this->addEntity(e);	
	this->addEntity(e);
	this->addEntity(e);	
	delete p;
	delete e;
}

void Game::addEntity(AEntity* unit) {
	Node *begin = this->e;
	// std::cout <<  "pusoh" << std::endl;
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

std::string getFileContents (std::ifstream& File)
{
    std::string Lines = "";        //All lines
    
    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    std::string TempLine;                  //Temp line
	    std::getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character
	    
	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }
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

void Game::startMessage() {
	std::string file;
	
	file = Game::getFile("welcome");
    attron(COLOR_PAIR(1) | A_BLINK);	
	mvprintw((this->x / 2) - 10, 0,"%s",file.c_str());
	attroff(COLOR_PAIR(1) | A_BLINK);
}
/* function members */
Node* Game::getEntity() {
	return this->e;
}

void Game::deleleEntity(AEntity *unit) {
	Node *e = this->e;
	Node *tmp;

	while (e)
	{
		if (unit == e->entity)
		{
				tmp = e;
				e = e->next;
				std::cout << "d"<< tmp->entity->getHP() << std::endl;
				delete tmp->entity;
				delete tmp;
		}
		else
				e = (*e).next;
	}
	// while(e)  {
	// 	if (unit == e->entity)
	// 	{


	// 	}
	// 	e = e->next;
	// }
	(void)unit;
	// return this->e;
}
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

/* override */
Game& Game::operator=(Game const & rhs) {
	std::cout << "(Game) assignation operator called";
	/* add logic */
	this->x = rhs.x;
	this->y = rhs.y;
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
	std::cout << "Game Ended" << std::endl;
    return ;
}
