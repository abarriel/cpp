// typedef void(Human::*action)(std::string const & target); 
// action members[] = {&Human::meleeAttack,...};
// CALL_MEMBER_FN(this, members[i])(target);
#include "FragTrap.hpp"
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

    wolverine->infos();
    wolverine->rangedAttack("Dr Strange");
    wolverine->meleeAttack("Dr Strange and Freewer");
    wolverine->takeDamage(0);
    wolverine->takeDamage(1001000000);
    wolverine->takeDamage(2);
    wolverine->takeDamage(2);
    wolverine->infos();
    wolverine->beRepaired(-2);
    wolverine->beRepaired(2);
    wolverine->beRepaired(5552);
    wolverine->infos();
    wolverine->takeDamage(2);
    wolverine->vaulthunter_dot_exe("Boo");
    wolverine->vaulthunter_dot_exe("Boo");
    wolverine->vaulthunter_dot_exe("Boo");
    wolverine->infos();
    wolverine->vaulthunter_dot_exe("Boo");
    wolverine->vaulthunter_dot_exe("Boo");
    wolverine->takeDamage(2);
    wolverine->takeDamage(2);
    wolverine->rangedAttack("Dr Strange");
    wolverine->meleeAttack("Dr Strange and Freewer");
    wolverine->infos();
    delete wolverine;
    return (0);
}
