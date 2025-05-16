#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string str;
public:
	Weapon(void);
	Weapon(std::string str);
	~Weapon();
	void				setType(std::string name);
	const std::string	&getType() const;
};

#endif