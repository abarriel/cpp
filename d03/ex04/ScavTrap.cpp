// ScavTrap
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) {
    this->type = "SC4V-TP";
    this->name = "SC4V-TP";
    this->hitPoints = 100;
    this->maxhitPoints = 100;
    this->energyPoints = 50;
    this->maxEnergyPoints = 50;
    this->level = 1;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->ArmorDamageReduction = 3;
    std::cout << this->type << " " << name << " -- start bootup sequence" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    this->type = "SC4V-TP";
    this->name = "SC4V-TP";
    this->hitPoints = 100;
    this->maxhitPoints = 100;
    this->energyPoints = 50;
    this->maxEnergyPoints = 50;
    this->level = 1;
    this->meleeAttackDamage = 20;
    this->rangedAttackDamage = 15;
    this->ArmorDamageReduction = 3;
    std::cout << this->type << " " << name << " -- start bootup sequence" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs) {
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

void ScavTrap::challengeNewcomer(void) {
    typedef void(ScavTrap::*Actions)(void);
    Actions random[5] = { &ScavTrap::moon, &ScavTrap::mars, &ScavTrap::earth, &ScavTrap::space, &ScavTrap::namek }; 
    int random_number = std::rand(); 
    return (this->*random[((random_number / 54) + (random_number / 23)) % 5])();
}

ScavTrap::~ScavTrap(void) {
    std::cout << this->name << " I M LEAVING HAHA NO MORE CHALLENGES FOR U" << std::endl;
}
