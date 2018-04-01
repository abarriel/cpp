#include "Game.hpp"
#define FPS(tms)  (clock() - tms > 10000)

void initNcurse() {
    initscr();
	start_color();
    init_pair(0, COLOR_CYAN, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK); /* id, foreground, background */
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_CYAN);
	// init_color(10, 234, 32, 39);	
	// rgb(255, 195, 18)
	init_color(10,18, 137, 167);
	init_pair(10, 10, COLOR_BLACK);	
	noecho (); /* no print char */
	curs_set(0); /* hide cursor */
	keypad(stdscr, TRUE);
	nodelay(stdscr,TRUE); /*  time framed */
	/* Initialization of the config */

	getmaxyx(stdscr, Game::instance()->setY(), Game::instance()->setX()); /* get max x and y of default window */
	// Game::instance()->setY() -= 1;
	// Game::instance()->setX() += 1;
}
// fps 60 update par seconde ticks
// a chaque update check si le x et y est deja hit

/* 
EACH FRAME 
	- save input
	- update entity
	- render
	- refresh
*/

int main()
{
	std::ofstream out("out.log");
	std::ifstream out_buf("out.log");
	std::streambuf *coutbuf = std::cout.rdbuf(); /* save buff */
	std::cout.rdbuf(out.rdbuf()); /* redirect std::cout to out.log */
	int direct;
	srand (time(NULL));	
	Game *g = Game::instance();
	clock_t	clock1 = clock();
	(void)clock1;
	(void)direct;
	// Node *entities = g->getEntity();
	// 40000
	initNcurse();
	g->init(); /* after initNcurse to get X and Y max*/
	g->startMessage();
	g->rmenu();
	while ((direct = getch()) != 10)
		if (direct == 'q')
			goto end;
	while(1)
	while (FPS(clock1))
	{
		direct = getch();
		if (direct == 'q')
			goto end;
		g->update(direct);
		g->render();
		refresh();
		clock1 = clock();
		g->setTicks()++;
	}
end:
	clear();
	endwin();
	delete g;
	std::cout.rdbuf(coutbuf); /* reset buff */
	// (void)out_buf;
	// std::cout << "***OUT.LOG****" << std::endl << out_buf.rdbuf() << std::endl << "***OUT.LOG****" << std::endl;
    return 0;
}
