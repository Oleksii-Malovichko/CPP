#pragma once

#include <exception>

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <sstream>

template <typename T>
class Array
{
	private:
		T *data;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		unsigned int size() const;
		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
};
