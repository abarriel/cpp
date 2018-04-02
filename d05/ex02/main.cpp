#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	ShrubberyCreationForm sh = ShrubberyCreationForm("sh_Allan");
	RobotomyRequestForm rb = RobotomyRequestForm("rb_Allan");
	PresidentialPardonForm pp = PresidentialPardonForm("pp_Allan");
	srand((unsigned)NULL);
	try {
		Bureaucrat b = Bureaucrat("Bureau", 41);
		b.signForm(&rb);
		rb.execute(b);
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b = Bureaucrat("Bureau", 46);
		b.signForm(&rb);
		rb.execute(b);
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b = Bureaucrat("Bureau", 4);
		b.signForm(&pp);
		pp.execute(b);
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b = Bureaucrat("Bureau", 6);
		b.signForm(&pp);
		pp.execute(b);
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b = Bureaucrat("Bureau", 136);
		b.signForm(&sh);
		sh.execute(b);
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b = Bureaucrat("Bureau", 138);
		b.signForm(&sh);
		sh.execute(b);
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b = Bureaucrat("Bureau", 138);
		b.executeForm(sh);
		// sh.execute(b);
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b = Bureaucrat("Bureau", 110);
		b.executeForm(sh);
		// sh.execute(b);
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
	
}
