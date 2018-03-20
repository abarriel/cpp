#include <iostream>
#include <iomanip>
#include "ClassContact.hpp"

int Contact::_index = 0;
Contact *Contact::_listContacts[8] = { NULL };

Contact::Contact(void) {
    // std::cout << "Constructor called" << std::endl;
    Contact::_listContacts[Contact::_index] = this;
    Contact::_index += 1;
}

Contact::~Contact(void) {
    // std::cout << "Destructor called" << std::endl;
}

void Contact::listContacts(void) {
// std::setw(10)
// index,first name,last nameandnickname
    std::cout << "index | first name | last name | nickname" << std::endl;
}

void Contact::getDetailsContact(int index) {
    Contact *c;
    c = Contact::_listContacts[index];

    const std::string fields[] = { "first name", "last name", "nickname", "login", "postal address", "email address", "phone number", "birthday date", "favorite meal", "underwear color", "darkest secret"};
    const std::string *c_fields[] = { &c->firstName, &c->lastName, &c->nickname, &c->login, &c->postalAddress, &c->email, &c->phoneNumber, &c->date, &c->favoriteMeal, &c->underwearColor, &c->darkestSecret };
    
    for (int i = 0; i < LEN(fields); i++){
        std::cout << fields[i] << ": ";
        std::cout << *c_fields[i] << std::endl;
    }
}

int Contact::getIndex(void) {
    return Contact::_index;
}