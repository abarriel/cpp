// typedef void(Human::*action)(std::string const & target); 
// action members[] = {&Human::meleeAttack,...};
// CALL_MEMBER_FN(this, members[i])(target);
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
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
    FragTrap *wolverine = new FragTrap("wolverine");
    ScavTrap *drquine = new ScavTrap("drquine");

    wolverine->infos();
    drquine->infos();
    wolverine->rangedAttack("Dr Strange");
    drquine->rangedAttack("Dr Strange");
    wolverine->meleeAttack("Dr Strange and Freewer");
    drquine->meleeAttack("Dr strange and Freezer");
    wolverine->takeDamage(0);
    wolverine->takeDamage(1001000000);
    wolverine->takeDamage(2);
    drquine->takeDamage(2);
    wolverine->takeDamage(2);
    drquine->takeDamage(2);
    wolverine->infos();
    drquine->infos();
    wolverine->beRepaired(-2);
    wolverine->beRepaired(2);
    drquine->beRepaired(4);
    wolverine->beRepaired(5552);
    wolverine->infos();
    wolverine->takeDamage(-2);
    drquine->challengeNewcomer();
    drquine->challengeNewcomer();
    drquine->challengeNewcomer();
    drquine->challengeNewcomer();
    drquine->challengeNewcomer();
    wolverine->vaulthunter_dot_exe("Boo");
    wolverine->vaulthunter_dot_exe("Boo");
    drquine->challengeNewcomer();
    wolverine->vaulthunter_dot_exe("Boo");
    wolverine->infos();
    wolverine->vaulthunter_dot_exe("Boo");
    wolverine->vaulthunter_dot_exe("Boo");
    wolverine->takeDamage(2);
    wolverine->takeDamage(2);
    wolverine->rangedAttack("Dr Strange");
    drquine->challengeNewcomer();
    wolverine->meleeAttack("Dr Strange and Freewer");
    wolverine->infos();
    delete wolverine;
    delete drquine;
    return (0);
}
