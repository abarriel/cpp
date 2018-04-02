#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Contact(void);
		// class ERROR: public std::exception {
		// 	public:
		// 		ERROR(void);
		// 		ERROR(ERROR const & src);
		// 		ERROR& operator=(ERROR const & rhs);
		// 		virtual ~ERROR(void) throw();
		//  };
		/* function members (or methods) */

		/* override */
		Contact(Contact const & src);
		Contact& operator=(Contact const & rhs);

		/* Destructors */
		virtual ~Contact(void);
};

std::ostream& operator<<(std::ostream& out, Contact const &i);

#endif
