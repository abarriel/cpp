#ifndef GAME_HPP
# define GAME_HPP
# include <iostream>
# include <ncurses.h>
# include <fstream>
# include <string>
# include <sstream>
# include "AEntity.hpp"
# include "Bullet.hpp"
# include "Game.hpp"
# include "Player.hpp"
# include "Enemy.hpp"

struct Node
{
	AEntity *entity;
	Node* next;
};

class Game {
	private:
	protected:
		int x;
		int y;
		int direction;
		bool end;
		int maxEntity;
		Node *e;
		static Game *p_instance;
	public:
		/* Constructors - do not delete the default constructor (void) */
		Game(void);
		Game(int x, int y);
		static Game *instance();
		/* function members (or methods) */
		int getX(void) const;
		int getMaxEntity(void) const;
		void addEntity(AEntity* unit);
		void deleleEntity(AEntity *unit);
		Node* getEntity();
		void init();
		std::string getFile(std::string s);		
		int getY(void) const;
		int getDir(void) const;
		bool getEnd() const;
		int& setMaxEntity(void);
		int& setDir(void);
		int& setX();
		int& setY();
		bool& setEnd();
		void startMessage();
		/* override */
		Game(Game const & src);
		Game& operator=(Game const & rhs);

		/* Destructors */
		~Game(void);
};

std::ostream& operator<<(std::ostream& out, Game const &i);

#endif
