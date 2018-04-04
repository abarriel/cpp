#ifndef C_HPP
# define C_HPP
# include <iostream>
# include "Base.hpp"

class C: public Base{
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		C(void);
		// class ERROR: public std::exception {
		// 	public:
		// 		ERROR(void);
		// 		ERROR(ERROR const & src);
		// 		ERROR& operator=(ERROR const & rhs);
		// 		virtual ~ERROR(void) throw();
		//  };
		/* function members (or methods) */

		/* override */
		
		C(C const & src);
		C& operator=(C const & rhs);

		/* Destructors */
		virtual ~C(void);
};

std::ostream& operator<<(std::ostream& out, C const &i);

#endif
