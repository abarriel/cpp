#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
#include "Form.hpp"
class PresidentialPardonForm: public Form {
	private:
	protected:
		PresidentialPardonForm(void);
	public:
		/* Constructors - do not delete the default constructor (void) */
		PresidentialPardonForm(std::string);
		// class ERROR: public std::exception {
		// 	public:
		// 		ERROR(void);
		// 		ERROR(ERROR const & src);
		// 		ERROR& operator=(ERROR const & rhs);
		// 		virtual ~ERROR(void) throw();
		//  };
		/* function members (or methods) */
		void execute(Bureaucrat const & executor) const;

		/* override */
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);

		/* Destructors */
		virtual ~PresidentialPardonForm(void);
};

std::ostream& operator<<(std::ostream& out, PresidentialPardonForm const &i);

#endif
