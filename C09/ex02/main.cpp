#include "PmergeMe.hpp"

bool isSorted(const std::vector<unsigned int> &vec)
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

bool checkLostElements(const std::vector<unsigned int> &original, const std::vector<unsigned int> &vec)
{
	if (original.size() != vec.size())
		return 0;
	std::vector<unsigned int> sorted = original;
	std::sort(sorted.begin(), sorted.end());
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (sorted[i] != vec[i])
			return 0;
	}
	return 1;
}

bool checkDup(int currNum, int i, int argc, char **argv)
{
	int num;
	while (i < argc)
	{
		try
		{
			num = std::stoi(argv[i]);
		}
		catch(const std::exception& e)
		{
			return 0;
		}
		if (currNum == num)
			return 0;
		i++;
	}
	return 1;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
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
		if (num < 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		if (!checkDup(num, i + 1, argc, argv))
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
	std::vector<unsigned int> original = vec;
	auto start_vec = std::chrono::high_resolution_clock::now();
	merge.mergeInsertSort(vec);
	auto end_vec = std::chrono::high_resolution_clock::now();
	double time_vec = std::chrono::duration<double, std::micro>(end_vec - start_vec).count();
	i = 0;
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		// if (vec.size() > 5 && i == 4)
		// {
		// 	std::cout << "[...]";
		// 	break;
		// }
		std::cout << *it << " ";
		i++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time_vec << " us" << std::endl;

	auto start_lst = std::chrono::high_resolution_clock::now();
	merge.mergeInsertSort(lst);
	auto end_lst = std::chrono::high_resolution_clock::now();
	double time_lst = std::chrono::duration<double, std::micro>(end_lst - start_lst).count();
	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::list : " << time_lst << " us" << std::endl;

	// testing if everything was correctly sorted
	if (isSorted(vec))
		std::cout << "SORTED [OK]" << std::endl;
	else
		std::cerr << "NOT SORTED [ERROR]" << std::endl;
	if (checkLostElements(original, vec))
		std::cout << "NO LOSTED [OK]" << std::endl;
	else
		std::cerr << "LOSTED ELEMENTS [ERROR]" << std::endl;
	return 0;
}
