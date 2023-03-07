#include <iostream>
#include <fstream>

const int MAX_SIZE = 1000;

int main()
{
	std::ifstream file("task1.cpp");

	if (!file.is_open())
	{
		std::cout << "Error";
		return -1;
	}

	char buffer[MAX_SIZE];

	while (!file.eof())
	{
		file.getline(buffer, MAX_SIZE);

		std::cout << buffer << std::endl;
	}

	file.close();

}
