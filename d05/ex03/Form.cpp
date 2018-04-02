#include "Form.hpp"

/* Constructors */
Form::Form(std::string name, int grade_sign, int grade_exec, std::string target): name(name), grade_sign(grade_sign), grade_exec(grade_exec), is_signed(false), target(target) {
	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw Form::GradeTooLowException();
    return ;
}
Form::GradeTooHighException::~GradeTooHighException(void) throw() { }
Form::GradeTooHighException::GradeTooHighException(void) {  }
Form::isNotSigned::~isNotSigned(void) throw() { }
Form::isNotSigned::isNotSigned(void) {  }
const char* Form::isNotSigned::what() const throw() { return "not signed"; }
const char* Form::GradeTooHighException::what() const throw() { return "grade to high."; }
Form::GradeTooLowException::~GradeTooLowException(void) throw() {  }
Form::GradeTooLowException::GradeTooLowException(void) {  }
const char* Form::GradeTooLowException::what() const throw() { return "grade to low."; }
/* function members */
std::string Form::getName() const { return this->name; }
int Form::getGradeSign() const { return this->grade_sign; }
int Form::getGradeExec() const { return this->grade_exec; }
bool Form::getSigned() const { return this->is_signed; }
std::string Form::getTarget() const { return this->target; }
void Form::beSigned(Bureaucrat* b) {
	if (b->getGrade() > this->grade_sign)
		throw Form::GradeTooLowException();
	this->is_signed = true;
}
Form::Form(Form const & src): name(src.name), grade_sign(src.grade_sign), grade_exec(src.grade_exec), is_signed(false), target(src.target) {
	// *this = src;
    return ;
}

void Form::execute(Bureaucrat const & executor) const {
	if(!this->is_signed)
		throw Form::isNotSigned();
	if (executor.getGrade() > this->getGradeExec())
		throw Form::GradeTooLowException();
}

/* override */
Form& Form::operator=(Form const & rhs) {
	std::cout << "(Form) assignation operator called";
	/* add logic */
	this->is_signed = rhs.is_signed;
	return *this;
}

std::ostream& operator<<(std::ostream& out, Form const &i) {
	out << i.getName() << ", form grade required to sign:  " << i.getGradeSign();
	out << " grade required to execute: " << i.getGradeExec() << std::endl;	
	return out;
}

/* Destructors */
Form::~Form(void) {
	// std::cout << "(Form) destructor Form called" << std::endl;
    return ;
}
