// NinjaTrap
#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(void) {
    this->type = "NinjaTrap";
    this->name = "NinjaTrap";
    this->hitPoints = 60;
    this->maxhitPoints = 60;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->level = 1;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->ArmorDamageReduction = 0;
    std::cout << this->type << " " << this->name << " -- start bootup sequence" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) {
    this->type = "NinjaTrap";
    this->name = name;
    this->hitPoints = 60;
    this->maxhitPoints = 60;
    this->energyPoints = 120;
    this->maxEnergyPoints = 120;
    this->level = 1;
    this->meleeAttackDamage = 60;
    this->rangedAttackDamage = 5;
    this->ArmorDamageReduction = 0;
    std::cout << this->type << " " << this->name << " -- start bootup sequence" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

NinjaTrap& NinjaTrap::operator=(NinjaTrap const & rhs) {
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

NinjaTrap::~NinjaTrap(void) {
    std::cout << this->name << " ninja neverrrr died (oh well maybe)" << std::endl;
}

bool NinjaTrap::meleeAttack(std::string const & target) {
        std::cout << this->type << " " << this->name << " attacks " << target
    << "with a meleeattack(ninja) causing " << this->meleeAttackDamage <<  " points of damage ! " << std::endl;
    return (true);
}

void NinjaTrap::ninjaShoeBox(ClapTrap& ct) {
    std::cout << this->type << " " << this->name << " found the usine!!" << std::endl;
}

void NinjaTrap::ninjaShoeBox(FragTrap& ft) {
    std::cout << this->type << " " << this->name << " like fragtrap a looooooot, that's why he extends if max energy points" << std::endl;
    ft.extendedEnergy(100);
}

void NinjaTrap::ninjaShoeBox(ScavTrap& st) {
    std::cout << this->type << " " << this->name << " doens't like the scav trap robot under the name of  " << st.getName() << " that's why the ninja change his name !! " << std::endl;
    st.setName("NinjaSoldiers"); 
}

void NinjaTrap::ninjaShoeBox(NinjaTrap& nt) {
    nt.beRepaired(50);
    std::cout << this->type << " " << this->name << " stole a steak for his ninja prefered (+50 live) " << nt.name << std::endl;
}
