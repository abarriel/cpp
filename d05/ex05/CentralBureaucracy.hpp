#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP
# include <iostream>
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

struct node
{
	std::string target;
	bool o;
	node* next;
};
class CentralBureaucracy {
	private:
		OfficeBlock ob[20];
		node *target;		
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		CentralBureaucracy(void);
		void feedOffice(Bureaucrat *b_s, Bureaucrat *b_e);
		void queueUp(std::string name);
		void doBureaucracy();
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
