#ifndef PLAYER_HPP
# define PLAYER_HPP
# include <iostream>
# include "AEntity.hpp"
class Player: public AEntity {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Player(void);

		/* function members (or methods) */
		Player* clone() const;		
		void attack(Enemy*);
		void attack(Player*);
		bool update();			
		bool update(int x, int y, bool isNeg);		
		
		// void update(void);
		/* override */
		Player(Player const & src);
		Player& operator=(Player const & rhs);

		/* Destructors */
		virtual ~Player(void);
};

std::ostream& operator<<(std::ostream& out, Player const &i);

#endif
