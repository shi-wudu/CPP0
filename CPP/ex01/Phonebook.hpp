#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
    private:
    Contact contacts[8];
    int counter;
    int index;

    public:
    void addContact();
    void searchContacts();
    void displayContact(int index);
};

#endif