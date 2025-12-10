#pragma once

#include <iostream>
#include <string>
#include <deque> // аналог вектор
#include <list>
#include <vector>
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void mergeInsertSort(std::vector<unsigned int> &vec);
		void mergeInsertSort(std::list<unsigned int> &lst);
};
