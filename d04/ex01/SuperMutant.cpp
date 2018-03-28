#include "SuperMutant.hpp"

/* Constructors */
SuperMutant::SuperMutant(void): Enemy(170, "Super Mutant")  {
	std::cout << "(SuperMutant) Gaaah. Me want smash heads !" << std::endl;
    return ;
}

SuperMutant::SuperMutant(SuperMutant const & src) {
	std::cout << "(SuperMutant) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* override */
SuperMutant& SuperMutant::operator=(SuperMutant const & rhs) {
	std::cout << "(SuperMutant) assignation operator called";
	this->type = rhs.type;
	this->hp = rhs.hp;
	return *this;
}

void SuperMutant::takeDamage(int dam) {
	if ((dam - 3) < 0)
		return ;
	this->hp -= (dam - 3);
	if (this->hp < 0)
		this->hp = 0;
}

std::ostream& operator<<(std::ostream& out, SuperMutant const &i) {
	out << "(SuperMutant) Hello my tape is " << i.getType() << " !"<< std::endl;
	return out;
}

/* Destructors */
SuperMutant::~SuperMutant(void) {
	std::cout << "(SuperMutant) Aaargh ..." << std::endl;
    return ;
}
