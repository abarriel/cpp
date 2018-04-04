#ifndef B_HPP
# define B_HPP
# include <iostream>
# include "Base.hpp"

class B: public Base {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		B(void);
		// class ERROR: public std::exception {
		// 	public:
		// 		ERROR(void);
		// 		ERROR(ERROR const & src);
		// 		ERROR& operator=(ERROR const & rhs);
		// 		virtual ~ERROR(void) throw();
		//  };
		/* function members (or methods) */

		/* override */

		B(B const & src);
		B& operator=(B const & rhs);

		/* Destructors */
		virtual ~B(void);
};

std::ostream& operator<<(std::ostream& out, B const &i);

#endif
