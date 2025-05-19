#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

// int main( void ) {
	
// 	Fixed a;
// 	Fixed b(a);
// 	Fixed c;

// 	a.setRawBits(25);
// 	b.setRawBits(30);
// 	c.setRawBits(3);

// 	std::cout << c.getRawBits() << std::endl;
// 	c = b;
	
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;

// 	return 0;
// }