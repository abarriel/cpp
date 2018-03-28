// NinjaTrap
#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap {
public:
    NinjaTrap(void); // Canonical
    NinjaTrap(std::string name); 
    NinjaTrap(NinjaTrap const & src); // Canonical
    ~NinjaTrap(void); // Canonical
    NinjaTrap& operator=(NinjaTrap const & rhs); // Canonical
    void ninjaShoeBox(ClapTrap& ct);
    void ninjaShoeBox(FragTrap& ft);
    void ninjaShoeBox(ScavTrap& st);
    void ninjaShoeBox(NinjaTrap& nt);
};
// std::ostream& operator<<(std::ostream& o, NinjaTrap const &i);
#endif
// FR4G-TP <name> attacks <target> at range, causing <damage> points of damage !
