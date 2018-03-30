#ifndef BULLET_HPP
# define BULLET_HPP
# include <iostream>
# include "AEntity.hpp"

class Bullet: public AEntity {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Bullet(void);
		Bullet(int i);

		/* function members (or methods) */

		/* override */
		Bullet(Bullet const & src);
		Bullet& operator=(Bullet const & rhs);
		void attack(Enemy*);
		void attack(Player*);
		
		/* Destructors */
		~Bullet(void);
};

std::ostream& operator<<(std::ostream& out, Bullet const &i);

#endif
