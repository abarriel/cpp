// ScavTrap
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>

class ScavTrap {
public:
    ScavTrap(void); // Canonical
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const & src); // Canonical
    ~ScavTrap(void); // Canonical
    ScavTrap& operator=(ScavTrap const & rhs); // Canonical
    bool rangedAttack(std::string const & target);
    bool meleeAttack(std::string const & target);
    bool takeDamage(unsigned int amount);
    bool beRepaired(unsigned int amount);
    void infos();
    void challengeNewcomer();
private:
    bool checkEnergy(std::string attack, std::string target, int energy);
    void namek(void);
    void space(void);
    void earth(void);
    void mars(void);
    void moon(void);
    std::string name;
    int hitPoints, maxhitPoints, energyPoints, maxEnergyPoints, 
        level, meleeAttackDamage, rangedAttackDamage, ArmorDamageReduction;
    
};
// std::ostream& operator<<(std::ostream& o, ScavTrap const &i);
#endif
// FR4G-TP <name> attacks <target> at range, causing <damage> points of damage !
