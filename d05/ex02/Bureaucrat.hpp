#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"
class Form;
class Bureaucrat {
	private:
	protected:
		Bureaucrat(void);
		std::string const name;
		int grade;
	public:
		/* Constructors - do not delete the default constructor (void) */
		Bureaucrat(std::string name, int grade);
		/* function members (or methods) */
		class GradeTooHighException: public std::exception {
			public:
				GradeTooHighException(void);
				GradeTooHighException(GradeTooHighException const & src);
				GradeTooHighException& operator=(GradeTooHighException const & rhs);
				virtual ~GradeTooHighException(void) throw();
		 };
		class GradeTooLowException: public std::exception {
			public:
				GradeTooLowException(void);
				GradeTooLowException(GradeTooLowException const & src);
				GradeTooLowException& operator=(GradeTooLowException const & rhs);
				virtual ~GradeTooLowException(void) throw();
		};
		/* override */
		void executeForm(Form const & form);
		std::string getName()const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		void signForm(Form*);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat& operator=(Bureaucrat const & rhs);

		/* Destructors */
		virtual ~Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const &i);

#endif
