#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	Contact();
	void	setContact();
	void	showShort(int index);
	void	showFull();
	bool	isEmpty();
};

#endif