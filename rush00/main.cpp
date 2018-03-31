#include "Game.hpp"
#define FPS(tms)  (clock() - tms > 3000)

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
	clear();
	delete Game::instance();
	exit(0);
}
void render() {

}
// a chaque update check si le x et y est deja hit
void boxx() {
	clear();
	box(stdscr, '|', '-');
	wrefresh(stdscr);
}
int main()
{
	std::ofstream out("out.log");
	std::ifstream out_buf("out.log");
	std::streambuf *coutbuf = std::cout.rdbuf(); /* save buff */
	std::cout.rdbuf(out.rdbuf()); /* redirect std::cout to out.log */
	int direct;
	Game *g = Game::instance();
	clock_t	clock1 = clock();
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
		clock1 = clock();
		refresh();		
	}
end:
	clear();
	endwin();
	delete g;
	std::cout.rdbuf(coutbuf); /* reset buff */
	std::cout << "***OUT.LOG****" << std::endl << out_buf.rdbuf() << std::endl << "***OUT.LOG****" << std::endl;
    return 0;
}
