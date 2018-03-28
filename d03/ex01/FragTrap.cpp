// FragTrap
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void): name("FragTrap"), hitPoints(100), maxhitPoints(100), energyPoints(100), maxEnergyPoints(100),
    level(1), meleeAttackDamage(30), rangedAttackDamage(20), ArmorDamageReduction(5)  {
    std::cout << this->name << " -- start bootup sequence" << std::endl;
}

FragTrap::FragTrap(std::string name): name(name), hitPoints(100), maxhitPoints(100), energyPoints(100), maxEnergyPoints(100),
    level(1), meleeAttackDamage(30), rangedAttackDamage(20), ArmorDamageReduction(5)  {
    std::cout << name << " -- start bootup sequence" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

FragTrap& FragTrap::operator=(FragTrap const & rhs) {
    std::cout << "Assignation operator called" << std::endl;
    this->name = rhs.name;
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

bool FragTrap::rangedAttack(std::string const & target) {
    // if (!this->checkEnergy("rangedAttack", target, this->rangedAttackDamage))
        // return false;
    std::cout << "FR4G-TP " << this->name << " attacks " << target << " at range, causing " << this->rangedAttackDamage <<  " points of damage ! " << std::endl;
    return true;
}

bool FragTrap::meleeAttack(std::string const & target) {
    // if (!this->checkEnergy("meleeAttack", target, this->meleeAttackDamage))
    //     return false;
    std::cout << "FR4G-TP " << this->name << " attacks " << target << " at melee, causing " << this->meleeAttackDamage <<  " points of damage ! " << std::endl;
    return true;
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

bool FragTrap::takeDamage(unsigned int amount) {
    int tmp;

    tmp = this->ArmorDamageReduction;
    this->ArmorDamageReduction -= amount;
    if (this->ArmorDamageReduction < 0)
        this->ArmorDamageReduction = 0;
    if (amount < tmp)
        amount = 0;
    else
        amount -= tmp;
    this->hitPoints -= amount;
    if (this->hitPoints < 0)
        this->hitPoints = 0;
    if (this->hitPoints == 0)
       std::cout << "FR4G-TP " << this->name << " is dying please let him go! " << std::endl;
    else
        std::cout << "FR4G-TP " << this->name << " took " << amount << " points of damage ! He is now at " << this->hitPoints << std::endl;
    return true;
}

bool FragTrap::checkEnergy(std::string attack, std::string target, int energy) {
    this->energyPoints -= energy;
    if (this->energyPoints < 0)
    {
        this->energyPoints += energy;
        std::cout << this->name << " doesn't have enough energy to " << attack << " the target " << target << std::endl;
        return false;
    }
    return true;
}

bool FragTrap::vaulthunter_dot_exe(std::string const & target) {
    typedef bool(FragTrap::*Actions)(std::string const & target);
    Actions random[5] = { &FragTrap::finalFlash, &FragTrap::Genkidama, &FragTrap::dragonFist, &FragTrap::Kamehameha, &FragTrap::galickGun }; 
    int random_number = std::rand(); 
    return (this->*random[((random_number / 54) + (random_number / 23)) % 5])(target);
}

bool FragTrap::beRepaired(unsigned int amount) {
    int amou;

    amou = amount;

    std::cout << "FR4G-TP " << this->name << " is being repaired! +" << amou <<  " points " << std::endl;
    this->hitPoints += amou;
    if (this->hitPoints < 0)
        this->hitPoints = 0;
    if (this->hitPoints > this->maxhitPoints)
        this->hitPoints = this->maxhitPoints;
    return true;
}

FragTrap::~FragTrap(void) {
    std::cout << this->name << " I'M DEAD I'M DEAD OHMYGOD I'M DEAD! " << std::endl;
}

void FragTrap::infos() {
    std::cout << "FR4G-TP: " << this->name << std::endl;
    std::cout << "  HP: " << this->hitPoints << std::endl;
    std::cout << "  Armor: " << this->ArmorDamageReduction << std::endl;
    std::cout << "  Energy: " << this->energyPoints << std::endl;
}
