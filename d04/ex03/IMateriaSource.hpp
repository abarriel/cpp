#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>

class IMateriaSource {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		IMateriaSource(void);

		/* function members (or methods) */

		/* override */
		IMateriaSource(IMateriaSource const & src);
		IMateriaSource& operator=(IMateriaSource const & rhs);

		/* Destructors */
		~IMateriaSource(void);
};

std::ostream& operator<<(std::ostream& out, IMateriaSource const &i);

#endif
