#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int main(int ac, char **av)
{
	if (ac != 2) return 0;
	// double d;

	// std::string input = av[1];
	// std::stringstream ss(input);
	// double ld = 42.00;
	// ss >> ld;
	std::cout << std::atof(av[1]) << std::endl;
	return 0;
}
