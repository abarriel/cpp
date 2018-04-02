#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "Form.hpp"

class Intern {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Intern(void);
		class unknownForm: public std::exception {
			public:
				unknownForm(void);
				unknownForm(unknownForm const & src);
				unknownForm& operator=(unknownForm const & rhs);
				virtual const char* what() const throw();				
				virtual ~unknownForm(void) throw();
		 };
		// class ERROR: public std::exception {
		// 	public:
		// 		ERROR(void);
		// 		ERROR(ERROR const & src);
		// 		ERROR& operator=(ERROR const & rhs);
		// 		virtual ~ERROR(void) throw();
		//  };
		/* function members (or methods) */
		Form *makeFrom(std::string, std::string);
		/* override */
		Intern(Intern const & src);
		Intern& operator=(Intern const & rhs);

		/* Destructors */
		virtual ~Intern(void);
};

std::ostream& operator<<(std::ostream& out, Intern const &i);

#endif
