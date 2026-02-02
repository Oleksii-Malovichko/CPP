#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;
	size_t	i;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			perror("[main] getline");
			break;
		}
		i = 0;
		while (i < command.size() && std::isspace(static_cast<unsigned char>(command[i])))
			i++;
		if (i > 0)
			command = command.substr(i);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break ;
	}
	return 0;
}
