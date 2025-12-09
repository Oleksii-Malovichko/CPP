#include "BitcoinExchange.hpp"

float parse_value(std::string line, std::size_t pos, bool main)
{
	std::string value_str = line.substr(pos + 1);
	float value;
	try
	{
		value = std::stof(value_str);
	}
	catch(...)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return -1;
	}
	
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return -1;
	}
	if (value > 1000 && main)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return -1;
	}
	return value;
}

bool parse_date(std::string line, std::string &date)
{
	date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
	if (date.size() != 10)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}

	std::string year_str = date.substr(0, 4);
	std::string month_str = date.substr(5, 2);
	std::string day_str = date.substr(8, 2);

	int year;
	int month;
	int day;
	try
	{
		year = std::stoi(year_str);
		month = std::stoi(month_str);
		day = std::stoi(day_str);
	}
	catch(...)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}

	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	return 1;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange exchange;

	exchange.collectDb("data.csv");
	// get data from input.txt
	std::ifstream inFile(argv[1]);
	if (!inFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		if (line == "date | value")
		{
			continue;
		}

		auto it = std::find(line.begin(), line.end(), '|');
		if (it == line.end())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::size_t pos = it - line.begin();
		std::string date = line.substr(0, pos);

		//parse value
		float value = parse_value(line, pos, 1);
		if (value == -1)
			continue;
		// std::cout << value << std::endl;

		// parse date
		if (!parse_date(line, date))
			continue;
		// std::cout << date << std::endl;
		exchange.findRate(date, value);
	}
	inFile.close();
	return 0;
}

/* 
задача
есть бд с датами и курсом биткоинов

также нужно создать файл input.txt, где указана
дата и КОЛИЧЕСТВО биткоинов

программа должна прочитать строку в input и сравнить
с курсом бд и вывести сумму биткоина в таком формате

Пример (input.txt):
2010-11-15 | 2
2010-11-17 | 1.5
2010-11-20 | 0.5

БД:
2010-11-11,0.24
2010-11-14,0.3
2010-11-17,0.28
2010-11-20,0.29

Вывод:
2010-11-14 => 2 = 0.6   (так как 2010-11-15 нет, берём 2010-11-14)
2010-11-17 => 1.5 = 0.42
2010-11-20 => 0.5 = 0.145
*/