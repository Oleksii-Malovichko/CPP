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

/* 
some usefull examples:
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <algorithm> // for find

int main()
{
	// example vector. По факту это массив, однако, ему не нужно задавать длину, так как его размер увеличивается динамически
	std::vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	std::cout << "v[0] = " << v[0] << std::endl;

	std::cout << "All elements of vector:" << std::endl;
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i - 1 != v.size())
			std::cout << std::endl;
	}
	std::cout << std::endl;

	// example list
	std::list<int> lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	
	std::cout << "All elements of lst:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;

	// example find and vector
	std::vector<int> v1 = {5, 10, 20, 40};
	
	int target = 20;

	std::vector<int>::iterator it = std::find(v.begin(), v.end(), target);
	if (it != v.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;
}
 */