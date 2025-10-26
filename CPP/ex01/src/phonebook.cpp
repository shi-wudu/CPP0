/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleandr <maleandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:33:26 by maleandr          #+#    #+#             */
/*   Updated: 2025/10/26 18:28:10 by maleandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"
#include <iostream>
#include <iomanip>
Phonebook::Phonebook(void)
{
    this->listSize = 0;
    this->overflowIndex = 0;
}
void Phonebook::addContact(std::string firstName, std::string lastName, \
    std::string nickname, std::string phoneNumber, std::string darkestSecret)
{ 
    int index;

    if (listSize < 8)
        index = listSize;
    else
        index = overflowIndex;

    if (!contacts[index].addDetails(firstName, lastName, nickname, phoneNumber, darkestSecret))
    {
        std::cout << "New contact added!" << std::endl;
        if (listSize < 8)
            listSize++;
        else
            overflowIndex = (overflowIndex + 1) % 8;
    }
    else
        std::cout << "You either forgot a bit of information or used a cursed character... Contact wasn't added." << std::endl;
    return;
}

void Phonebook::searchContact(int index)
{
    if (index < 0 || index >=listSize)
    {
        std::cout << "Please insert an index within the options displayed." << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

static std::string formatString(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

static void printHeader(void)
{
    std::cout << std::right << std::setw(10) << "index" << "|";
    std::cout << std::right << std::setw(10) << "first name" << "|";
    std::cout << std::right << std::setw(10) << "last name" << "|";
    std::cout << std::right << std::setw(10) << "nickname" << std::endl;
}

void Phonebook::displayContacts(void)
{
    printHeader();
    for (int i = 0; i < listSize; i++)
    {
        std::cout << std::right << std::setw(10) << i + 1 << "|";
        std::cout << std::right << std::setw(10) << formatString(contacts[i].getFirstName()) << "|";
        std::cout << std::right << std::setw(10) << formatString(contacts[i].getLastName()) << "|";
        std::cout << std::right << std::setw(10) << formatString(contacts[i].getNickname()) << std::endl;
    }
}

int Phonebook::getListSize(void) const
{
    return listSize;
}