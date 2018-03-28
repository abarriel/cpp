// SuperTrap
#include "SuperTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap(void) {
    this->type = "SuperTrap";
    this->name = "SuperTrap";
    // this->hitPoints = FragTrap::hitPoints;
    // this->maxhitPoints = FragTrap::maxhitPoints;
    // this->energyPoints = NinjaTrap::energyPoints;
    // this->maxEnergyPoints = NinjaTrap::maxEnergyPoints;
    // this->level = 1;
    // this->meleeAttackDamage = NinjaTrap::meleeAttackDamage;
    // this->rangedAttackDamage = NinjaTrap::rangedAttackDamage;
    // this->ArmorDamageReduction = FragTrap::ArmorDamageReduction;
    this->hitPoints = 100;
    this->maxhitPoints = 100;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->level = 1;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->ArmorDamageReduction = 5;
    std::cout << this->type << " " << this->name << " -- startup super soldier" << std::endl;
}

SuperTrap::SuperTrap(std::string name) {
    this->type = "SuperTrap";
    this->name = name;
    // this->hitPoints = FragTrap::hitPoints; // 100
    // this->maxhitPoints = FragTrap::maxhitPoints;
    // this->energyPoints = NinjaTrap::energyPoints;
    // this->maxEnergyPoints = NinjaTrap::maxEnergyPoints;
    // this->level = 1;
    // this->meleeAttackDamage = NinjaTrap::meleeAttackDamage;
    // this->rangedAttackDamage = NinjaTrap::rangedAttackDamage;
    // this->ArmorDamageReduction = FragTrap::ArmorDamageReduction;
    this->hitPoints = 100;
    this->maxhitPoints = 100;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->level = 1;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->ArmorDamageReduction = 5;
    std::cout << this->type << " " << this->name << " -- startup super soldier" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

bool SuperTrap::rangedAttack(std::string const & target) {
    return FragTrap::rangedAttack(target);
}

bool SuperTrap::meleeAttack(std::string const & target) {
    return NinjaTrap::meleeAttack(target);
}

SuperTrap& SuperTrap::operator=(SuperTrap const & rhs) {
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

SuperTrap::~SuperTrap(void) {
    std::cout << this->name << " super class dead! " << std::endl;
}

// void SuperTrap::infos(void) {
//     std::cout << this->type << ": " << this->name << std::endl;
//     std::cout << "  HP: " << this->hitPoints << std::endl;
//     std::cout << "  Armor: " << this->ArmorDamageReduction << std::endl;
//     std::cout << "  Energy: " << this->energyPoints << std::endl;
//     std::cout << "  MaxEnergy: " << this->maxEnergyPoints << std::endl;
//     std::cout << "  armorDamageReduction: " << this->ArmorDamageReduction << std::endl;
//     std::cout << "  meleeattackDamage: " << this->meleeAttackDamage << std::endl;
//     std::cout << "  rangeattackDamage: " << this->rangedAttackDamage << std::endl;
// }
