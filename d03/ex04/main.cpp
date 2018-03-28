// typedef void(Human::*action)(std::string const & target); 
// action members[] = {&Human::meleeAttack,...};
// CALL_MEMBER_FN(this, members[i])(target);
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

#include <iostream>
#define LEN(cmds) sizeof(cmds) / sizeof(std::string)
#define CALL_MEMBER_FN(object,ptrToMember)  ((object)->*(ptrToMember))

void    err(int i, std::string str, int ext = 0) {
    std::string err[] = { "Invalid Command", "Only 8 contacts can be stored" };
    std::cout << err[i] << ": " << str << std::endl;
    if (ext)
        exit(0);
    return;
}

int     main(void) {

    SuperTrap super;
    FragTrap wolverine("wolverine");
    ScavTrap drquine("drquine");
    NinjaTrap ninja("Naruto");
    ClapTrap d;

    super.infos();
    super.rangedAttack("Dr Strange");
    super.meleeAttack("Dr Strange and Freewer");
    super.ninjaShoeBox(ninja);
    super.ninjaShoeBox(d);
    super.ninjaShoeBox(wolverine);
    super.ninjaShoeBox(drquine);
    super.vaulthunter_dot_exe("Boo");
    super.vaulthunter_dot_exe("Boo");
    super.vaulthunter_dot_exe("Boo");
    super.infos();
    super.vaulthunter_dot_exe("Boo");
    super.vaulthunter_dot_exe("Boo");
    super.takeDamage(50);
    super.beRepaired(60);  
    super.infos();
    // ninja.infos();
    // ninja.infos();
    // drquine.infos();
    //
    // wolverine.rangedAttack("Dr Strange");
    // drquine.infos();
    // drquine.rangedAttack("Dr Strange");
    // wolverine.meleeAttack("Dr Strange and Freewer");
    // drquine.meleeAttack("Dr strange and Freezer");
    // wolverine.takeDamage(0);
    // wolverine.takeDamage(1001000000);
    // wolverine.takeDamage(2);
    // wolverine.beRepaired(2);
    // wolverine.infos();
    // FragTrap b;
    // b = wolverine;
    // b.infos();
    // drquine.takeDamage(2);
    // wolverine.takeDamage(2);
    // drquine.takeDamage(2);
    // wolverine.infos();
    // drquine.infos();
    // wolverine.beRepaired(-2);
    // drquine.beRepaired(4);
    // wolverine.beRepaired(5552);
    // wolverine.infos();
    // wolverine.takeDamage(2);
    // drquine.challengeNewcomer();
    // drquine.challengeNewcomer();
    // drquine.challengeNewcomer();
    // drquine.challengeNewcomer();
    // drquine.challengeNewcomer();
    // wolverine.vaulthunter_dot_exe("Boo");
    // wolverine.vaulthunter_dot_exe("Boo");
    // drquine.challengeNewcomer();
    // wolverine.vaulthunter_dot_exe("Boo");
    // wolverine.infos();
    // wolverine.vaulthunter_dot_exe("Boo");
    // wolverine.vaulthunter_dot_exe("Boo");
    // wolverine.takeDamage(2);
    // wolverine.takeDamage(2);
    // wolverine.rangedAttack("Dr Strange");
    // drquine.challengeNewcomer();
    // wolverine.meleeAttack("Dr Strange and Freewer");
    // wolverine.infos();
    return (0);
}
