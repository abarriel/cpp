#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Contact(void);

		/* function members (or methods) */

		/* override */
		Contact(Contact const & src);
		Contact& operator=(Contact const & rhs);

		/* Destructors */
		~Contact(void);
};

std::ostream& operator<<(std::ostream& out, Contact const &i);

#endif
