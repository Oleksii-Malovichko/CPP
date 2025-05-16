#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : cur_index(0) {}

void	PhoneBook::addContact()
{
	std::cout << "Adding a new contact..." << std::endl;
	contacts[cur_index].setContact();
	if (contacts[cur_index].checkName())
		cur_index = (cur_index + 1) % 8;
}

bool	isNumeric(const std::string &str)
{
	const char *ptr;

	ptr = str.c_str(); // для преобразования в си строку (const char *ptr)
	if (*ptr == '\0')
		return (false);
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr)
	{
		if (!std::isdigit(static_cast<unsigned char>(*ptr)))
			return false;
		ptr++;
	}
	return true;
}

bool isValidIntRange(std::string str)
{
	if (str.empty())
		return false;
	
	int start = 0;
	if (str[0] == '-' || str[0] == '+')
		start++;
	if (start == 1 && str.size() == 1)
		return false;
	for (size_t i = start; i < str.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
	}
	if (str.size() - start > 10)
		return false;
	long long val = std::stoll(str);
	return (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
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
		if (!isValidIntRange(str_index))
		{
			std::cout << "[searchContact:isValidIntRange] Invalid index!" << std::endl;
			continue;
		}
		index = std::stoi(str_index);
		if (index == -1)
			break ;
		if (index >= 0 && index < 8 && !contacts[index].isEmpty())
			contacts[index].showFull();
		else
		{
			std::cout << "[searchContact] Invalid index!" << std::endl;
			continue;
		}
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