#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie {
  public:
        Zombie(void);
        ~Zombie(void);
        void initZombie(std::string name, std::string type);
        std::string name;
        std::string type;    
        void announce(void) const;
};
#endif
