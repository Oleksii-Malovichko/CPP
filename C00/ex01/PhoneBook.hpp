/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:12:39 by omalovic          #+#    #+#             */
/*   Updated: 2025/05/06 15:25:43 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK
#define PHONE_BOOK

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int totalContacts;
		int currentIndex;
	
	public:
		PhoneBook();
		void addContact();
		void searchContact() const;
};

#endif