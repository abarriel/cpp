#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>

class Character {
	public:
		/* Constructors - do not delete the default constructor (void) */
		Character(void);

		/* override */
		Character(Character const & src);
		Character& operator=(Character const & rhs);
	
		/* Destructors */
		~Character(void);
	private:
};

std::ostream& operator<<(std::ostream& out, Character const &i);

#endif
