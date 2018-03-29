#include "Fixed.class.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main(int ac, char **av ) {
	size_t ri;
	float res;
	float rf;
	std::string subs;
	std::string tmp;

	res = 0.0;
	rf = 0.0;
	if(ac != 2 || !av[1])
	{
		std::cout << "wrong argument" << std::endl;
	}
	std::istringstream iss(av[1]);
	std::string s(av[1]);
	ri = std::count(s.begin(), s.end(), '+') + std::count(s.begin(), s.end(), '-');
	ri += std::count(s.begin(), s.end(), '/') + std::count(s.begin(), s.end(), '*');
	if (!ri)
		{
			std::cout << av[1] << std::endl;
			return 0;
		}
    do
    {
    	iss >> subs;
		std::stringstream ss(subs);
		if ((ss >> rf))  {
			if(!iss.eof() && tmp.empty())
				res = Fixed(rf).toFloat();
			if (tmp == "+")
				res += Fixed(rf).toFloat();
			if (tmp == "-")
				res -= Fixed(rf).toFloat();
			if (tmp == "*")
				res *= Fixed(rf).toFloat();
			if (tmp == "/")
				res /= Fixed(rf).toFloat();
			tmp.clear();
		} else {
			tmp = ss.str();
		}
    } while (iss);
	std::cout << res << std::endl;
    return 0;
}
