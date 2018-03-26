#include <iostream>
#include "Logger.hpp"

int main(void) {
    Logger file("nodejs.log");
    std::string rep;
    std::string fl;
    while (std::cout << "append to a file ? (yes or no): ") {
        std::cin >> rep;
        if (rep == "yes")
            fl = "file";
        else if (rep == "no")
            fl = "log";
        else continue;
        std::cout << "log to write: ";
        std::cin >> rep;
        file.log(fl, rep);
        // std::cout << rep << std::endl;

    }
    return (0);
}