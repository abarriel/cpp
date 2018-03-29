#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <iostream>

class ICharacter {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		ICharacter(void);

		/* function members (or methods) */

		/* override */
		ICharacter(ICharacter const & src);
		ICharacter& operator=(ICharacter const & rhs);

		/* Destructors */
		~ICharacter(void);
};

std::ostream& operator<<(std::ostream& out, ICharacter const &i);

#endif
