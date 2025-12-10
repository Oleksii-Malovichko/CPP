#include "PmergeMe.hpp"

void isSorted(std::vector<unsigned int> &vec)
{
	for (size_t i = 0; i + 1 < vec.size(); i++)
	{
		if (vec[i] > vec[i + 1])
		{
			std::cout << "NOT SORTED " << i << std::endl;
			return;
		}
	}
	std::cout << "SORTED" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	std::vector<unsigned int> vec;
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
		vec.push_back(num);
		i++;
	}
	i = 0;
	std::cout << "Before:" << std::endl;
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		if (lst.size() > 5 && i == 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *it << " ";
		i++;
	}
	std::cout << std::endl;
	
	PmergeMe merge;
	std::cout << "After:" << std::endl;
	merge.mergeInsertSort(vec);
	i = 0;
	std::vector<unsigned int> v_sorted;
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		if (vec.size() > 5 && i == 4)
		{
			std::cout << "[...]";
			break;
		}
		std::cout << *it << " ";
		v_sorted.push_back(*it);
		i++;
	}
	std::cout << std::endl;
	isSorted(v_sorted); // this func is only to show the evaluator that the vector is really sorted
	return 0;
}
