#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
/* Constructors */
Intern::Intern(void) {
	// std::cout << "(Intern) default constructor called" << std::endl;
    return ;
}

/* function members */
// Intern::ERROR::~ERROR(void) throw() { }
// Intern::ERROR::ERROR(void) {  }
/* override */
Intern::unknownForm::~unknownForm(void) throw() { }
Intern::unknownForm::unknownForm(void) {  }
const char* Intern::unknownForm::what() const throw() { return "the form is unknown"; }
Intern& Intern::operator=(Intern const & rhs) {
	std::cout << "(Intern) assignation operator called";
	/* add logic */
	(void)rhs;
	return *this;
}
Form *Intern::rrform(std::string name, std::string target){
	std::cout << "Intern creates " << name << std::endl;
	return new RobotomyRequestForm(target); 
}
Form *Intern::ppform(std::string name, std::string target){
	std::cout << "Intern creates " << name << std::endl;
	return new PresidentialPardonForm(target); 
}
Form *Intern::scform(std::string name, std::string target){
	std::cout << "Intern creates " << name << std::endl;
	return new ShrubberyCreationForm(target); 
}

Form *Intern::makeFrom(std::string name, std::string target) {
	const std::string f[] = { "robotomyRequest", "presidentialPardon", "shrubbberyCreation"};
	typedef Form*(Intern::*actions)(std::string, std::string);
    actions action[] = { &Intern::rrform, &Intern::ppform, &Intern::scform };

    for(int i = 0; i < 3; i++)
    {
		if(name == f[i])
			return (this->*action[i])(name, target);
    }
	throw Intern::unknownForm();
}

std::ostream& operator<<(std::ostream& out, Intern const &i) {
	out << "(Intern) WARNING ! ADD A LOGIC <<" << std::endl;
	(void)i;
	return out;
}

Intern::Intern(Intern const & src) {
	std::cout << "(Intern) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
Intern::~Intern(void) {
	// std::cout << "(Intern) destructor Intern called" << std::endl;
    return ;
}
