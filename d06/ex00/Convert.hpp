#ifndef CONVERT_HPP
# define CONVERT_HPP
# include <iostream>

class Convert {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Convert(void);
		// class ERROR: public std::exception {
		// 	public:
		// 		ERROR(void);
		// 		ERROR(ERROR const & src);
		// 		ERROR& operator=(ERROR const & rhs);
		// 		virtual ~ERROR(void) throw();
		//  };
		/* function members (or methods) */

		/* override */
		Convert(Convert const & src);
		Convert& operator=(Convert const & rhs);

		/* Destructors */
		virtual ~Convert(void);
};

std::ostream& operator<<(std::ostream& out, Convert const &i);

#endif
