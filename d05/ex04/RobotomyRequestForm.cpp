#include "RobotomyRequestForm.hpp"

/* Constructors */
RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robo", 72, 45, target)  {
    return ;
}

/* function members */
// RobotomyRequestForm::ERROR::~ERROR(void) throw() { }
// RobotomyRequestForm::ERROR::ERROR(void) {  }
/* override */
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	/* add logic */
	(void)rhs;
	return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	Form::execute(executor);
	srand(time(NULL));
	if((rand() % 2))
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " failed to robotimized" << std::endl;
}
/* Destructors */
RobotomyRequestForm::~RobotomyRequestForm(void) {
    return ;
}
