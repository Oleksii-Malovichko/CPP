#include "Base.hpp"
#include "inheritance/A.hpp"
#include "inheritance/B.hpp"
#include "inheritance/C.hpp"

int main()
{
	srand(time(NULL));

	int i = 0;
	Base *obj;

	while (i < 10)
	{
		obj = generate();

		// checking using ptr
		std::cout << "identify(Base*): ";
		identify(obj);

		//checking using ref
		std::cout << "identify(Base&): ";
		identify(*obj);

		if (i != 9)
			std::cout << "---------------" << std::endl;
	
		delete obj;
		i++;
	}
	return 0;
}