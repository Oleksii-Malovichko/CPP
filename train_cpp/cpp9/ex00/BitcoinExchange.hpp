#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> db;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void collectDb(const std::string &nameDB);
		void findRate(std::string date, double value);
};

double parse_value(std::string line, std::size_t pos, bool main);
bool parse_date(std::string line, std::string &date);
