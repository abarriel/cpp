#include "OfficeBlock.hpp"

/* Constructors */
OfficeBlock::OfficeBlock(void): i(NULL), b_s(NULL), b_e(NULL) {
	std::cout << "(OfficeBlock) default constructor called" << std::endl;
    return ;
}

OfficeBlock::OfficeBlock(Intern* i, Bureaucrat* b_s, Bureaucrat* b_e): i(i), b_s(b_s), b_e(b_e) {
	std::cout << "(OfficeBlock) default constructor called" << std::endl;
    return ;
}

/* function members */
// OfficeBlock::ERROR::~ERROR(void) throw() { }
// OfficeBlock::ERROR::ERROR(void) {  }
/* override */
OfficeBlock::forbidden::~forbidden(void) throw() { }
OfficeBlock::forbidden::forbidden(void) {  }
const char* OfficeBlock::forbidden::what() const throw() { return "forbidden to declare like that"; }

void OfficeBlock::setIntern(Intern& i) { this->i = &i; }
Bureaucrat *OfficeBlock::getBS() { return this->b_s; }
Bureaucrat *OfficeBlock::getBE() { return this->b_e; }

void OfficeBlock::setSigner(Bureaucrat& b) { 
	// std::cout << "setSigner added " << std::endl;
	this->b_s = &b;
}

void OfficeBlock::setExecutor(Bureaucrat& b) { 
	// std::cout << "setExecutor added " << std::endl;
	this->b_e = &b;
}

void OfficeBlock::doBureaucracy(std::string form, std::string target) {
	Form *f;
	f = this->i->makeFrom(form, target);
	this->b_s->signForm(f);
	this->b_e->executeForm(*f);
}


OfficeBlock& OfficeBlock::operator=(OfficeBlock const & rhs) {
	std::cout << "(OfficeBlock) assignation operator called";
	(void)rhs;
	throw OfficeBlock::forbidden();
	return *this;
}

std::ostream& operator<<(std::ostream& out, OfficeBlock const &i) {
	out << "(OfficeBlock) WARNING ! ADD A LOGIC <<" << std::endl;
	(void)i;
	return out;
}

OfficeBlock::OfficeBlock(OfficeBlock const & src) {
	(void)src;
	throw OfficeBlock::forbidden();
}

/* Destructors */
OfficeBlock::~OfficeBlock(void) {
	std::cout << "(OfficeBlock) destructor OfficeBlock called" << std::endl;
    return ;
}
