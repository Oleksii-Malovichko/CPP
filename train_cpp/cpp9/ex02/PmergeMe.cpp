#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}


void PmergeMe::mergeInsertSort(std::deque<unsigned int> &deq)
{
	int big;
	int small;

	if (deq.size() <= 1)
		return ;
	if (deq.size() == 2)
	{
		if (deq[0] > deq[1])
			std::swap(deq[0], deq[1]);
		return ;
	}
	std::deque<std::pair<unsigned int, unsigned int>> storage;
	// std::deque<unsigned int> smalls;
	for (auto it = deq.begin(); it + 1 != deq.end(); it+=2)
	{
		big = (*it > *it + 1) ? *it : *it + 1;
		small = (*it > *it + 1) ? *it + 1 : *it;
		std::pair<unsigned int, unsigned int> p(big, small);
		storage.push_back(p);
	}
	std::deque<unsigned int> bigs;
	for (auto &p : storage)
	{
		bigs.push_back(p.first);
	}
	if (deq.size() % 2 != 0)
	{
		bigs.push_back(deq.back());
	}
	if (bigs.size() <= 2)
	{
		if (bigs.size() == 2 && bigs[0] > bigs[1])
		{
			std::swap(bigs[0], bigs[1]);
		}
	}
	else
	{
		mergeInsertSort(bigs);
	}
	// now working with smalls and insert them to sorted deque of bigs
	std::deque<unsigned int> smalls;
	for (auto &p : storage)
	{
		smalls.push_back(p.second);
	}
	for (unsigned int s : smalls)
	{
		auto pos = std::lower_bound(bigs.begin(), bigs.end(), s);
		bigs.insert(pos, s);
	}
	deq = bigs;
}

void PmergeMe::mergeInsertSort(std::list<unsigned int> &lst)
{
	(void)lst;
}