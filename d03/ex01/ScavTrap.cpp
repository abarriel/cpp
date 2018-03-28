// ScavTrap
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void): name("ScavTrap"), hitPoints(100), maxhitPoints(100), energyPoints(50), maxEnergyPoints(50),
    level(1), meleeAttackDamage(20), rangedAttackDamage(15), ArmorDamageReduction(3)  {
    std::cout << name << " -- initialize challenges and ready to fight!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): name(name), hitPoints(100), maxhitPoints(100), energyPoints(50), maxEnergyPoints(50),
    level(1), meleeAttackDamage(20), rangedAttackDamage(15), ArmorDamageReduction(3)  {
    std::cout << name << " -- initialize challenges and ready to fight!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs) {
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

bool ScavTrap::rangedAttack(std::string const & target) {
    // if (!this->checkEnergy("rangedAttack", target, this->rangedAttackDamage))
        // return false;
    std::cout << "SC4V-TP " << this->name << " attacks " << target << " at range, causing " << this->rangedAttackDamage <<  " points of damage ! " << std::endl;
    return true;
}

bool ScavTrap::meleeAttack(std::string const & target) {
    // if (!this->checkEnergy("meleeAttack", target, this->meleeAttackDamage))
    //     return false;
    std::cout << "SC4V-TP " << this->name << " attacks " << target << " at melee, causing " << this->meleeAttackDamage <<  " points of damage ! " << std::endl;
    return true;
}

void ScavTrap::namek(void) {
    std::cout << "SC4V-TP " << this->name << " challenges u to fight on namek (no shield, no melee attack because namek people are nice)" << std::endl;
}

void ScavTrap::earth(void) {
    std::cout << "SC4V-TP " << this->name << " challenges u to fight on earth (no heal)" << std::endl;
}
void ScavTrap::space(void) {
    std::cout << "SC4V-TP " << this->name << " challenges u to fight on space (hardcode mode)" << std::endl;
}

void ScavTrap::mars(void) {
    std::cout << "SC4V-TP " << this->name << " challenges u to fight on mars (every attacks is 2x damaging)" << std::endl;
}

void ScavTrap::moon(void) {
    std::cout << "SC4V-TP " << this->name << " challenges u to fight on moon (10 times longer to do an attack)" << std::endl;
}

bool ScavTrap::takeDamage(unsigned int amount) {
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
       std::cout << "SC4V-TP " << this->name << " is dying please let him go! " << std::endl;
    else
        std::cout << "SC4V-TP " << this->name << " took " << amount << " points of damage ! He is now at " << this->hitPoints << std::endl;
    return true;
}

bool ScavTrap::checkEnergy(std::string attack, std::string target, int energy) {
    this->energyPoints -= energy;
    if (this->energyPoints < 0)
    {
        this->energyPoints += energy;
        std::cout << this->name << " doesn't have enough energy to " << attack << " the target " << target << std::endl;
        return false;
    }
    return true;
}

void ScavTrap::challengeNewcomer(void) {
    typedef void(ScavTrap::*Actions)(void);
    Actions random[5] = { &ScavTrap::moon, &ScavTrap::mars, &ScavTrap::earth, &ScavTrap::space, &ScavTrap::namek }; 
    int random_number = std::rand(); 
    return (this->*random[((random_number / 54) + (random_number / 23)) % 5])();
}

bool ScavTrap::beRepaired(unsigned int amount) {
    int amou;

    amou = amount;

    std::cout << "SC4V-TP " << this->name << " is being repaired! +" << amou <<  " points " << std::endl;
    this->hitPoints += amou;
    if (this->hitPoints < 0)
        this->hitPoints = 0;
    if (this->hitPoints > this->maxhitPoints)
        this->hitPoints = this->maxhitPoints;
    return true;
}

ScavTrap::~ScavTrap(void) {
    std::cout << this->name << " I M LEAVING HAHA NO MORE CHALLENGES FOR U" << std::endl;
}

void ScavTrap::infos() {
    std::cout << "SC4V-TP: " << this->name << std::endl;
    std::cout << "  HP: " << this->hitPoints << std::endl;
    std::cout << "  Armor: " << this->ArmorDamageReduction << std::endl;
    std::cout << "  Energy: " << this->energyPoints << std::endl;
}
