#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl; // 17
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl; // 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// using iterators
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "\nTesting ++it and --it:" << std::endl;
	++it; // moving iterator to the second el (3)
	std::cout << "After ++it: " << *it << std::endl;
	--it; // moving iterator to the first el (5)
	std::cout << "After --it: " << *it << std::endl;

	std::cout << "\nElements in MutantStack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// coping to std::stack
	std::stack<int> s(mstack);
	std::cout << "\nTop of copied std::stack: " << s.top() << std::endl;

	std::cout << "\n=== Test std::list for compairing===" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back(); // like pop
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Elements in lst:" << std::endl;
	for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit)
		std::cout << *lit << std::endl;
	return 0;
}

// playing with an original stack
// int main()
// {
// 	std::stack<int> s;

// 	s.push(10);
// 	s.push(20);
// 	s.push(30);

// 	std::cout << "Size of stack: " << s.size() << std::endl;

// 	std::cout << "Top element: " << s.top() << std::endl;

// 	s.pop();
// 	std::cout << "Top element after pop: " << s.top() << std::endl;

// 	while (!s.empty())
// 	{
// 		std::cout << "Removing: " << s.top() << std::endl;
// 		s.pop();
// 	}
// 	if (s.empty())
// 		std::cout << "Empty" << std::endl;
// 	else
// 		std::cout << "Not empty" << std::endl;
// }