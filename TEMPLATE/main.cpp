#include "ClassContact.hpp"
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
    return (0);
}

// typedef void(Human::*action)(std::string const & target); 
// action members[] = {&Human::meleeAttack,...};
// CALL_MEMBER_FN(this, members[i])(target);