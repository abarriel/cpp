#include <iostream>
#include <ctime>
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void randomChump(void) {
    srand (time(NULL));
    const std::string name[7] = { "allan", "michael", "ilan", "chamo", "superman", "nek", "dracula" };
    int random_number = std::rand(); 
    Zombie randomZombie(name[((random_number / 54) + (random_number / 23)) % 7], "random");
    randomZombie.announce();
}

Zombie *event(std::string type) {
    ZombieEvent event;

    event.setZombieType(type);
    return event.newZombie("Rick");
}

int main(void) {
    Zombie *bad, *good;
    std::string type[] = { "Bad", "Good" };

    bad = event(type[0]);
    bad->announce();
    delete bad;
    good = event(type[1]);
    good->announce();
    delete good;
    randomChump();
}
