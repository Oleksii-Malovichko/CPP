#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		db = other.db;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::collectDb(const std::string &nameDB)
{
	std::ifstream inFile(nameDB);

	if (!inFile.is_open())
	{
		std::cerr << "Error: failed to open DB" << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		if (line == "date,exchange_rate")
			continue;
		auto it = std::find(line.begin(), line.end(), ',');
		if (it == line.end())
		{
			std::cerr << "Error: bad DB => " << line << std::endl;
			return ;
		}
		std::size_t pos = it - line.begin();
		std::string date = line.substr(0, pos);
		//parse value
		float value = parse_value(line, pos);
		if (value == -1)
			continue;

		// parse date
		if (!parse_date(line, date))
			continue;
		db[date] = value;
	}
	// вывести дб
	for (const auto &pair : db)
		std::cout << pair.first << " -> " << pair.second << std::endl;
}