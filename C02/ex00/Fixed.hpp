#pragma once

#include <string>
#include <iostream>

class Fixed
{
	int fixedPointNum;
	static const int fractBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};