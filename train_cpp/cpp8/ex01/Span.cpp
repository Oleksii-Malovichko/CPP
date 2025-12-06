#include "Span.hpp"

Span::Span(unsigned int len) : len(len) {}

// faster for a big quantity of numbers
Span::Span(const Span &other) : len(other.len), nums(other.nums) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->len = other.len;
		this->nums = other.nums;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (nums.size() + 1 > len)
		throw std::out_of_range("Out of range");
	nums.push_back(n);
}

int Span::longestSpan() const
{
	if (nums.size() < 2)
		throw std::out_of_range("Too few nums");

	int min = *std::min_element(nums.begin(), nums.end());
	int max = *std::max_element(nums.begin(), nums.end());
	return max - min;
}

int Span::shortestSpan() const
{
	size_t i = 1;
	std::vector<int> sorted = nums;

	if (sorted.size() < 2)
		throw std::out_of_range("Too few nums");
	
	std::sort(sorted.begin(), sorted.end());

	int min_diff = sorted[1] - sorted[0];
	while (i < sorted.size() - 1)
	{
		int diff = sorted[i + 1] - sorted[i];
		if (diff < min_diff)
			min_diff = diff;
		i++;
	}
	return min_diff;
}
