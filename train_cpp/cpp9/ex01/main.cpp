#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	int i = 0;
	std::vector<std::string> tokens;
	while (argv[1][i])
	{
		if (isdigit(argv[1][i]) || argv[1][i] == '+' || argv[1][i] == '-'
			|| argv[1][i] == '*' || argv[1][i] == '/')
		{
			tokens.push_back(std::string(1, argv[1][i]));
		}
		else if (argv[1][i] == ' ')
		{
			i++;
			continue;
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		i++;
	}
	RPN rpn;
	rpn.proccessNums(tokens);
	return 0;
}
