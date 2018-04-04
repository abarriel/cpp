#ifndef A_HPP
# define A_HPP
# include <iostream>
# include "Base.hpp"

class A: public Base {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		A(void);
		// class ERROR: public std::exception {
		// 	public:
		// 		ERROR(void);
		// 		ERROR(ERROR const & src);
		// 		ERROR& operator=(ERROR const & rhs);
		// 		virtual ~ERROR(void) throw();
		//  };
		/* function members (or methods) */

		/* override */

		A(A const & src);
		A& operator=(A const & rhs);

		/* Destructors */
		virtual ~A(void);
};

std::ostream& operator<<(std::ostream& out, A const &i);

#endif
