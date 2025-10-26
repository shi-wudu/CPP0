/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleandr <maleandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:32:14 by maleandr          #+#    #+#             */
/*   Updated: 2025/10/26 18:26:18 by maleandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"
#include <iostream>

int Contact::addDetails(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) 
        return -1;
    if (firstName.find('\t') != std::string::npos || 
        lastName.find('\t') != std::string::npos || 
        nickname.find('\t') != std::string::npos || 
        phoneNumber.find('\t') != std::string::npos || 
        darkestSecret.find('\t') != std::string::npos)
        return -1;
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;

    return (0);
}

std::string Contact::getFirstName(void)
{
    return(firstName);
}

std::string Contact::getLastName(void)
{
    return(lastName);
}
std::string Contact::getNickname(void)
{
    return(nickname);
}
std::string Contact::getPhoneNumber(void)
{
    return(phoneNumber);
}
std::string Contact::getDarkestSecret(void)
{
    return(darkestSecret);
}