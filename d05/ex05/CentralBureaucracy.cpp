#include "CentralBureaucracy.hpp"

/* Constructors */
CentralBureaucracy::CentralBureaucracy(void): i(NULL), b_s(NULL), b_e(NULL) {
	std::cout << "(CentralBureaucracy) default constructor called" << std::endl;
    return ;
}

CentralBureaucracy::CentralBureaucracy(Intern* i, Bureaucrat* b_s, Bureaucrat* b_e): i(i), b_s(b_s), b_e(b_e) {
	std::cout << "(CentralBureaucracy) default constructor called" << std::endl;
    return ;
}

/* function members */
// CentralBureaucracy::ERROR::~ERROR(void) throw() { }
// CentralBureaucracy::ERROR::ERROR(void) {  }
/* override */
CentralBureaucracy::forbidden::~forbidden(void) throw() { }
CentralBureaucracy::forbidden::forbidden(void) {  }
const char* CentralBureaucracy::forbidden::what() const throw() { return "forbidden to declare like that"; }

void CentralBureaucracy::setIntern(Intern& i) { this->i = &i; }

void CentralBureaucracy::setSigner(Bureaucrat& b) { this->b_s = &b;}

void CentralBureaucracy::setExecutor(Bureaucrat& b) { this->b_e = &b; }

void CentralBureaucracy::doBureaucracy(std::string form, std::string target) {
	Form *f;
	f = this->i->makeFrom(form, target);
	this->b_s->signForm(f);
	this->b_e->executeForm(*f);
}


CentralBureaucracy& CentralBureaucracy::operator=(CentralBureaucracy const & rhs) {
	std::cout << "(CentralBureaucracy) assignation operator called";
	(void)rhs;
	throw CentralBureaucracy::forbidden();
	return *this;
}

std::ostream& operator<<(std::ostream& out, CentralBureaucracy const &i) {
	out << "(CentralBureaucracy) WARNING ! ADD A LOGIC <<" << std::endl;
	(void)i;
	return out;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const & src) {
	(void)src;
	throw CentralBureaucracy::forbidden();
}

/* Destructors */
CentralBureaucracy::~CentralBureaucracy(void) {
	std::cout << "(CentralBureaucracy) destructor CentralBureaucracy called" << std::endl;
    return ;
}
