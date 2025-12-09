#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

class RPN
{
	private:
		std::stack<int> data;
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void proccessNums(const std::vector<std::string> &tokens);
};
