#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Bureaucrat(void);

		/* function members (or methods) */

		/* override */
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat& operator=(Bureaucrat const & rhs);

		/* Destructors */
		~Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const &i);

#endif
