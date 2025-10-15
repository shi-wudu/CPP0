#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    public:
    void setDetails(std::string firstName, std::string lastName, std::string nickname,
                    std::string phoneNumber, std::string darkestSecret);
    void displayDetails();
    bool isEmpty();
};

#endif