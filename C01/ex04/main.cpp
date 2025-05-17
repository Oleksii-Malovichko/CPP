#include "File.hpp"

std::string replaceAll(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result.append(line, pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result.append(line, pos, std::string::npos);
	return result;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Expected 3 arguments: <namefile> <str1> <str2>" << std::endl;
		return 1;
	}
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string newFile = fileName + ".replace";
	if (fileName.empty() || fileName == "\n")
	{
		std::cerr << "Error: filename must not be empty" << std::endl;
		return 1;
	}
	if ((s1.empty() || s1 == "\n" ) || (s2.empty() || s2 == "\n"))
	{
		std::cerr << "Error: s1 and s2 must not be empty" << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Could not open file for reading" << std::endl;
		return 1;
	}
	std::ofstream outputFile(newFile);
	if (!outputFile.is_open())
	{
		std::cerr << "Could not open file for writing" << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		outputFile << replaceAll(line, s1, s2);
		if (!inputFile.eof())
			outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}
