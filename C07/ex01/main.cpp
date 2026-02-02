#include "iter.hpp"

int main()
{
	int arr[] = {1,2,3,4,5};
	std::string arr1[] = {"Hello", "world", "!!!"};
	const int arr2[] = {10, 20, 30, 40};
	
	std::cout << "===USING: iter(int arr, 5, printInt)===" << std::endl;
	iter(arr, 5, printInt);

	std::cout << "\n===USING: iter(int arr, 5, incrementInt)===" << std::endl;
	iter(arr, 5, incrementInt);
	
	std::cout << "\n===USING: iter(std::string arr, 3, printStr)===" << std::endl;
	iter(arr1, 3, printStr);

	std::cout << "\n===USING: iter(std::string arr, 3, modifyStr)===" << std::endl;
	iter(arr1, 3, modifyStr);

	std::cout << "\n===USING: iter(const int arr, 4, printInt)===" << std::endl;
	iter(arr2, 4, printInt);

	std::cout << "\n===USING: iter(prev arrs, n, printEl)===" << std::endl;
	iter(arr, 5, printEl<int>);
	
	std::cout << "\n" << std::endl;
	// iter(arr1, 3, printEl<std::string>);
	iter(arr1, 3, [](const auto &x){printEl(x);}); // tried to use lambda func
	
	std::cout << "\n" << std::endl;
	iter(arr2, 4, printEl<int>);

	return 0;
}