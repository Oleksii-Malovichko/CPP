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

std::vector<size_t> buildJacobsthalIndices(size_t n)
{
    std::vector<size_t> order;
    if (n == 0) return order;

    // Jacobsthal numbers: 1, 3, 5, 11, 21, ...
    std::vector<size_t> jac;
    {
        size_t a = 1, b = 3;
        if (a < n) jac.push_back(a);
        if (b < n) jac.push_back(b);
        while (true) {
            size_t c = b + 2 * a;
            if (c >= n) break;
            jac.push_back(c);
            a = b;
            b = c;
        }
    }

    size_t prev = 0;

    for (size_t j : jac) {
        // Insert the Jacobsthal index
        order.push_back(j);

        // Insert backwards from j-1 down to prev
        for (size_t i = j; i-- > prev;)
            order.push_back(i);

        prev = j + 1;
    }

    // Tail: (n-1) down to prev
    for (size_t i = n; i-- > prev;)
        order.push_back(i);

    return order;
}

void PmergeMe::mergeInsertSort(std::vector<unsigned int> &vec)
{
	if (vec.size() <= 1)
		return;
	// std::cout << "vec size: " << vec.size() << std::endl;
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
	// std::cout << "Smalls size: " << smalls.size() << std::endl;
	std::vector<size_t> order = buildJacobsthalIndices(smalls.size());
	// std::cout << "Smalls order size: " << order.size() << std::endl;
	// for (size_t i = 0; i < order.size(); i++)
	// {
	// 	std::cout << order[i] << " ";
	// }
	// std::cout << std::endl;
	// for (unsigned int s : smalls)
	// {
	// 	auto pos = std::lower_bound(bigs.begin(), bigs.end(), s);
	// 	bigs.insert(pos, s);
	// }

	for (size_t idx : order)
	{
		unsigned int value = smalls[idx];
		auto pos = std::lower_bound(bigs.begin(), bigs.end(), value);
		bigs.insert(pos, value);
	}
	vec = bigs;
}

void PmergeMe::mergeInsertSort(std::list<unsigned int> &lst)
{
	(void)lst;
}