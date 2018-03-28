#include <iostream>
#include "Human.hpp"
#define LEN(cmds) sizeof(cmds) / sizeof(std::string)
#define CALL_MEMBER_FN(object, ptrToMember)  ((object)->*(ptrToMember))

// Human::Human(void) {
//     std::cout << "Constructor called" << std::endl;
// }

// Human::~Human(void) {
//     std::cout << "Destructor called" << std::endl;
// }

void Human::meleeAttack(std::string const & target) {
    std::cout << "atttackkkkkkk with a meleeAttack " << target << std::endl;
}

void Human::rangedAttack(std::string const & target) {
    std::cout << "BOOM BIM BAMMMMMMMM I ATTACKED WITH A rangedAttack " << target << std::endl;
}

void Human::intimidatingShout(std::string const & target) {
    std::cout << "tssss...... intimidatingShout " << target << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target) {
    const std::string actions[] = { "meleeAttack", "rangedAttack", "intimidatingShout" };
    typedef void(Human::*action)(std::string const & target); // http://www.cs.technion.ac.il/users/yechiel/c++-faq/array-memfnptrs.html
    action members[] = {&Human::meleeAttack,&Human::rangedAttack,&Human::intimidatingShout };

    for(size_t i = 0; i < LEN(actions); i++)
    {
        if (actions[i] == action_name)
         {
            CALL_MEMBER_FN(this, members[i])(target);
            break;
         }
    }
}
