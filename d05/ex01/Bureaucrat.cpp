#include "Bureaucrat.hpp"

/* Constructors */
Bureaucrat::Bureaucrat(std::string name, int grade): name(name) {
	if(grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if(grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
    return ;
}

/* function members */
std::string Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incGrade() {
	this->grade -= 1;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decGrade() {
	this->grade += 1;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooHighException();
}
/* override */
Bureaucrat& Bureaucrat::operator=(Bureaucrat const & rhs) {
	std::cout << "(Bureaucrat) assignation operator called";
	/* add logic */
	this->grade = rhs.grade;
	return *this;
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
