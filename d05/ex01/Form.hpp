#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;
class Form {
	private:
		Form(void);
		std::string const name;
		int const grade_sign;
		int const grade_exec;
		bool is_signed;
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		Form(std::string,int,int);
		class GradeTooHighException: public std::exception {
			public:
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & src);
				GradeTooHighException& operator=(GradeTooHighException const & rhs);
				virtual const char* what() const throw();
				virtual ~GradeTooHighException(void) throw();
		 };
		class GradeTooLowException: public std::exception {
			public:
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & src);
				GradeTooLowException& operator=(GradeTooLowException const & rhs);
				virtual const char* what() const throw();
				virtual ~GradeTooLowException(void) throw();
		};
		/* function members (or methods) */
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSigned() const;
		void beSigned(Bureaucrat*);
		/* override */
		Form(Form const & src);
		Form& operator=(Form const & rhs);

		/* Destructors */
		virtual ~Form(void);
};

std::ostream& operator<<(std::ostream& out, Form const &i);

#endif
