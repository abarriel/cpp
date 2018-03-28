// ScavTrap
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
    ScavTrap(void); // Canonical
    ScavTrap(std::string name); // Canonical
    ScavTrap(ScavTrap const & src); // Canonical
    ~ScavTrap(void); // Canonical
    ScavTrap& operator=(ScavTrap const & rhs); // Canonical
    void challengeNewcomer();
private:
    void namek(void);
    void space(void);
    void earth(void);
    void mars(void);
    void moon(void);
};
// std::ostream& operator<<(std::ostream& o, ScavTrap const &i);
#endif
// FR4G-TP <name> attacks <target> at range, causing <damage> points of damage !
