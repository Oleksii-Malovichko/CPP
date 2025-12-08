#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class RPN
{
	private:
		std::vector<int> data;
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void proccessNums();
};
