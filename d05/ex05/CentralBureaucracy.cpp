#include "CentralBureaucracy.hpp"

/* Constructors */
CentralBureaucracy::CentralBureaucracy(void): target(NULL) {
	std::cout << "(CentralBureaucracy) default constructor called" << std::endl;
    return ;
}

void CentralBureaucracy::queueUp(std::string name) {
	// std::cout <<  "push" << std::endl;
	node *begin = this->target;
	if (!target)
		return ;
	node *nw = new node();
	nw->target = name;
	nw->o = true;
	nw->next = NULL;
	if (!this->target) {
			this->target = nw;
			return;
	}
	while (this->target->next)
		this->target = this->target->next;
	this->target->next = nw;
	this->target = begin;
	return;
}

void CentralBureaucracy::feedOffice(Bureaucrat *b_s, Bureaucrat *b_e) {
	// dump 
	int i;
	i = 0;
	for(; i < 20; i++) {
		if(!this->ob[i].getBE() && !this->ob[i].getBS())
		{
			Intern  *idiotOne = new Intern();
			this->ob[i].setIntern(*idiotOne);
			this->ob[i].setExecutor(*b_e);
			this->ob[i].setSigner(*b_s);
			return ;
		}
	}
	std::cout << "Bureaucrat is full, I reject you" << std::endl;
}

std::string getTarget(node *t) {
	while(t) {
		if(t->o)
		 {
			 t->o = false;
			 return t->target;
		 }
		t = t->next;
	}
	return "targetEmpty";
}

void CentralBureaucracy::doBureaucracy() {
	const std::string f[] = { "robotomyRequest", "presidentialPardon", "shrubbberyCreation"};
	for (int i = 0; i < 10; i++) 
		this->ob[i].doBureaucracy(f[i % 3], getTarget(this->target));
}

CentralBureaucracy& CentralBureaucracy::operator=(CentralBureaucracy const & rhs) {
	std::cout << "(CentralBureaucracy) assignation operator called";
	(void)rhs;
	return *this;
}

std::ostream& operator<<(std::ostream& out, CentralBureaucracy const &i) {
	out << "(CentralBureaucracy) WARNING ! ADD A LOGIC <<" << std::endl;
	(void)i;
	return out;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const & src) {
	(void)src;
}

/* Destructors */
CentralBureaucracy::~CentralBureaucracy(void) {
	std::cout << "(CentralBureaucracy) destructor CentralBureaucracy called" << std::endl;
    return ;
}
