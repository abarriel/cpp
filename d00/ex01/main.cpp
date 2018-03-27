#include "ClassContact.hpp"
#include <iostream>

#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

void    err(int i, std::string str, int ext = 0) {
    std::string err[] = { "Invalid Command", "Only 8 contacts can be stored" };
    std::cout << err[i] << ": " << str << std::endl;
    if (ext)
        exit(0);
    return;
}

std::string promptCmd() {
    int i;
    const std::string cmds[] = { "ADD", "SEARCH", "EXIT" };
    std::string cmd;    

    while (1) {
        std::cout << "Enter your command (ADD | SEARCH | EXIT): ";
        std::cin >> cmd;
        // std::getline(std::cin, cmd);
        for (i = 0; i < LEN(cmds); i++)
            if (!cmd.compare(cmds[i]))
                break;
        if (i == LEN(cmds))
            err(0, cmd);
        else
            break;
    }
    return cmd;
}

void addContact() {
    if (Contact::getIndex() == 8)
        err(1, "ADD", 1);
    Contact c;
    std::string tmp;
    const std::string fields[] = { "first name", "last name", "nickname", "login", "postal address", "email address", "phone number", "birthday date", "favorite meal", "underwear color", "darkest secret"};
    typedef void(Contact::*setterArray)(std::string const target); 
    setterArray setter[] = { &Contact::set_firstName, &Contact::set_lastName, &Contact::set_nickname, &Contact::set_login, &Contact::set_postalAddress, &Contact::set_email, &Contact::set_phoneNumber, &Contact::set_date, &Contact::set_favoriteMeal, &Contact::set_underwearColor, &Contact::set_darkestSecret };

    for(int i = 0; i < LEN(fields); i++)
    {
        std::cout << "Enter your " << fields[i] << " : ";
        std::cin >> tmp;
        CALL_MEMBER_FN(c, setter[i])(tmp);
    }
    std::cout << "User added :)" << std::endl;
    board();
    // Contact::getDetailsContact(0);
}

void board(void) {
    std::string cmd;

    while (1) {
        cmd = promptCmd();
        if (!cmd.compare("ADD"))
            addContact();
        if (!cmd.compare("SEARCH"))
            Contact::listContacts();
        if (!cmd.compare("EXIT"))
            exit(0);
    }
}

int main(void) {
    board(); // little trick ;)
}