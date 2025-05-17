#include <iostream>
#include <string>

class Date
{
	public:
		int day;
		int month;
		int year;
		void	printDate(void);
};

void	Date::printDate()
{
	std::cout << day << '/' << month << '/' << year << std::endl;
}

int main()
{
	Date data;

	data.day = 3;
	data.month = 5;
	data.year = 2025;
	data.printDate();
}