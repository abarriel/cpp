// #include "ShrubberyCreationForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
int main() {
	Intern intern;
	Form *r;
	try {
		r = intern.makeFrom("robotomy request", "Bender");	
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
	try {
		r = intern.makeFrom("robotomyRequest", "Bender");	
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
		try {
		r = intern.makeFrom("presidentialPardon", "Bender");	
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
		try {
		r = intern.makeFrom("shrubbberyCreation", "Bender");	
	} catch (std::exception& e) {
		std::cout << "ERREUR HAPPEND: " << e.what() << std::endl;
	}
}
