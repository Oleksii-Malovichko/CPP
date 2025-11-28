#include "iter.hpp"

void printInt(const int &x)
{
	std::cout << x << std::endl;
}

void incrementInt(int &x)
{
	x++;
	std::cout << "[incrementInt] done!" << std::endl;
}

void printStr(const std::string &s)
{
	std::cout << s << std::endl;
}

void modifyStr(std::string &s)
{
	s += ".";
	std::cout << "[modifyStr] done!" << std::endl;
}
