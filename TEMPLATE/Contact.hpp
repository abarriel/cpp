#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {
	public:
		/* Constructors - do not delete the default constructor (void) */
		Contact(void);

		/* override */
		Contact(Contact const & src);
		Contact& operator=(Contact const & rhs);
	
		/* Destructors */
		~Contact(void);
	private:
};

std::ostream& operator<<(std::ostream& out, Contact const &i);

#endif
