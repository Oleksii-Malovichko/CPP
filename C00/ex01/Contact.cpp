#include "Contact.hpp"

void	Contact::setContact()
{
	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Phonenumber: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkestSecret);
}

bool	Contact::isValid() const
{
	return (!(firstName.empty() || lastName.empty() || nickName.empty()
				|| phoneNumber.empty() || darkestSecret.empty()));
}

std::string formatField(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return str;
}

void	Contact::displayShort(int index) const
{
	std::cout << std::setw(10) << index << "|"
		<< std::setw(10) << formatField(firstName) << "|"
		<< std::setw(10) << formatField(lastName) << "|"
		<< std::setw(10) << formatField(nickName) << std::endl;
}

void	Contact::displayFull() const {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}