#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->data = nullptr;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->data = new T[n]();
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	_size = other._size;
	if (_size > 0)
	{
		data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			this->data[i] = other.data[i];
	}
	else
		data = nullptr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] data; // to loose the access for the previous array (var) and avoid the seg fault at the end (in destructor)

		this->_size = other._size;
		if (_size > 0)
		{
			data = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				this->data[i] = other.data[i];
		}
		else
			data = nullptr;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] data;
	data = nullptr;
	this->_size = 0;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < _size)
		return data[index];
	
	std::ostringstream oss; // for an informative msg
	oss << "Index " << index << " out of bounds for array of size " << _size;
	throw std::out_of_range(oss.str());
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index < _size)
		return data[index];
	
	std::ostringstream oss; // for an informative msg
	oss << "Index " << index << " out of bounds for array of size " << _size;
	throw std::out_of_range(oss.str());
}
