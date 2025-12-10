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


void RPN::proccessNums(std::stack<std::string> &tokens)
{
	int a;
	int b;

	std::stack<std::string> tokens2;

	// get the direction back
	while (!tokens.empty())
	{
		tokens2.push(tokens.top());
		tokens.pop();
	}
	while (!tokens2.empty())
	{
		if (tokens2.top() != "+" && tokens2.top() != "-"
			&& tokens2.top() != "*" && tokens2.top() != "/")
		{
			// data.push(tokens2[i][0] - '0');
			data.push(std::stoi(tokens2.top()));
			tokens2.pop();
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
			if (tokens2.top() == "+")
				data.push(a + b);
			else if (tokens2.top() == "-")
				data.push(a - b);
			else if (tokens2.top() == "*")
				data.push(a * b);
			else if (tokens2.top() == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error" << std::endl;
					return ;
				}
				data.push(a / b);
			}
			tokens2.pop();
		}
	}
	if (data.size() == 1)
	{
		std::cout << data.top() << std::endl;
		return ;
	}
	std::cout << "Error" << std::endl;
}
