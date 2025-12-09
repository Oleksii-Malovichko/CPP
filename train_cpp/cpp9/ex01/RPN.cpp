#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->data = other.data;
	}
	return *this;
}

RPN::~RPN() {}


void RPN::proccessNums(const std::vector<std::string> &tokens)
{
	int a;
	int b;

	for (size_t i = 0; i < tokens.size(); i++)
	{
		if (tokens[i] != "+" && tokens[i] != "-"
			&& tokens[i] != "*" && tokens[i] != "/")
		{
			// data.push(tokens[i][0] - '0');
			data.push(std::stoi(tokens[i]));
		}
		else
		{
			if (data.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			b = data.top();
			data.pop();
			a = data.top();
			data.pop();
			if (tokens[i] == "+")
				data.push(a + b);
			else if (tokens[i] == "-")
				data.push(a - b);
			else if (tokens[i] == "*")
				data.push(a * b);
			else if (tokens[i] == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error" << std::endl;
					return ;
				}
				data.push(a / b);
			}
		}
	}
	if (data.size() == 1)
	{
		std::cout << data.top() << std::endl;
		return ;
	}
	std::cout << "Error" << std::endl;
}
