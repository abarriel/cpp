#include "AsteroKreog.hpp"

/* Constructors */
AsteroKreog::AsteroKreog(void): name("AsteroKreog") {
	std::cout << "(AsteroKreog) default constructor called" << std::endl;
    return ;
}

/* function members */
std::string AsteroKreog::getName() const {
	return this->name;
};

std::string AsteroKreog::beMined() const {
	return 0;
};

/* override */
AsteroKreog& AsteroKreog::operator=(AsteroKreog const & rhs) {
	std::cout << "(AsteroKreog) assignation operator called";
	/* add logic */
	return *this;
}

std::ostream& operator<<(std::ostream& out, AsteroKreog const &i) {
	out << "(AsteroKreog) WARNING ! ADD A LOGIC <<" << std::endl;
	return out;
}

AsteroKreog::AsteroKreog(AsteroKreog const & src) {
	std::cout << "(AsteroKreog) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
AsteroKreog::~AsteroKreog(void) {
	std::cout << "(AsteroKreog) destructor AsteroKreog called" << std::endl;
    return ;
}
