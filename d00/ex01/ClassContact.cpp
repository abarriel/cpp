#include <iostream>
#include <iomanip>
#include "ClassContact.hpp"

int Contact::_index = 0;
Contact *Contact::_listContacts[7] = { NULL };

Contact::Contact(void) {
    // std::cout << "Constructor called" << std::endl;
    Contact::_listContacts[Contact::_index] = this;
    Contact::_index += 1;
}

Contact::~Contact(void) {
    std::cout << "Destructor called" << std::endl;
}

void pad(std::string s, int flag = 2){
    if (!flag)
        std::cout << "|";
    if (s.length() > 10)
        {
            s.resize(9);
            s += ".";
        }
    std::cout << std::setw(10) << s << "|";
    if (flag == 1)
        std::cout << std::endl << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
}
void Contact::set_firstName(std::string acc) {
    this->firstName = acc;
}
void Contact::set_lastName(std::string acc) {
    this->lastName = acc;
}
void Contact::set_nickname(std::string acc) {
    this->nickname = acc;
}
void Contact::set_login(std::string acc) {
    this->login = acc;
}
void Contact::set_postalAddress(std::string acc) {
    this->postalAddress = acc;
}
void Contact::set_email(std::string acc) {
    this->email = acc;
}
void Contact::set_phoneNumber(std::string acc) {
    this->phoneNumber = acc;
}
void Contact::set_date(std::string acc) {
    this->date = acc;
}
void Contact::set_favoriteMeal(std::string acc) {
    this->favoriteMeal = acc;
}
void Contact::set_underwearColor(std::string acc) {
    this->underwearColor = acc;
}
void Contact::set_darkestSecret(std::string acc) {
    this->darkestSecret = acc;
}

void Contact::listContacts(void) {
    int index;

    std::cout << ".___________________________________________." << std::endl;
    pad("index", 0);
    pad("first name");
    pad("last name");
    pad("nickname", 1);
    for (int i = 0; i < Contact::_index; i++) 
    {
        pad(std::to_string(i), 0);
        pad(Contact::_listContacts[i]->firstName);
        pad(Contact::_listContacts[i]->lastName);
        pad(Contact::_listContacts[i]->nickname, 1);
    }
    while (std::cout << "Enter the user's index to see full details: " 
        && ((!(std::cin >> index) && std::cin.fail()) || (index < 0 || index > (Contact::_index - 1))))
    {
        std::cout << "Wrong index, has to be an integer and be actually available" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    Contact::getDetailsContact(index);
}

void Contact::getDetailsContact(int index) {
    Contact *c;
    c = Contact::_listContacts[index];

    const std::string fields[] = { "first name", "last name", "nickname", "login", "postal address", "email address", "phone number", "birthday date", "favorite meal", "underwear color", "darkest secret"};
    const std::string *c_fields[] = { &c->firstName, &c->lastName, &c->nickname, &c->login, &c->postalAddress, &c->email, &c->phoneNumber, &c->date, &c->favoriteMeal, &c->underwearColor, &c->darkestSecret };
    std::cout << "Here are the full details:" << std::endl;
    for (int i = 0; i < LEN(fields); i++){
        std::cout << fields[i] << ": ";
        std::cout << *c_fields[i] << std::endl;
    }
}

int Contact::getIndex(void) {
    return Contact::_index;
}