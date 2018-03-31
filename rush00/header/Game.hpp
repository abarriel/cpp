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
		static Game *instance();
		/* render */
		void rmenu(); /* menu */
		void render();

		void update(int direction);
		/* function members (or methods) */
		void addEntity(AEntity* unit);
		void deleleEntity(AEntity *unit);
		void init();
		std::string getFile(std::string s);		
		void startMessage();

		/* accessors */
		Node* getEntity();
		AEntity* getPlayer();		
		int getX(void) const;
		int getY(void) const;
		int getDir(void) const;
		bool getEnd() const;
		int getMaxEntity(void) const;
		int& setMaxEntity(void);
		int& setDir(void);
		int& setX();
		int& setY();
		bool& setEnd();
		/* override */
		Game(Game const & src);
		Game& operator=(Game const & rhs);

		/* Destructors */
		~Game(void);
};

std::ostream& operator<<(std::ostream& out, Game const &i);

#endif
