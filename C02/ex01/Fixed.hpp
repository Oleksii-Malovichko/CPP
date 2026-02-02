#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	int value;
	static const int fractBits = 8;
	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float fnum);
		Fixed(const Fixed &other); // конструктор копирования
		Fixed& operator=(const Fixed &other); // оператор присваивания копированием
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
	
		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
