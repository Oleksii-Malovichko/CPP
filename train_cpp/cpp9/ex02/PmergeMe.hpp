#pragma once

#include <iostream>
#include <string>
#include <deque> // аналог вектор
#include <list>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void mergeInsertSort(std::deque<unsigned int> &deq);
		void mergeInsertSort(std::list<unsigned int> &lst);
};
