// #include "ShrubberyCreationForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int main() {
    const std::string name[] = { "Martin", "Bernard", "Thomas", "Petit", "Robert", "Richard", "Durand", "Dubois", "Moreau", "Laurent", "Simon", "Michel", "Lefebvre", "Leroy", "Roux", "David", "Bertrand", "Morel", "Fournier", "Girard", "Bonnet", "Dupont", "Lambert", "Fontaine", "Rousseau", "Vincent", "Muller", "Lefevre", "Faure", "Andre", "Mercier", "Blanc", "Guerin", "Boyer", "Garnier", "Chevalier", "Francois", "Legrand", "Gauthier", "Garcia", "Perrin", "Robin", "Clement", "Morin", "Nicolas", "Henry", "Roussel", "Mathieu", "Gautier", "Masson", "Marchand", "Duval", "Denis", "Dumont", "Marie", "Lemaire", "Noel", "Meyer", "Dufour", "Meunier", "Brun", "Blanchard", "Giraud", "Joly", "Riviere", "Lucas", "Brunet", "Gaillard", "Barbier", "Arnaud", "Martinez", "Gerard", "Roche", "Renard", "Schmitt", "Roy", "Leroux", "Colin", "Vidal", "Caron", "Picard", "Roger", "Fabre", "Aubert", "Lemoine", "Renaud", "Dumas", "Lacroix", "Olivier", "Philippe", "Bourgeois", "Pierre", "Benoit", "Rey", "Leclerc", "Payet", "Rolland", "Leclercq", "Guillaume", "Lecomte", "Lopez", "Jean", "Dupuy", "Guillot", "Hubert", "Berger", "Carpentier", "Sanchez", "Dupuis", "Moulin", "Louis", "Deschamps", "Huet", "Vasseur", "Perez", "Boucher", "Fleury", "Royer", "Klein", "Jacquet", "Adam", "Paris", "Poirier", "Marty", "Aubry", "Guyot", "Carre", "Charles", "Renault", "Charpentier", "Menard", "Maillard", "Baron", "Bertin", "Bailly", "Herve", "Schneider", "Fernandez", "Lel", "Collet", "Leger", "Bouvier", "Julien", "Prevost", "Millet", "Perrot", "Daniel", "Lex", "Cousin", "Germain", "Breton", "Besson", "Langlois", "Remy", "Lef", "Pelletier", "Leveque", "Perrier", "Leblanc", "Barre", "Lebrun", "Marchal", "Weber", "Mallet", "Hamon", "Boulanger", "Jacob", "Monnier", "Michaud", "Rodriguez", "Guichard", "Gillet", "Etienne", "Grondin", "Poulain", "Tessier", "Chevallier", "Collin", "Chauvin", "Dava", "Bouchet", "Gay", "Lemaitre", "Benard", "Marechal", "Humbert", "Reynaud", "Antoine", "Hoarau", "Perret", "Barthelemy", "Cordier", "Pichon", "Lejeune", "Gilbert", "Lamy", "Delaunay", "Pasquier", "Carlier", "Laporte" };
	CentralBureaucracy cb;
	Bureaucrat *b[20];
	for(int i = 0; i < 20; i++) {
		b[i] = new Bureaucrat(name[i], 3);
	}
	for(int i = 0; i < 20; i += 2) {
		cb.feedOffice(b[i], b[i + 1]);
		std::cout << std::endl;
	}
	for(int i = 0; i < 20; i++)
		cb.queueUp(name[i]);
	cb.doBureaucracy();
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// cb.feedOffice(b[0], b[1]);
	// Intern      idiotOne;
	// Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 22);
	// Bureaucrat  bob = Bureaucrat("Bobby Bobson", 3);
	// OfficeBlock ob;
	// ob.setIntern(idiotOne);
	// ob.setSigner(bob);
	// ob.setExecutor(hermes);
	// try {
	// 	ob.doBureaucracy("mutant pig termination", "Pigley");
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// } 
	// try {
	// 	ob.doBureaucracy("robotomyRequest", "Pigley");
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// } 
}
