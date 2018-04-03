#include "Bureaucrat.hpp"

/* Constructors */
Bureaucrat::Bureaucrat(std::string name, int grade): name(name) {
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
    return ;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() { }
Bureaucrat::GradeTooHighException::GradeTooHighException(void) {  }
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {  }
Bureaucrat::GradeTooLowException::GradeTooLowException(void) {  }
/* function members */
std::string Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incGrade() {
	this->grade -= 1;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::executeForm(Form const & form) {
	try {
		form.execute(*this);
		std::cout << this->name << " executes " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error happens : " << e.what() << std::endl;
	}
}

void Bureaucrat::decGrade() {
	this->grade += 1;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
/* override */
Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs) {
	std::cout << "(Bureaucrat) assignation operator called";
	/* add logic */
	this->grade = rhs.grade;
	return *this;
}

void Bureaucrat::signForm(Form* p) {
	std::cout << this->name << " signs " << p->getName() << std::endl;
	try {
		p->beSigned(this);	
		std::cout << this->name << " signs " << p->getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->name << " cannot sign " << p->getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const &i) {
	out << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return out;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	*this = src;
    return ;
}

/* Destructors */
Bureaucrat::~Bureaucrat(void) {
    return ;
}
