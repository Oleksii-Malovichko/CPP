#pragma once

#include <iostream>
#include <string>

class Fixed
{
	int value;
	static const int fractBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &other); // конструктор копирования
		Fixed& operator=(const Fixed &other); // оператор присваивания копированием
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

//[int getRawBits(void) const] мы только возвращаем значение, и ничего не меняем, поэтому const