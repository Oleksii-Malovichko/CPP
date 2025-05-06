#include "header.hpp"

const char *prog_name = "Primitive example"; // неизменяемая
char str_to_change[] = "Hello, world!";

int main()
{
	f();
	f2();
	std::cout << str_to_change << std::endl;
}