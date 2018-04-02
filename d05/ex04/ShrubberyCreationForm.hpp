#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form {
	private:
	protected:
		ShrubberyCreationForm(void);
	public:
		/* Constructors - do not delete the default constructor (void) */
		ShrubberyCreationForm(std::string);
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
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);

		/* Destructors */
		virtual ~ShrubberyCreationForm(void);
};

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm const &i);

#endif
