/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleandr <maleandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:22:12 by maleandr          #+#    #+#             */
/*   Updated: 2025/10/26 17:24:35 by maleandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
#include "Contact.hpp"
#include <string>
class Phonebook { 
	private:
	Contact contacts[8];
	int listSize;
	int overflowIndex;

	public:
	Phonebook(void);
	void addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
	void searchContact(int index);
	void displayContacts(void);
	int getListSize(void) const;
};

#endif