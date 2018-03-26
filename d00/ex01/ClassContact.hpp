#ifndef CLASSCONTACT_HPP
#define CLASSCONTACT_HPP
#include <iostream>
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
        static void listContacts(void);
        static int  getIndex(void);
    private:
        static int _index;
        static Contact *_listContacts[7];
};
void board(void);
#endif