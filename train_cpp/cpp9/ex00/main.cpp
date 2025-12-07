#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 0;
	}
	std::ifstream inFile(argv[1]);
	if (!inFile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		std::cout << line << std::endl;
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