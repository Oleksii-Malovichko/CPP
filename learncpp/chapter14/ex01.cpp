#include <iostream>
#include <string>

struct Snake
{
	std::string name{"snake"};
	int numLegs{0};
};

struct Dog
{
	std::string name = "dog";
	int numLegs = 4;
};

struct Chicken
{
	std::string name = "chicken";
	int numLegs = 2;
};

int main()
{
	Snake animal;
	std::cout << "a " << animal.name << " has " << animal.numLegs << " legs" << std::endl;
}