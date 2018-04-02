#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "Form.hpp"
class RobotomyRequestForm: public Form {
	private:
	protected:
		RobotomyRequestForm(void);
	public:
		/* Constructors - do not delete the default constructor (void) */
		RobotomyRequestForm(std::string);
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
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);

		/* Destructors */
		virtual ~RobotomyRequestForm(void);
};

std::ostream& operator<<(std::ostream& out, RobotomyRequestForm const &i);

#endif
