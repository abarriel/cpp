#include <iostream>
#include "Human.hpp"

int main(int ac, char **av) {
    Human h;
    
    if (ac != 3)
    {
        std::cout << "wrong argument" << std::endl;
        return (0);
    }
    h.action(av[1], av[2]);
    return (0);
}