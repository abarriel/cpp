#include <iostream>
#include <fstream>

void    err(int i, std::string str, int ext = 0) {
    std::string err[] = { "Failed to open file", "failed bad" , "wrong argument"};
    std::cout << err[i] << ": " << str << std::endl;
    if (ext)
        exit(0);
    return;
}

void replaceAll(std::string& file, const std::string s1, const std::string s2) {
    size_t pos = 0;

    if (s1 == "")
        return ;
    // std::cout << s1;
    while((pos = file.find(s1, pos)) != std::string::npos)
    {
        file.replace(pos, s1.length(), s2);
        pos += s2.length();
    }
}

int main(int ac, char **av){
    std::ifstream ifs(av[1]);
    std::string line;
    std::string file;

    if (ac != 4)
        err(2, std::to_string(ac),  1);
    if (!ifs.is_open())
        err(0, ac < 2 ? "" : av[1] , 1);
    std::ofstream ofs((std::string)av[1] + ".replace");
    if (!ofs.is_open())
        err(1, (std::string)av[1] + ".replace" , 1);
    while (std::getline(ifs, line) && !ifs.eof())
        file += line + "\n";
    file += line;
	if (ifs.bad() || !ifs.eof())
		err(1, av[1], 1);
    // std::cout << file; // better to put everything in a file, otherwise it's gonna create the output without checking the eof
    replaceAll(file, (std::string)av[2], (std::string)av[3]);
    // std::cout << std::endl;
    ofs << file; // better to put everything in a file, otherwise it's gonna create the output without checking the eof
    ifs.close();
    ofs.close();
    return 0;
}