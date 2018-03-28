#include <iostream>
#include <fstream>

int main(int ac, char **av) {
    std::string buff;

	if (ac == 1)
    	while (1)
		{
			buff.clear();
			std::cin >> buff;
			std::cout << buff << std::endl;
            if (std::cin.eof())
                return 0;
		}
	for (int i = 1; i < ac; i++) {
        std::ifstream ifs(av[i]);
        if (!ifs.is_open())
        {
            if (i != 1)
                std::cout << std::endl;
            std::cout << "cat: " << av[i]<< ": " << strerror(errno) << std::endl;
            if (i == ac)
                return 1;
            continue;
        }
        std::cout << ifs.rdbuf();
	}
    return 0;
}
