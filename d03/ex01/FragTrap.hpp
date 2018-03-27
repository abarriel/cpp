// FragTrap
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <iostream>

class FragTrap {
public:
    FragTrap(std::string name); // Canonical
    FragTrap(FragTrap const & src); // Canonical
    ~FragTrap(void); // Canonical
    FragTrap& operator=(FragTrap const & rhs); // Canonical
    bool rangedAttack(std::string const & target);
    bool meleeAttack(std::string const & target);
    bool takeDamage(unsigned int amount);
    bool beRepaired(unsigned int amount);
    void infos();
    bool vaulthunter_dot_exe(std::string const & target);
private:
    bool checkEnergy(std::string attack, std::string target, int energy);
    bool galickGun(std::string const & target);
    bool dragonFist(std::string const & target);
    bool finalFlash(std::string const & target);
    bool Genkidama(std::string const & target);
    bool Kamehameha(std::string const & target);
    std::string name;
    int hitPoints, maxhitPoints, energyPoints, maxEnergyPoints, 
        level, meleeAttackDamage, rangedAttackDamage, ArmorDamageReduction;
    
};
// std::ostream& operator<<(std::ostream& o, FragTrap const &i);
#endif
// FR4G-TP <name> attacks <target> at range, causing <damage> points of damage !
