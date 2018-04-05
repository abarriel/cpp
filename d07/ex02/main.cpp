#include "Array.hpp"

int	main(void)
{
	Array<int> tab_int(5);
	Array<int> tab_int2(10);

	std::cout << "print list" << std::endl;
	for (size_t i = 0; i < tab_int.size(); i++)
		std::cout << i << " --> " << tab_int[i] << std::endl;

	std::cout << "fill list" << std::endl;
	for (size_t i = 0; i < tab_int.size(); i++)
		tab_int[i] = i;

	std::cout << "print list" << std::endl;
	for (size_t i = 0; i < tab_int.size(); i++)
		std::cout << i << " --> " << tab_int[i] << std::endl;

	std::cout << "fill list tab2" << std::endl;
	for (size_t i = 0; i < tab_int2.size(); i++)
		tab_int2[i] = i * 2;

	std::cout << "print list tab2" << std::endl;
	for (size_t i = 0; i < tab_int2.size(); i++)
		std::cout << i << " --> " << tab_int2[i] << std::endl;

	std::cout << "tab = tab2" << std::endl;
	tab_int = tab_int2;


	std::cout << "print list" << std::endl;
	for (size_t i = 0; i < tab_int.size(); i++)
		std::cout << i << " --> " << tab_int[i] << std::endl;

	std::cout << "--------------------------" << std::endl;

	// Array<std::string> tab_str(5);

	// std::cout << "print list" << std::endl;
	// for (size_t i = 0; i < tab_str.size(); i++)
	// 	std::cout << i << " --> " << tab_str[i] << std::endl;

	// std::cout << "fill list" << std::endl;
	// for (size_t i = 0; i < tab_str.size(); i++)
	// 	tab_str[i] = "fleur";

	// std::cout << "print list" << std::endl;
	// for (size_t i = 0; i < tab_str.size(); i++)
	// 	std::cout << i << " --> " << tab_str[i] << std::endl;
	return (0);
}
