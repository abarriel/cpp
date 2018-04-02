#include "PresidentialPardonForm.hpp"

/* Constructors */
PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presi", 25, 5, target)  {
	// std::cout << "(PresidentialPardonForm) default constructor called" << std::endl;
    return ;
}

/* function members */
// PresidentialPardonForm::ERROR::~ERROR(void) throw() { }
// PresidentialPardonForm::ERROR::ERROR(void) {  }
/* override */
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	// std::cout << "(PresidentialPardonForm) assignation operator called";
	/* add logic */
	(void)rhs;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	Form::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

/* Destructors */
PresidentialPardonForm::~PresidentialPardonForm(void) {
    return ;
}
