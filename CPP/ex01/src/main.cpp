/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleandr <maleandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:41:13 by maleandr          #+#    #+#             */
/*   Updated: 2025/10/26 18:14:08 by maleandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"
#include <iostream>
#include "unistd.h"
#include "stdio.h"
#include <cstdlib>

int main()
{
    Phonebook clientPhonebook;

    std::string Prompt;
    std::cout << "Greetings! As of now, your Contact List is empty..." << std::endl;
    sleep(1);
    while (1)
    {
        std::cout << "Please type either ADD | SEARCH | EXIT to change that... or not: " << std::endl;
        std::getline(std::cin, Prompt);
        for (size_t i = 0; i < Prompt.length(); i++)
            Prompt[i] = std::toupper(Prompt[i]);
        if (Prompt == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);

            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);

            std::cout << "Enter phonenumber: ";
            std::getline(std::cin, phoneNumber);

            std::cout << "Enter their darkest secret: ";
            std::getline(std::cin, darkestSecret);

            clientPhonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        }
        else if (Prompt == "SEARCH")
        {
            clientPhonebook.displayContacts();
            std::cout << "Which contact are you looking for? Insert the INDEX here: ";
            std::string string;
            int selected;
            std::getline(std::cin, string);
            selected = std::atoi(string.c_str());
            if (selected < 0 || selected > clientPhonebook.getListSize())
                std::cout << "Oof! Instructions unclear? That contact doesn't exist." << std::endl;
            else
                clientPhonebook.searchContact(selected - 1);
        }
        else if (Prompt == "EXIT")
        {
            break;
        }
        sleep(2);
    }
    
}