#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

int		main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	std::string d(av[1]);
	if(d.find("f") != std::string::npos )
		d.replace(d.find("f"), 1, "");

	std::stringstream s(d);
	double a ;
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	s >> a;
	/* char */
	std::cout << "char: ";
	char c = static_cast<char>(a);
	if (s.fail() || a < 0 || a > 255) std::cout << "impossible" << std::endl;
	else if (c < 33 || c > 126) std::cout << "Non displayable" << std::endl;
	else std::cout << c << std::endl;

	/* int */
	std::cout << "int: ";
	if (s.fail()) std::cout << "nan" << std::endl;
	else if ( a != a || std::isinf(a)) std::cout << "impossible" << std::endl;
	else std::cout << static_cast<int>(a) << std::endl;

	/* float */
	std::cout << "float: ";
	try {
		float d = static_cast<float>(std::stof(av[1]));
		std::cout << d << "f" << std::endl;
	} catch (const std::invalid_argument& ia) {
		std::cout << "nanf" << std::endl;
	}

	/* double */
	std::cout << "double: ";
	if (std::isinf(atof(av[1]))) std::cout << atof(av[1]) << std::endl;
	else if (s.fail()) std::cout << "nan" << std::endl;
	else std::cout << a << std::endl;


	return 0;
}
