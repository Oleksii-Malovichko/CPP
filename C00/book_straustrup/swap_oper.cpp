#include <iostream>

void	swap(int *p1, int *p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}

void	swap(int &t1, int &t2) // тут используется ссылочная передача, которая есть только в с++
{
	int t = t1;
	t1 = t2;
	t2 = t;
}

/* 
в с++ разрешего использовать одинаковые имена для ф-ий, но у них должны быть разные типы их параметров */

int main()
{
	int t1 = 5;
	int t2 = 10;
	swap(&t1, &t2);
	std::cout << "t1: " << t1 << "; " << "t2: " << t2 << std::endl;
	swap(t1, t2);
	std::cout << "t1: " << t1 << "; " << "t2: " << t2 << std::endl;
	return (0);
}