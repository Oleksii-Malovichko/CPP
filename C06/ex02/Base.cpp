#include "Base.hpp"
#include "inheritance/A.hpp"
#include "inheritance/B.hpp"
#include "inheritance/C.hpp"
#include <random>

Base::~Base() {}

Base *generate(void)
{
	int randNum = rand() % 3;

	if (randNum == 0)
		return new A();
	else if (randNum == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) // so here in a bad case will be nullptr
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) // there is no nullptr for ref!!!
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast&)
	{}// not a
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast&)
	{}// not b

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast&)
	{}// not c
}