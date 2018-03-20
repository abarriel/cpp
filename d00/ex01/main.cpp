#include "ClassContact.hpp"
#include <iostream>
#include <iomanip>

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
    Contact c;
    const std::string fields[] = { "first name", "last name", "nickname", "login", "postal address", "email address", "phone number", "birthday date", "favorite meal", "underwear color", "darkest secret"};
    std::string *contact_fields[] = { &c.firstName, &c.lastName, &c.nickname, &c.login, &c.postalAddress, &c.email, &c.phoneNumber, &c.date, &c.favoriteMeal, &c.underwearColor, &c.darkestSecret };

    for(int i = 0; i < LEN(fields); i++)
    {
        std::cout << "Enter your " << fields[i] << " : ";
        std::cin >> *contact_fields[i];
    }
    std::cout << "User added :)" << std::endl;
    Contact::getDetailsContact(0);
}

int main(void) {
    std::string cmd;

    while (1) {
        cmd = promptCmd();
        // std::cout << cmd << std::endl;
        if (!cmd.compare("ADD"))
            addContact();
        if (!cmd.compare("EXIT"))
            exit(0);
        if (Contact::getIndex() == 9)
            err(1, cmd, 1);
    }
}