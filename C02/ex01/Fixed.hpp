#pragma once

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	rawBits;
		static const int fractBits = 8;
	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);