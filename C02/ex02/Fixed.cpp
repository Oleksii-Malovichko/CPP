#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {}
Fixed::Fixed(const int raw) : rawBits(raw << fractBits) {}
Fixed::Fixed(const float raw) : rawBits(roundf(raw * (1 << fractBits))) {}
Fixed::Fixed(const Fixed& other) : rawBits(other.rawBits) {}
Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

int Fixed::getRawBits() const
{
	return rawBits;
}

void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

float Fixed::toFloat() const
{
	return (float)rawBits / (1 << fractBits);
}

int Fixed::toInt() const
{
	return rawBits >> fractBits;
}


Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}


bool Fixed::operator>(const Fixed& other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->getRawBits() != other.getRawBits();
}


// Pre-increment func
Fixed& Fixed::operator++()
{
	this->rawBits++;
	return *this;
}

// Post-increment func
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->rawBits++;
	return temp;
}

// Pre-decrement func
Fixed& Fixed::operator--()
{
	this->rawBits--;
	return *this;
}

// Post-decrement func
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->rawBits--;
	return temp;
}

// 4 overloaded functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
	return b;
}


// overload function for outputing as float
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
