#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "USAGE: " << argv[0] << " <literal>" << std::endl;
		exit(0);
	}
	ScalarConverter::convert(argv[1]);
}