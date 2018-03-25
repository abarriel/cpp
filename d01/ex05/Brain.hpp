#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
    public:
        Brain(void);
        ~Brain(void);
        int qi;
        int stupidity;
        const Brain *identify(void) const;
};
#endif