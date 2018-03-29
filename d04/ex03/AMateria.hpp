#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class AMateria {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		AMateria(void);

		/* function members (or methods) */

		/* override */
		AMateria(AMateria const & src);
		AMateria& operator=(AMateria const & rhs);

		/* Destructors */
		~AMateria(void);
};

std::ostream& operator<<(std::ostream& out, AMateria const &i);

#endif
