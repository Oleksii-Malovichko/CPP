#pragma once

#include <string>
#include <iostream>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		void complain( std::string level ); // call all funcs above
};

struct LevelFunction
{
	std::string level;
	void	(Harl::*func)();
};