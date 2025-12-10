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
	if (vec.size() % 2 != 0)
		smalls.push_back(vec.back());
	for (size_t i = 1; i < bigs.size(); ++i)
	{
		unsigned int key = bigs[i];
		size_t j = i;
		while (j > 0 && bigs[j - 1] > key)
		{
			bigs[j] = bigs[j - 1];
			--j;
		}
		bigs[j] = key;
	}
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