#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP
# include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

class CentralBureaucracy {
	private:
		Intern *i;
		Bureaucrat *b_s;
		Bureaucrat *b_e;
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		CentralBureaucracy(void);
		CentralBureaucracy(Intern*, Bureaucrat*, Bureaucrat*);
		class forbidden: public std::exception {
			public:
				forbidden(void);
				forbidden(forbidden const & src);
				forbidden& operator=(forbidden const & rhs);
				virtual const char* what() const throw();				
				virtual ~forbidden(void) throw();
		 };
		void setIntern(Intern&);
		void setSigner(Bureaucrat&);
		void setExecutor(Bureaucrat&);
		void doBureaucracy(std::string, std::string);
		// class ERROR: public std::exception {
		// 	public:
		// 		ERROR(void);
		// 		ERROR(ERROR const & src);
		// 		ERROR& operator=(ERROR const & rhs);
		// 		virtual ~ERROR(void) throw();
		//  };
		/* function members (or methods) */

                // __Setter__
		/* override */
		CentralBureaucracy(CentralBureaucracy const & src);
		CentralBureaucracy& operator=(CentralBureaucracy const & rhs);

		/* Destructors */
		virtual ~CentralBureaucracy(void);
};

std::ostream& operator<<(std::ostream& out, CentralBureaucracy const &i);

#endif
