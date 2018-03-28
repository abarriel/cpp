// ClapTrap
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
public:
    ClapTrap(void); // Canonical
    ClapTrap(ClapTrap const & src); // Canonical
    ~ClapTrap(void); // Canonical
    ClapTrap& operator=(ClapTrap const & rhs); // Canonical
    bool rangedAttack(std::string const & target);
    bool meleeAttack(std::string const & target);
    bool takeDamage(unsigned int amount);
    bool beRepaired(unsigned int amount);
    void infos(void);
    std::string getName();
    void setName(std::string name);
protected:
    bool checkEnergy(std::string attack, std::string target, int energy);
    std::string name;
    std::string type;
    int hitPoints, maxhitPoints, energyPoints, maxEnergyPoints, 
        level, meleeAttackDamage, rangedAttackDamage, ArmorDamageReduction;
    
};
// std::ostream& operator<<(std::ostream& o, ClapTrap const &i);
#endif
// FR4G-TP <name> attacks <target> at range, causing <damage> points of damage !
