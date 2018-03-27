#ifndef CLASSCONTACT_HPP
#define CLASSCONTACT_HPP
#include <iostream>
#define LEN(cmds) sizeof(cmds) / sizeof(std::string)


class Contact {
    public:
        Contact(void);
        ~Contact(void);
        static void listContacts(void);
        void set_firstName(std::string const acc);
        void set_lastName(std::string const acc);
        void set_nickname(std::string const acc);
        void set_login(std::string const acc);
        void set_postalAddress(std::string const acc);
        void set_email(std::string const acc);
        void set_phoneNumber(std::string const acc);
        void set_date(std::string const acc);
        void set_favoriteMeal(std::string const acc);
        void set_underwearColor(std::string const acc);
        void set_darkestSecret(std::string const acc);
        static int  getIndex(void);
    private:
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
        static int _index;
        static Contact *_listContacts[7];
};
void board(void);
#endif