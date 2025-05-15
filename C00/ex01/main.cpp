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
		while (i < command.length() && std::isspace(static_cast<unsigned char>(command[i])))
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

/* 

проблемы с getline in main
problems with std::cin in std::cin >> index; after clickin ctrl+d

также при получении ввода нужно удалять пробелы, если человек введет "     ADD" ф-я не сработает

- Entering non-numeric input in the SEARCH (when an index is expected). - Sending EOF (Ctrl-D) in SEARCH or the main loop. 
I'm sure you can fix those things easily*/