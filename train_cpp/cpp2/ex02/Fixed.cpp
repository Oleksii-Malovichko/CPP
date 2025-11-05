#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = num << this->fractBits;
}

Fixed::Fixed(const float fnum)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(fnum * (1 << this->fractBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

float Fixed::toFloat(void) const
{
	return (float)this->value / (1 << this->fractBits);
}

int Fixed::toInt(void) const
{
	return this->value >> fractBits; // this->value >> 8
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

bool Fixed::operator>(Fixed const &other) const
{
	return this->value > other.value;
}

bool Fixed::operator<(Fixed const &other) const
{
	return this->value < other.value;
}

bool Fixed::operator>=(Fixed const &other) const
{
	return this->value >= other.value;
}

bool Fixed::operator<=(Fixed const &other) const
{
	return this->value <= other.value;
}

bool Fixed::operator==(Fixed const &other) const
{
	return this->value == other.value;
}

bool Fixed::operator!=(Fixed const &other) const
{
	return this->value != other.value;
}

Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed result;
	long tmp = (long)this->getRawBits() * (long)other.getRawBits();
	result.setRawBits((int)(tmp >> 8)); // divide to 256
	return result;
}

Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed result;
	long tmp = ((long)this->getRawBits() << 8) / (long)other.getRawBits();
	result.setRawBits((int)(tmp));
	return result;
}

Fixed &Fixed::operator++()
{
	this->value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	this->value += 1;
	return old;
}

Fixed &Fixed::operator--()
{
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	this->value -= 1;
	return old;
}

Fixed &Fixed::min(Fixed &p1, Fixed &p2)
{
	if (p1 > p2)
		return p2;
	else
		return p1;
}

const Fixed &Fixed::min(Fixed const &p1, Fixed const &p2)
{
	if (p1 > p2)
		return p2;
	else
		return p1;
}

Fixed &Fixed::max(Fixed &p1, Fixed &p2)
{
	if (p1 > p2)
		return p1;
	else
		return p2;
}

const Fixed &Fixed::max(Fixed const &p1, Fixed const &p2)
{
	if (p1 > p2)
		return p1;
	else
		return p2;
}