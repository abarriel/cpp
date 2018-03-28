// FragTrap
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
public:
    FragTrap(void); // Canonical
    FragTrap(std::string name); 
    FragTrap(FragTrap const & src); // Canonical
    ~FragTrap(void); // Canonical
    FragTrap& operator=(FragTrap const & rhs); // Canonical
    bool vaulthunter_dot_exe(std::string const & target);
    void extendedEnergy(int energy);
    bool rangedAttack(std::string const & target);
protected:
    bool galickGun(std::string const & target);
    bool dragonFist(std::string const & target);
    bool finalFlash(std::string const & target);
    bool Genkidama(std::string const & target);
    bool Kamehameha(std::string const & target);
    
};
// std::ostream& operator<<(std::ostream& o, FragTrap const &i);
#endif
// FR4G-TP <name> attacks <target> at range, causing <damage> points of damage !
