#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>

class Enemy {
	public:
		/* Constructors - do not delete the default constructor (void) */
		Enemy(void);

		/* override */
		Enemy(Enemy const & src);
		Enemy& operator=(Enemy const & rhs);
	
		/* Destructors */
		~Enemy(void);
	private:
};

std::ostream& operator<<(std::ostream& out, Enemy const &i);

#endif
