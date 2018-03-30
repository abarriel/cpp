#include "Game.hpp"
#define LEN(name) sizeof(name) / sizeof(AEntity)

void startMessage()
{
    std::ifstream ifs("use/welcome");
	std::stringstream buffer;
    if (!ifs.is_open())
	{
		endwin();
		exit(0);		
	}
	buffer << ifs.rdbuf();
	printw(buffer.str().c_str());
}

void initNcurse() {
    initscr();
	start_color();
    init_pair(0, COLOR_CYAN, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK); /* id, foreground, background */
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	noecho (); /* no print char */
	curs_set(0); /* hide cursor */
	nodelay(stdscr,TRUE); /*  time framed */
	/* Initialization of the config */
	getmaxyx(stdscr, Game::instance()->setX(), Game::instance()->setY()); /* get max x and y of default window */
}
// fps 60 update par seconde ticks
void fexit() {
    endwin();
	exit(0);
}

// a chaque update check si le x et y est deja hit

void get(Node *b, int d) {
	int i;

	i = 0;
	while(b)
	{
		if(i == 2)
		{
			b->entity->getInfos();
			b->entity->setHP() = 0;
			if(d == 1)
				 Game::instance()->deleleEntity(b->entity);
		}
		b = b->next;
		i++;
	}
}
int main()
{
	int i;
	i =0;
	Game *g = Game::instance();
	// AEntity *p = new Player();
	// AEntity *e = new Enemy();
	// g->addEntity(e);
	g->init();
	Node *entities = g->getEntity();
	// Game *g = new Game();
	(void)g;
	get(entities, 0);
	// get(entity);
	// be = entity;
	get(entities, 1);
	std::cout << "EIFJEOIFEJOIFEJR" << std::endl;
	while(entities)
	{
	// 	// if(i == 2)
		entities->entity->getInfos();
		entities = entities->next;
	// 	i++;
	}
	// g->setMaxEntity() = LEN(e);
	// for(int i = 0; i < g->getMaxEntity(); i++ )
// s	p->getInfos();
	// e->getInfos();
	// b.getInfos();
	// std::cout << b->getShape() << std::endl;
// std::ofstream out("out.log");
// std::ifstream out_buf("out.log");
// std::streambuf *coutbuf = std::cout.rdbuf(); /* save buff */
// std::cout.rdbuf(out.rdbuf()); /* redirect std::cout to out.log */
// initNcurse();
// g->startMessage();
// box(stdscr, '|', '-');
// mvprintw(0, g->getY() / 2 - 10, "*FT_RETRO*");
// while ((direction = getch()) != 10)
// {
// 	if (direction == 'q')
// 		fexit();
// }
// clear();
// box(stdscr, '|', '-');
// wrefresh(stdscr);
// getchar();
// endwin();
// std::cout.rdbuf(coutbuf); /* reset buff */
// std::cout << out_buf.rdbuf() << std::endl;
    return 0;
}
