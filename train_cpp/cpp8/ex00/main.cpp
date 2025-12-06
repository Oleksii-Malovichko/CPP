#include "easyfind.hpp"

int main()
{
	std::vector<int> v = {0, 10, 20, 30, 40};
	std::list<int> lst = {50, 60, 70, 80};
	std::deque<int> deq = {90, 100, 110};

	try
	{
		// vector
		std::cout << "Try find in vector" << std::endl;
		auto it = easyfind(v, 10);
		std::cout << *it << std::endl;
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		// list
		std::cout << "\nTry find in list" << std::endl;
		auto it1 = easyfind(lst, 10);
		std::cout << *it1 << std::endl;
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		// deque
		std::cout << "\nTry find in deque" << std::endl;
		auto it2 = easyfind(deq, 90);
		std::cout << *it2 << std::endl;
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}