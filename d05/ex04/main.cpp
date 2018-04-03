// #include "ShrubberyCreationForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main() {
	Intern      idiotOne;
	Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 22);
	Bureaucrat  bob = Bureaucrat("Bobby Bobson", 3);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	try {
		ob.doBureaucracy("mutant pig termination", "Pigley");
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} 
	try {
		ob.doBureaucracy("robotomyRequest", "Pigley");
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	} 
}
