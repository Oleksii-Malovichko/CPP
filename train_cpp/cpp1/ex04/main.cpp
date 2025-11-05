#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
std::string doReplace(std::string buffer, std::string s1, std::string s2, size_t start = 0)
{
	std::size_t i = 0;
	std::size_t j = 0;
	std::size_t pos;
	std::string buffer2;

	pos = buffer.find(s1, start);
	if (pos == std::string::npos)
		return buffer;
	while (i < pos)
	{
		buffer2 += buffer[i];
		i++;
	}
	while (j < s2.length())
	{
		buffer2 += s2[j];
		j++;
		i++;
	}
	size_t k = pos + s1.length();
	while (k < buffer.length())
	{
		buffer2 += buffer[k];
		k++;
	}
	return doReplace(buffer2, s1, s2, i);
}

int main(int argc, char **argv)
{
	// получение аргументов в переменные
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cerr << "I'm not a fool to execute the program with such \"nice\" arguments ;)" << std::endl;
		return 1;
	}
	// открытие файла
	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	// запись из файла в переменную
	std::string buffer;
	char c;
	while (inputFile.get(c))
	{
		buffer += c;
	}
	inputFile.close();
	// получение корректной строки
	printf("rec started\n");
	std::string replaced = doReplace(buffer, s1, s2);
	// запись в другой файл
	std::ofstream outputFile(filename+=".replace");
	if (!outputFile.is_open())
	{
		std::cerr << "Error: could not create output file" << std::endl;
		return 1;
	}
	outputFile << replaced;
	return 0;
}