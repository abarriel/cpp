#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
#include <iostream>
#include "Zombie.hpp"

class ZombieHorde {
  public:
        ZombieHorde(int nb);
        ZombieHorde(int nb, std::string horde);
        ~ZombieHorde(void);
        int nb_zombie;
        void announce(void) const;
  private:
		Zombie *hordes;
};

#endif
