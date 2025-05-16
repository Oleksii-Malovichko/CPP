#include "Contact.hpp"

Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
}

bool Contact::isEmpty()
{
	return (firstName.empty());
}

void	Contact::setContact()
{
	std::cout << "Enter your First name: ";
	std::getline(std::cin, firstName);

	std::cout << "Enter your Last name: ";
	std::getline(std::cin, lastName);

	std::cout << "Enter your Nickname: ";
	std::getline(std::cin, nickName);

	std::cout << "Enter your Phone number: ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Enter your Darkest secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickName.empty()
		|| phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: all fields must be filled!" << std::endl;
		firstName = "";
	}
}

std::string formatField(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return str;
}

void	Contact::showShort(int index)
{
	std::cout << std::setw(10) << index << "|"
		<< std::setw(10) << formatField(firstName) << "|"
		<< std::setw(10) << formatField(lastName) << "|"
		<< std::setw(10) << formatField(nickName) << std::endl;
}

void	Contact::showFull()
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}