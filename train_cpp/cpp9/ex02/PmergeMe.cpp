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

void PmergeMe::mergeInsertSort(std::vector<unsigned int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<unsigned int> bigs;
	std::vector<unsigned int> smalls;
	// separete to the pairs
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
		{
			bigs.push_back(vec[i]);
			smalls.push_back(vec[i + 1]);
		}
		else
		{
			bigs.push_back(vec[i + 1]);
			smalls.push_back(vec[i]);
		}
	}
	// if the arr is odd
	if (vec.size() % 2 != 0)
		smalls.push_back(vec.back());
	// sorting the bigs using recursion
	mergeInsertSort(bigs);
	// select smalls to the sorted bigs arr
	for (unsigned int s : smalls)
	{
		auto pos = std::lower_bound(bigs.begin(), bigs.end(), s);
		bigs.insert(pos, s);
	}
	vec = bigs;
}

void PmergeMe::mergeInsertSort(std::list<unsigned int> &lst)
{
	(void)lst;
}