#include "ShrubberyCreationForm.hpp"
#include <fstream>

/* Constructors */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shru", 145, 137, target) {
    return ;
}

/* function members */
// ShrubberyCreationForm::ERROR::~ERROR(void) throw() { }
// ShrubberyCreationForm::ERROR::ERROR(void) {  }
/* override */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	/* add logic */
	(void)rhs;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	Form::execute(executor);
	std::ofstream ofs(this->getTarget() + "_shrubbery");
	if (ofs.is_open()) {
		ofs << "ASCII trees" << std::endl;
		ofs.close();
	}
}

/* Destructors */
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    return ;
}
