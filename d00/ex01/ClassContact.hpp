#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP
#include <iostream>
// #define FIELDS std::string fields[] = { "first name", "last name", "nickname", "login", "postal address", "email address", "phone number", "birthday date", "favorite meal", "underwear color", "darkest secret"};
// #define CMDS std::string cmds[] = { "ADD", "SEARCH", "EXIT" };
#define LEN(cmds) sizeof(cmds) / sizeof(std::string)

class Contact {
    public:
        Contact(void);
        ~Contact(void);
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string login;
        std::string postalAddress;
        std::string email;
        std::string phoneNumber;
        std::string date;
        std::string favoriteMeal;
        std::string underwearColor;
        std::string darkestSecret;    
        static void getDetailsContact(int index);
        static int  getIndex(void);
    private:
        static int _index;
        static Contact *_listContacts[8];
};

#endif