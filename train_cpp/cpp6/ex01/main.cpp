#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data d;
	d.number = 55;
	d.text = "Hello world!";

	Data *p = &d;

	std::cout << "Previous pointer: " << p << std::endl;

	uintptr_t num = Serializer::serialize(p);
	std::cout << "Serialized: " << num << std::endl;

	Data *newPtr = Serializer::deserialize(num);
	std::cout << "Deserialized: " << newPtr << std::endl;

	assert(p == newPtr);
}

// so here is going on the forced changing of types. In this case from ptr (normal view of address) to the same but in integer
// and then back. static_cast will not pass, cause static_cast<uintptr_t>(ptr) ---> will cause an error