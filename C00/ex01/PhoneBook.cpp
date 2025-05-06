#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0), currentIndex(0) {}

void	PhoneBook::addContact()
{
	Contact newContact;
	newContact.setContact();
	if (!newContact.isValid())
	{
		std::cout << "Error: all fields must be field!" << std::endl;
		return ;
	}
	contacts[currentIndex] = newContact;
	currentIndex = (currentIndex + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
	std::cout << "Contact added succesfully" << std::endl;
}

void	PhoneBook::searchContact() const
{
	if (totalContacts == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First name" << "|"
				<< std::setw(10) << "Last name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < totalContacts; i++)
		contacts[i].displayShort(i);
	std::cout << "Enter index: ";
	int index;
	std::cin >> index;
	if (std::cin.fail() || index < 0 || index >= totalContacts)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	std::cin.ignore();
	contacts[index].displayFull();
}