#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void error()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	exit(1);
}

int checkSpesialLiterals(const std::string &literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::string d = literal.substr(0, literal.size() - 1);
		std::cout << "double: " << d << std::endl;
		return 1;
	}
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return 1;
	}
	return 0;
}

int convertChar(const std::string &literal)
{
	char c;
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		c = literal[1];
	}
	// else if (literal.length() == 1)
	// 	c = literal[0];
	else
		return 0;

	if (isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: non-displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	return 1;
}

bool isInt(const std::string &literal)
{
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i = 1;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (!isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

int convertInt(const std::string &literal)
{
	if (!isInt(literal))
		return 0;
	long long checker;
	try
	{
    	checker = std::stoll(literal);
	}
	catch (...)
	{
		return 0;
	}
	// catch (const std::out_of_range&)
	// {
	// 	return 0;
	// }
	// catch (const std::invalid_argument&)
	// {
	// 	return 0;
	// }
	if (checker < std::numeric_limits<int>::min() || checker > std::numeric_limits<int>::max())
		return 0;
	int value = static_cast<int>(checker);
	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: non-displayable" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	return 1;
}

bool isFloatOrDouble(const std::string &literal, bool l)
{
	size_t i = 0;
	size_t real_index = 0;
	bool dote = false;
	bool sign_f = false;
	bool digit = false;
	size_t len = literal.length();

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return 0;
	if (l && literal.back() == 'f')
	{
		sign_f = true;
		len--;
	}
	while (i < len)
	{
		if (isdigit(literal[i]))
			digit = true;
		if (literal[i] == '.' && dote == false)
		{
			dote = true;
			i++;
			continue;
			// if (real_index != 0 && isdigit(literal[i + 1]))
			// {
			// }
			// else
			// 	return 0;
		}
		if (!isdigit(literal[i]))
			return 0;
		i++;
		real_index++;
	}
	if (dote && sign_f && digit && l)
		return 1;
	if (dote && digit && !l)
		return 1;
	return 0;
}

void convertFloat(const std::string &literal)
{
	float value;

	try
	{
		value = std::stof(literal);
	}
	catch(...)
	{
		error();
	}
	// char
	if (value >= 0 && value <= 127 && std::isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value <= 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	// int
	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	// float
	std::cout << "float: " << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	// double
	double dvalue = static_cast<double>(value);
	std::cout << "double: " << dvalue;
	if (dvalue == static_cast<int>(dvalue))
		std::cout << ".0";
	std::cout << std::endl;
}

void convertDouble(const std::string &literal)
{
	double value;

    try
	{
        value = std::stod(literal);
    }
	catch (...)
	{
        return error();
    }

    // char
    if (value >= 0 && value <= 127 && std::isprint(static_cast<char>(value)))
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else if (value >= 0 && value <= 127)
        std::cout << "char: non-displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;

    // int
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // float (interesting math)
    if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
        std::cout << "float: " << static_cast<float>(value);
    else
        std::cout << "float: impossible";
    
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    // double
    std::cout << "double: " << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
		error();
	if (checkSpesialLiterals(literal))
		return ;
	if (convertChar(literal))
		return ;
	if (convertInt(literal))
		return ;
	if (isFloatOrDouble(literal, 1))
	{
		convertFloat(literal);
		return ;
	}
	if (isFloatOrDouble(literal, 0))
	{
		convertDouble(literal);
		return ;
	}
	error();
}
	// size_t i = 0;
	// if (literal[0] == '-' || literal[0] == '+')
	// 	i = 1;
	// if (literal.find('.') != std::string::npos || literal.back() == 'f')
	// {
	// 	return ;
	// }
	// else // int
	// {
	// 	bool isInt = true;
	// 	if (literal.length() == i)
	// 		isInt = false;
	// 	while (i < literal.length())
	// 	{
	// 		if (!isdigit(literal[i]))
	// 		{
	// 			isInt = false;
	// 			break;
	// 		}
	// 		i++;
	// 	}
	// 	if (isInt == true)
	// 	{
	// 		int value = std::stoi(literal);
	// 		if (isprint(value))
	// 			std::cout << "char: " << (char)value << std::endl;
	// 		else
	// 			std::cout << "char: non-displayable" << std::endl;
	// 		std::cout << "int: " << value << std::endl;
	// 		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	// 		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	// 		return ;
	// 	}
	// }