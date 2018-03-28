#include <iostream>
#include <ctime>
#include "ZombieHorde.hpp"

void createHordes(int nb, std::string n) {
  ZombieHorde factory(nb, n);
  factory.announce();
}

void createHordesDefault(int nb) {
  ZombieHorde factory(nb);
  factory.announce();
}
int main(void) {
    createHordes(10, "walking dead");
    createHordes(1, "game of thrones");
    createHordesDefault(20);
    createHordes(0, "game of thrones");
    createHordes(-10, "game of thrones");
}
