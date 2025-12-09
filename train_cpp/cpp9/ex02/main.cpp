#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	std::deque<unsigned int> deq;
	std::list<unsigned int> lst;
	int i = 1;
	int num = -1;
	while (i < argc)
	{
		try
		{
			num = std::stoi(argv[i]);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		if (num <= 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		lst.push_back(num);
		deq.push_back(num);
		i++;
	}
	i = 0;
	std::cout << "Before:" << std::endl;
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		if (lst.size() > 5 && i == 4)
		{
			std::cout << "[...]" << std::endl;
			break;
		}
		std::cout << *it << " ";
		i++;
	}
	std::cout << std::endl;
	return 0;
}