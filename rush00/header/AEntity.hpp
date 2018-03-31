#ifndef AENTITY_HPP
# define AENTITY_HPP
# include <iostream>
// # include "Game.hpp"

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
		int	size; /* Box size */
		int style; /* ncurse style */
		int	damageCost; /* damage Given */
		bool live; /* is alive */
		std::string shape; /* string */
	public:
		/* Constructors - do not delete the default constructor (void) */
		AEntity(void);
		AEntity(Enemy *);
		AEntity(Player *);
		AEntity(Bullet *, int);
		void init(int i);		
		int getX() const; 
		int getY() const;
		int getHP() const;
		int getSize() const;
		int getStyle() const;
		int getDamageCost() const;
		std::string getShape() const;
		bool getLive() const;
		virtual AEntity* clone() const = 0;	
		int& setX();
		int& setY();
		int& setHP();
		int& setSize();
		int& setStyle();
		int& setDamageCost();
		bool& setLive();
		void getInfos() const;
		/* function members (or methods) */
		void takeDamage(int dama);
		// void attack(Enemy*);
		// void attack(Player*);
		// void attack(Bullet*);

		void update(Enemy *);
		void update(Player *);
		void update(Bullet *);
		/* override */
		AEntity(AEntity const & src);
		AEntity& operator=(AEntity const & rhs);

		/* Destructors */
		virtual ~AEntity(void);
};


std::ostream& operator<<(std::ostream& out, AEntity const &i);

struct Entity
{
	std::string path;
	int	hp;
	int	size; 
	int	damageCost;
	int style;
};

#define ENEMY_LEN 5 
#define BULLET_LEN 3

static Entity entity[]  = {
	{ "enemy1", 8, 4, 25, 0 },
	{ "enemy2", 20, 12, 70, 0 },
	{ "enemy3", 8, 4, 25, 0 },
	{ "enemy4", 8, 4, 25, 0 },
	{ "enemy5", 60, 13, 100, 0 },
	{ "bullet1", 1, 1, 4, 0 },
	{ "bullet2", 1, 2, 8, 0 },
	{ "bullet3", 1, 3, 10, 0 },
	{ "player", 100, 14, 10, 0 } // size may change
};

#endif
