#ifndef GAME_HPP
# define GAME_HPP
# include <iostream>
# include <ncurses.h>
# include <fstream>
# include <string>
# include <sstream>
// # include "Game.hpp"
# include "AEntity.hpp"
# include "Bullet.hpp"
# include "Player.hpp"
# include "Enemy.hpp"

class AEntity;
// class Player;
struct Node
{
	AEntity *entity;
	Node* next;
};

class Game {
	private:
	protected:
		int x;
		int ticks;
		int y;
		int direction;
		bool end;
		int maxEntity;
		Node *e;
		int lvl;
		int score;
		static Game *p_instance;
	public:
		/* Constructors - do not delete the default constructor (void) */
		Game(void);
		static Game *instance();
		/* render */
		void rmenu(); /* menu */
		void render();
		void printShape(AEntity *e) const;
		void update(int direction);
		/* function members (or methods) */
		void addEntity(AEntity* unit);
		void deleleEntity(AEntity *unit);
		AEntity *getEntity(AEntity *);
		void boss();
		// void updateEntity(Bullet *);
		// void updateEntity(Enemy *);
		// void updateEntity(Player *, int x, int y, bool isNeg);

		void init();
		std::string *getFile(std::string s);		
		void startMessage();
		void endMessage();
		void winMessage();
		void printBG();

		/* accessors */
		Node* getEntity();
		AEntity* getPlayer();		
		int getX(void) const;
		int getY(void) const;
		int getTicks(void) const;
		int getDir(void) const;
		int getScore() const;
		int getlvl() const;
		bool getEnd() const;
		int getMaxEntity(void) const;
		int& setMaxEntity(void);
		int& setDir(void);
		int& setX();
		int& setlvl();
		int& setScore();
		int& setTicks();
		int& setY();
		bool& setEnd();
		/* override */
		Game(Game const & src);
		Game& operator=(Game const & rhs);

		/* Destructors */
		virtual ~Game(void);
};
std::ostream& operator<<(std::ostream& out, Game const &i);

#endif
