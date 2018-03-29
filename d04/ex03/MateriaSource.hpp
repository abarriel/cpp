#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>

class MateriaSource {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		MateriaSource(void);

		/* function members (or methods) */

		/* override */
		MateriaSource(MateriaSource const & src);
		MateriaSource& operator=(MateriaSource const & rhs);

		/* Destructors */
		~MateriaSource(void);
};

std::ostream& operator<<(std::ostream& out, MateriaSource const &i);

#endif
