#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>


template <typename T>
typename T::const_iterator easyfind(const T &container, int find)
{
	for (auto it = container.begin(); it != container.end(); ++it)
	{
		if (*it == find)
			return it;
	}
	throw std::runtime_error("Element not found");
}