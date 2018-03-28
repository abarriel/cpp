// ClapTrap
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): name("ClapTrap"), type("ClapTrap"), hitPoints(100), maxhitPoints(100), energyPoints(100), maxEnergyPoints(100),
    level(1), meleeAttackDamage(30), rangedAttackDamage(20), ArmorDamageReduction(5)  {
    std::cout << this->type << " " << this->name << " -- start bootup sequence" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs) {
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

void ClapTrap::messageAttack(std::string const target, std::string const attack, int const damage) const {
    std::cout << this->type << " " << this->name << " attacks " << target
    << "with a "  << attack << " attack causing " << damage <<  " points of damage ! " << std::endl;
}

bool ClapTrap::rangedAttack(std::string const & target) {
    // if (!this->checkEnergy("meleeAttack", target, this->meleeAttackDamage))
    //     return false;
    this->messageAttack(target, "range", this->rangedAttackDamage);
    return true;
}

bool ClapTrap::meleeAttack(std::string const & target) {
    // if (!this->checkEnergy("meleeAttack", target, this->meleeAttackDamage))
    //     return false;
    this->messageAttack(target, "melee", this->rangedAttackDamage);
    return true;
}

bool ClapTrap::takeDamage(unsigned int amount) {
    int tmp;

    tmp = this->ArmorDamageReduction;
    this->ArmorDamageReduction -= amount;
    if (this->ArmorDamageReduction < 0)
        this->ArmorDamageReduction = 0;
    if ((int)amount < tmp)
        amount = 0;
    else
        amount -= tmp;
    this->hitPoints -= amount;
    if (this->hitPoints < 0)
        this->hitPoints = 0;
    if (this->hitPoints == 0)
       std::cout << this->name << " is dying please let him go! " << std::endl;
    else
        std::cout << this->name << " took " << amount << " points of damage ! He is now at " << this->hitPoints << std::endl;
    return true;
}

bool ClapTrap::checkEnergy(std::string attack, std::string target, int energy) {
    this->energyPoints -= energy;
    if (this->energyPoints < 0)
    {
        this->energyPoints += energy;
        std::cout << this->name << " doesn't have enough energy to " << attack << " the target " << target << std::endl;
        return false;
    }
    return true;
}

bool ClapTrap::beRepaired(unsigned int amount) {
    int amou;

    amou = amount;

    std::cout << this->name << " is being repaired! +" << amou <<  " points " << std::endl;
    this->hitPoints += amou;
    if (this->hitPoints < 0)
        this->hitPoints = 0;
    if (this->hitPoints > this->maxhitPoints)
        this->hitPoints = this->maxhitPoints;
    return true;
}

ClapTrap::~ClapTrap(void) {
    std::cout << this->type << " " << this->name << " is dead" << std::endl;
}

std::string ClapTrap::getName(void) {
    return this->name;
}

void ClapTrap::setName(std::string name) {
    this->name = name;
}

void ClapTrap::infos(void) {
    std::cout << this->type << ": " << this->name << std::endl;
    std::cout << "  HP: " << this->hitPoints << std::endl;
    std::cout << "  Armor: " << this->ArmorDamageReduction << std::endl;
    std::cout << "  Energy: " << this->energyPoints << std::endl;
    std::cout << "  MaxEnergy: " << this->maxEnergyPoints << std::endl;
}
