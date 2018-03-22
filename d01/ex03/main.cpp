#include <iostream>
#include <ctime>
#include "ZombieHorde.hpp"

void createHordes(int nb, std::string n) {
  ZombieHorde factory(nb, n);
  factory.announce();
}

int main(void) {
    createHordes(10, "walking dead");
    createHordes(10000, "game of thrones");
}