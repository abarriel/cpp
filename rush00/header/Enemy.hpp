#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>
# include "AEntity.hpp"

class Enemy: public AEntity {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Enemy(void);
		Enemy(int);

		/* function members (or methods) */
		Enemy* clone() const;
		// void update(int x, int y, bool isNeg);		
		bool update();	
		bool update(int x, int y, bool isNeg);		
			
		/* override */
		Enemy(Enemy const & src);
		Enemy& operator=(Enemy const & rhs);
		void attack(Enemy*);
		void attack(Player*);
		
		/* Destructors */
		virtual ~Enemy(void);
};

std::ostream& operator<<(std::ostream& out, Enemy const &i);

#endif
