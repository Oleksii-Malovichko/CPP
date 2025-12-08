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
		std::cerr << "Error: could not open file." << std::endl;
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
		float value = parse_value(line, pos, 0);
		if (value == -1)
			continue;

		// parse date
		if (!parse_date(line, date))
			continue;
		db[date] = value;
	}
	// show db
	// for (const auto &pair : db)
	// 	std::cout << pair.first << " -> " << pair.second << std::endl;
}

void BitcoinExchange::findRate(std::string date, float value)
{
	auto it = db.lower_bound(date);
	float price;

	if (it != db.end() && it->first == date)
	{
		price = it->second * value;
	}
	else if (it != db.begin())
	{
		--it;
		price = it->second * value;
	}
	else
	{
		std::cerr << "Error: no available date before " << date << std::endl;
		return ;
	}
	std::cout << date << " => " << value << " = " << price << std::endl;
}
