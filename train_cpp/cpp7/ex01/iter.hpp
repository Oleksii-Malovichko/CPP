#pragma once

#include <iostream>
#include <string>

template <typename T, typename F>

void iter(T *arr, size_t len, F func)
{
	size_t i = 0;

	if (!arr)
		return ;
	while (i < len)
	{
		func(arr[i]);
		i++;
	}
}

// for test
template <typename T>
void printEl(const T &x)
{
	std::cout << x << std::endl;
}

void modifyStr(std::string &s);
void printStr(const std::string &s);
void incrementInt(int &x);
void printInt(const int &x);