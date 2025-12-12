#include "PmergeMe.hpp"

bool isSorted(std::vector<unsigned int> &vec)
{
	for (size_t i = 0; i + 1 < vec.size(); i++)
	{
		if (vec[i] > vec[i + 1])
		{
			return 0;
		}
	}
	return 1;
}

bool checkLostElements(std::vector<unsigned int> vec, std::vector<unsigned int> v_sorted)
{
	bool found = 0;
	if (vec.size() != v_sorted.size())
		return 0;
	for (size_t i = 0; i < vec.size() ; i++)
	{
		size_t j = 0;
		found = 0;
		while (j < v_sorted.size())
		{
			if (vec[i] == v_sorted[j])
			{
				found = 1;
				break;
			}
			j++;
		}
		if (!found)
			return 0;
	}
	return 1;
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
		// if (lst.size() > 5 && i == 4)
		// {
		// 	std::cout << "[...]";
		// 	break;
		// }
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
		// if (vec.size() > 5 && i == 4)
		// {
		// 	std::cout << "[...]";
		// 	break;
		// }
		std::cout << *it << " ";
		v_sorted.push_back(*it);
		i++;
	}
	std::cout << std::endl;
	if (isSorted(v_sorted) && vec.size() == v_sorted.size())
		std::cout << "SORTED [OK]" << std::endl;
	else
		std::cout << "NOT SORTED [ERROR]" << std::endl;
	if (checkLostElements(vec, v_sorted))
		std::cout << "NO LOSTED [OK]" << std::endl;
	else
		std::cout << "LOSTED ELEMENTS [ERROR]" << std::endl;
	return 0;
}
