#ifndef BULLET_HPP
# define BULLET_HPP
# include <iostream>
# include "AEntity.hpp"
class Bullet: public AEntity {
	private:
	protected:
		bool isNeg;		
	public:
		/* Constructors - do not delete the default constructor (void) */
		Bullet(void);
		Bullet(int i);
		Bullet(int i, bool);
	
		/* function members (or methods) */
		bool update();	
		// bool update(int x, int y, bool isNeg);		
		Bullet* clone() const;
		/* override */
		Bullet(Bullet const & src);
		Bullet& operator=(Bullet const & rhs);
		void attack(Enemy*);
		void attack(Player*);
		
		/* Destructors */
		virtual ~Bullet(void);
};

std::ostream& operator<<(std::ostream& out, Bullet const &i);

#endif
