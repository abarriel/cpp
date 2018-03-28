// SuperTrap
#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

// class SuperTrap: public FragTrap, public NinjaTrap {
class SuperTrap: public NinjaTrap, public FragTrap {
public:
    SuperTrap(void); // Canonical
    SuperTrap(std::string name); 
    SuperTrap(SuperTrap const & src); // Canonical
    ~SuperTrap(void); // Canonical
    SuperTrap& operator=(SuperTrap const & rhs); // Canonical
    bool rangedAttack(std::string const & target);
    bool meleeAttack(std::string const & target);
    // void infos(void); // override becauseee shit
private:
    bool galickGun(std::string const & target);
    bool dragonFist(std::string const & target);
    bool finalFlash(std::string const & target);
    bool Genkidama(std::string const & target);
    bool Kamehameha(std::string const & target);
};
// std::ostream& operator<<(std::ostream& o, SuperTrap const &i);
#endif
// FR4G-TP <name> attacks <target> at range, causing <damage> points of damage !
