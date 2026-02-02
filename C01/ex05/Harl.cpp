#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "error" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string arr[] = {"debug", "info", "warning", "error"};
	// массив указателей на ф-ии
	void (Harl::*actions[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == arr[i])
		{
			(this->*actions[i])();
			return ;
		}
	}
}
