#include <iostream>
#include "ZombieHorde.hpp"
#define LEN(name) sizeof(name) / sizeof(std::string)
#include <ctime>

ZombieHorde::ZombieHorde(int nb): nb_zombie(nb) {
    const std::string name[] = { "Martin", "Bernard", "Thomas", "Petit", "Robert", "Richard", "Durand", "Dubois", "Moreau", "Laurent", "Simon", "Michel", "Lefebvre", "Leroy", "Roux", "David", "Bertrand", "Morel", "Fournier", "Girard", "Bonnet", "Dupont", "Lambert", "Fontaine", "Rousseau", "Vincent", "Muller", "Lefevre", "Faure", "Andre", "Mercier", "Blanc", "Guerin", "Boyer", "Garnier", "Chevalier", "Francois", "Legrand", "Gauthier", "Garcia", "Perrin", "Robin", "Clement", "Morin", "Nicolas", "Henry", "Roussel", "Mathieu", "Gautier", "Masson", "Marchand", "Duval", "Denis", "Dumont", "Marie", "Lemaire", "Noel", "Meyer", "Dufour", "Meunier", "Brun", "Blanchard", "Giraud", "Joly", "Riviere", "Lucas", "Brunet", "Gaillard", "Barbier", "Arnaud", "Martinez", "Gerard", "Roche", "Renard", "Schmitt", "Roy", "Leroux", "Colin", "Vidal", "Caron", "Picard", "Roger", "Fabre", "Aubert", "Lemoine", "Renaud", "Dumas", "Lacroix", "Olivier", "Philippe", "Bourgeois", "Pierre", "Benoit", "Rey", "Leclerc", "Payet", "Rolland", "Leclercq", "Guillaume", "Lecomte", "Lopez", "Jean", "Dupuy", "Guillot", "Hubert", "Berger", "Carpentier", "Sanchez", "Dupuis", "Moulin", "Louis", "Deschamps", "Huet", "Vasseur", "Perez", "Boucher", "Fleury", "Royer", "Klein", "Jacquet", "Adam", "Paris", "Poirier", "Marty", "Aubry", "Guyot", "Carre", "Charles", "Renault", "Charpentier", "Menard", "Maillard", "Baron", "Bertin", "Bailly", "Herve", "Schneider", "Fernandez", "Lel", "Collet", "Leger", "Bouvier", "Julien", "Prevost", "Millet", "Perrot", "Daniel", "Lex", "Cousin", "Germain", "Breton", "Besson", "Langlois", "Remy", "Lef", "Pelletier", "Leveque", "Perrier", "Leblanc", "Barre", "Lebrun", "Marchal", "Weber", "Mallet", "Hamon", "Boulanger", "Jacob", "Monnier", "Michaud", "Rodriguez", "Guichard", "Gillet", "Etienne", "Grondin", "Poulain", "Tessier", "Chevallier", "Collin", "Chauvin", "Dava", "Bouchet", "Gay", "Lemaitre", "Benard", "Marechal", "Humbert", "Reynaud", "Antoine", "Hoarau", "Perret", "Barthelemy", "Cordier", "Pichon", "Lejeune", "Gilbert", "Lamy", "Delaunay", "Pasquier", "Carlier", "Laporte" };
    srand (time(NULL));
    std::cout << "ZombieHorde called" << std::endl;
    if (nb < 1)
    {
        this->hordes = NULL;
        return;
    }
    this->hordes = new Zombie[nb];
    for(int i = 0; i < nb; i++) {
        int random_number = std::rand(); 
        this->hordes[i].initZombie(name[((random_number / 54) + (random_number / 23)) % LEN(name)], "horde");
    }
}

ZombieHorde::ZombieHorde(int nb, std::string horde): nb_zombie(nb) {
    const std::string name[] = { "Martin", "Bernard", "Thomas", "Petit", "Robert", "Richard", "Durand", "Dubois", "Moreau", "Laurent", "Simon", "Michel", "Lefebvre", "Leroy", "Roux", "David", "Bertrand", "Morel", "Fournier", "Girard", "Bonnet", "Dupont", "Lambert", "Fontaine", "Rousseau", "Vincent", "Muller", "Lefevre", "Faure", "Andre", "Mercier", "Blanc", "Guerin", "Boyer", "Garnier", "Chevalier", "Francois", "Legrand", "Gauthier", "Garcia", "Perrin", "Robin", "Clement", "Morin", "Nicolas", "Henry", "Roussel", "Mathieu", "Gautier", "Masson", "Marchand", "Duval", "Denis", "Dumont", "Marie", "Lemaire", "Noel", "Meyer", "Dufour", "Meunier", "Brun", "Blanchard", "Giraud", "Joly", "Riviere", "Lucas", "Brunet", "Gaillard", "Barbier", "Arnaud", "Martinez", "Gerard", "Roche", "Renard", "Schmitt", "Roy", "Leroux", "Colin", "Vidal", "Caron", "Picard", "Roger", "Fabre", "Aubert", "Lemoine", "Renaud", "Dumas", "Lacroix", "Olivier", "Philippe", "Bourgeois", "Pierre", "Benoit", "Rey", "Leclerc", "Payet", "Rolland", "Leclercq", "Guillaume", "Lecomte", "Lopez", "Jean", "Dupuy", "Guillot", "Hubert", "Berger", "Carpentier", "Sanchez", "Dupuis", "Moulin", "Louis", "Deschamps", "Huet", "Vasseur", "Perez", "Boucher", "Fleury", "Royer", "Klein", "Jacquet", "Adam", "Paris", "Poirier", "Marty", "Aubry", "Guyot", "Carre", "Charles", "Renault", "Charpentier", "Menard", "Maillard", "Baron", "Bertin", "Bailly", "Herve", "Schneider", "Fernandez", "Lel", "Collet", "Leger", "Bouvier", "Julien", "Prevost", "Millet", "Perrot", "Daniel", "Lex", "Cousin", "Germain", "Breton", "Besson", "Langlois", "Remy", "Lef", "Pelletier", "Leveque", "Perrier", "Leblanc", "Barre", "Lebrun", "Marchal", "Weber", "Mallet", "Hamon", "Boulanger", "Jacob", "Monnier", "Michaud", "Rodriguez", "Guichard", "Gillet", "Etienne", "Grondin", "Poulain", "Tessier", "Chevallier", "Collin", "Chauvin", "Dava", "Bouchet", "Gay", "Lemaitre", "Benard", "Marechal", "Humbert", "Reynaud", "Antoine", "Hoarau", "Perret", "Barthelemy", "Cordier", "Pichon", "Lejeune", "Gilbert", "Lamy", "Delaunay", "Pasquier", "Carlier", "Laporte" };
    srand (time(NULL));
    std::cout << "ZombieHorde called" << std::endl;
    if (nb < 1)
    {
        this->hordes = NULL;
        return;
    }
    this->hordes = new Zombie[nb];
    for(int i = 0; i < nb; i++) {
        int random_number = std::rand(); 
        this->hordes[i].initZombie(name[((random_number / 54) + (random_number / 23)) % LEN(name)], horde);
    }
}

void ZombieHorde::announce(void) const {
    int nb = this->nb_zombie;
    for(int i = 0; i < nb; i++) {
        this->hordes[i].announce();
    }
}

ZombieHorde::~ZombieHorde(void) {
    if (this->hordes)
        delete [] this->hordes;
    std::cout << "ZombieHorde deleted and hordes too" << std::endl;
}
