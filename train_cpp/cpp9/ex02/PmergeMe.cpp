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
	if (n == 0)
		return order;
	// Generate Jacobsthal numbers < n
	size_t a;
	size_t b;
	size_t c;
	// using formula J(k) = J(k-1) + 2 * J(k-2)
	std::vector<size_t> jac;
	a = 1; // default first values
	b = 3; // default first values
	if (a < n)
		jac.push_back(a);
	if (b < n)
		jac.push_back(b);
	while (true)
	{
		c = b + 2 * a; //
		if (c >= n)
			break;
		jac.push_back(c);
		a = b;
		b = c;
	}
	// here is building the order of insertion
	size_t prev = 0;
	for (size_t j : jac)
	{
		order.push_back(j);
		// insert j-1, j-2, ..., prev
		for (size_t i = j; i-- > prev; ) // in a normal view it's working slower!
			order.push_back(i);
		prev = j;
	}
	// insert n-1 till prev (when the nums of Jacobsthal are finished)
	for (size_t i = n; i-- > prev; )
		order.push_back(i);
	return order;
}

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
	// if the arr is odd, then put the last element to smalls arr
	if (vec.size() % 2 != 0)
		smalls.push_back(vec.back());
	// sorting the bigs using recursion
	// mergeInsertSort(bigs);
	// get the arr of indices to build the Jacobsthal order
	std::vector<size_t> order = buildJacobsthalIndices(smalls.size());
	// put smalls elements to bigs arr using the gotten order
	std::cout << "Order size: " << order.size() << std::endl;
	for (size_t i = 0; i < order.size(); i++)
	{
		std::cout << order[i] << " ";
	}
	std::cout << std::endl;
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