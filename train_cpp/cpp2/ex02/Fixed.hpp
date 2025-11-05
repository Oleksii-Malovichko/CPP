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
		// comparison operators
		bool operator>(Fixed const &other) const;
		bool operator<(Fixed const &other) const;
		bool operator>=(Fixed const &other) const;
		bool operator<=(Fixed const &other) const;
		bool operator==(Fixed const &other) const;
		bool operator!=(Fixed const &other) const;

		// 4 arithmetic operators
		Fixed operator+(Fixed const &other) const;
		Fixed operator-(Fixed const &other) const;
		Fixed operator*(Fixed const &other) const;
		Fixed operator/(Fixed const &other) const;

		// post-incrementing/decrementing
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		// overloaded member funcs
		static Fixed &min(Fixed &p1, Fixed &p2);
		static const Fixed &min(Fixed const &p1, Fixed const &p2);
		static Fixed &max(Fixed &p1, Fixed &p2);
		static const Fixed &max(Fixed const &p1, Fixed const &p2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
