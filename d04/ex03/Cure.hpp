#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>

class Cure {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Cure(void);

		/* function members (or methods) */

		/* override */
		Cure(Cure const & src);
		Cure& operator=(Cure const & rhs);

		/* Destructors */
		~Cure(void);
};

std::ostream& operator<<(std::ostream& out, Cure const &i);

#endif
