#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

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
		class GradeTooHighException: public std::exception { };
		class GradeTooLowException: public std::exception { };
		/* override */
		std::string getName()const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat& operator=(Bureaucrat const & rhs);

		/* Destructors */
		virtual ~Bureaucrat(void);
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const &i);

#endif
