// FragTrap
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) {
    this->type = "FrapTrap";
    this->name = "FrapTrap";
    this->hitPoints = 100;
    this->maxhitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->level = 1;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->ArmorDamageReduction = 5;
    std::cout << this->type << " " << this->name << " -- start bootup sequence" << std::endl;
}

FragTrap::FragTrap(std::string name) {
    this->type = "FrapTrap";
    this->name = name;
    this->hitPoints = 100;
    this->maxhitPoints = 100;
    this->energyPoints = 100;
    this->maxEnergyPoints = 100;
    this->level = 1;
    this->meleeAttackDamage = 30;
    this->rangedAttackDamage = 20;
    this->ArmorDamageReduction = 5;
    std::cout << this->type << " " << this->name << " -- start bootup sequence" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

FragTrap& FragTrap::operator=(FragTrap const & rhs) {
    std::cout << "Assignation operator called" << std::endl;
    this->name = rhs.name;
    this->type = rhs.type;
    this->hitPoints = rhs.hitPoints;
    this->maxhitPoints = rhs.maxhitPoints;
    this->energyPoints = rhs.energyPoints;
    this->maxEnergyPoints = rhs.maxEnergyPoints;
    this->level = rhs.level;
    this->meleeAttackDamage = rhs.meleeAttackDamage;
    this->rangedAttackDamage = rhs.rangedAttackDamage;
    this->ArmorDamageReduction = rhs.ArmorDamageReduction;
    return *this;
}

bool FragTrap::galickGun(std::string const & target) {
    if (!this->checkEnergy("galickGun", target, 25))
        return false;
    std::cout << "FR4G-TP " << this->name << " attacks " << target << " with a galick Gun , causing " << 21 <<  " points of damage ! " << std::endl;
    return true;
}

bool FragTrap::dragonFist(std::string const & target) {
    if (!this->checkEnergy("dragonFist", target, 25))
        return false;
    std::cout << "FR4G-TP " << this->name << " attacks " << target << " with a dragon fist, causing " << 70 <<  " points of damage ! " << std::endl;
    return true;
}

bool FragTrap::finalFlash(std::string const & target) {
    if (!this->checkEnergy("finalFlash", target, 25))
        return false;
    std::cout << "FR4G-TP " << this->name << " attacks " << target << " with a final flash, causing " << 15 <<  " points of damage ! " << std::endl;
    return true;
}

bool FragTrap::Genkidama(std::string const & target) {
    if (!this->checkEnergy("Genkidama", target, 25))
        return false;
    std::cout << "FR4G-TP " << this->name << " attacks " << target << " with a genekidama, causing " << 50 <<  " points of damage ! " << std::endl;
    return true;
}

bool FragTrap::Kamehameha(std::string const & target) {
    if (!this->checkEnergy("Kamehameha", target, 25))
        return false;
    std::cout << "FR4G-TP " << this->name << " attacks " << target << " with a kamehameha, causing " << 20 <<  " points of damage ! " << std::endl;
    return true;
}

bool FragTrap::vaulthunter_dot_exe(std::string const & target) {
    typedef bool(FragTrap::*Actions)(std::string const & target);
    Actions random[5] = { &FragTrap::finalFlash, &FragTrap::Genkidama, &FragTrap::dragonFist, &FragTrap::Kamehameha, &FragTrap::galickGun }; 
    int random_number = std::rand(); 
    return (this->*random[((random_number / 54) + (random_number / 23)) % 5])(target);
}

FragTrap::~FragTrap(void) {
    std::cout << this->name << " I'M DEAD I'M DEAD OHMYGOD I'M DEAD! " << std::endl;
}
