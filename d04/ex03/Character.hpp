#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>

class Character {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Character(void);

		/* function members (or methods) */

		/* override */
		Character(Character const & src);
		Character& operator=(Character const & rhs);

		/* Destructors */
		~Character(void);
};

std::ostream& operator<<(std::ostream& out, Character const &i);

#endif
