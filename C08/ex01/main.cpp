#include "Span.hpp"

int main()
{
	Span sp = Span(100000);
	std::vector<int> v;

	for (int i = 1; i <= 100000; i++)
		v.push_back(i);

	sp.moreNumbers(v.begin(), v.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

// // Subject main
// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }