#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw) : rawBits(raw << fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw) : rawBits(roundf(raw * (1 << fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : rawBits(other.rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	rawBits = raw;
}

float Fixed::toFloat() const
{
	return (float)rawBits / (1 << fractBits);
}

int Fixed::toInt() const {
	return rawBits >> fractBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}