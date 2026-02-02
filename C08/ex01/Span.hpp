#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		unsigned int len;
		std::vector<int> nums;
	public:
		Span(unsigned int len);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename T>
		void moreNumbers(T begin, T end);
};

template <typename T>
void Span::moreNumbers(T begin, T end)
{
	for (auto it = begin; it != end; ++it)
	{
		addNumber(*it);
	}
}