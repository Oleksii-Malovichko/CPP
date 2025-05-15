#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : cur_index(0) {}

void	PhoneBook::addContact()
{
	std::cout << "Adding a new contact..." << std::endl;
	contacts[cur_index].setContact();
	cur_index = (cur_index + 1) % 8;
}

bool	isNumeric(const std::string &str)
{
	const char *ptr;

	ptr = str.c_str(); // для преобразования в си строку (const char *ptr)
	if (*ptr == '\0')
		return (false);
	if (*ptr == '-')
		ptr++;
	while (*ptr)
	{
		if (!std::isdigit(static_cast<unsigned char>(*ptr)))
			return false;
		ptr++;
	}
	return true;
}

void	PhoneBook::searchContact()
{
	int index;
	std::string str_index;
	showContacts();

	while (1)
	{
		std::cout << "Enter index to view full contact details or -1 to come back to the commands: ";
		if (!std::getline(std::cin, str_index))
		{
			perror("[searchContact] getline");
			exit(1);
		}
		if (isNumeric(str_index) == false)
		{
			std::cout << "Index must be a num!" << std::endl;
			continue;
		}
		index = std::stoi(str_index);
		if (index == -1)
			break ;
		if (index >= 0 && index < 8 && !contacts[index].isEmpty())
			contacts[index].showFull();
		else
			std::cout << "Invalid index!" << std::endl;
	}
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