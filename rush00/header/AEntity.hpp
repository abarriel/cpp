#ifndef AENTITY_HPP
# define AENTITY_HPP
# include <iostream>
class Game;
class Enemy;
class Player;
class Bullet;
class AEntity {
	private:
	protected:
		int	x; /* current position (take in account the size) */
		int	y; /* current position (take in account the size) */
		int	hp; /* HP point */
		// std::string type*/
		int	yMax; /* Box size */
		int	xMax; /* Box size */
		int style; /* ncurse style */
		int	damageCost; /* damage Given */
		bool live; /* is alive */
		bool isNeg;
		std::string *shape; /* string */
	public:
		/* Constructors - do not delete the default constructor (void) */
		AEntity(void);
		AEntity(Enemy *);
		AEntity(Enemy *, int);
		AEntity(Player *);
		AEntity(Bullet *, int);
		void init(int i);		
		int getX() const; 
		int getXmax() const; 
		int getYmax() const;
		int getY() const;
		int getHP() const;
		int getStyle() const;
		int getDamageCost() const;
		std::string *getShape() const;
		bool getLive() const;

		virtual AEntity* clone() const = 0;	
		int& setX();
		int& setY();
		int& setHP();
		int& setStyle();
		int& setDamageCost();
		bool& setLive();
		void getInfos() const;
		/* function members (or methods) */
		void takeDamage(int dama);
		// void attack(Enemy*);
		// void attack(Player*);
		// void attack(Bullet*);

		virtual bool update(int x, int y, bool isNeg);
		virtual bool update();
		/* override */
		AEntity(AEntity const & src);
		AEntity& operator=(AEntity const & rhs);

		/* Destructors */
		virtual ~AEntity(void);
};

# include "Game.hpp"
std::ostream& operator<<(std::ostream& out, AEntity const &i);

struct Entity
{
	std::string path;
	int	hp;
	int	damageCost;
	int style;
	int	yMax; 
	int	xMax; 
};

#define ENEMY_LEN 8
#define BULLET_LEN 3
// rgb(234, 32, 39)
    // init_pair(0, COLOR_CYAN, COLOR_BLACK);
    // init_pair(1, COLOR_RED, COLOR_BLACK); /* id, foreground, background */
    // init_pair(2, COLOR_GREEN, COLOR_BLACK);
    // init_pair(3, COLOR_BLUE, COLOR_BLACK);
    // init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
static Entity entity[]  = {
	{ "enemy1", 8, 25, 1, 4, 6 },
	{ "enemy2", 20, 70, 3, 4, 12 },
	{ "enemy3", 8, 25, 3, 3, 9 },
	{ "enemy4", 8, 25, 4, 3, 7 },
	{ "enemy5", 40, 100, 5, 5, 13 },
	{ "mur_left", 9999999, 9999999, 5, 84, 40 },
	{ "mur_right", 9999999, 9999999, 5, 84, 40 },
	{ "boss", 60, 99999998, 1, 62, 152 },
	{ "bullet1", 1, 4, 0, 1, 1 },
	{ "bullet2", 1, 8, 0, 2, 2 },
	{ "bullet3", 1, 14, 0, 3, 5 },
	{ "player", 100, 10, 2, 6, 13 } // size may change
};

#endif
