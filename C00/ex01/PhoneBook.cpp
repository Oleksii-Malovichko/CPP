#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : cur_index(0) {}

void	PhoneBook::addContact()
{
	std::cout << "Adding a new contact..." << std::endl;
	contacts[cur_index].setContact();
	cur_index = (cur_index + 1) % 8;
}

void	PhoneBook::searchContact()
{
	int index;

	showContacts();

	std::cout << "Enter index to view full contact details or -1 to come back to the commands: ";
	std::cin >> index;
	std::cin.ignore(); // free the buffer of std::cin
	if (index == -1)
		return ;
	if (index >= 0 && index < 8 && !contacts[index].isEmpty())
		contacts[index].showFull();
	else
		std::cout << "Invalid index!" << std::endl;
}

void	PhoneBook::showContacts()
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First name" << "|"
				<< std::setw(10) << "Last name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].isEmpty())
			contacts[i].showShort(i);
	}
}