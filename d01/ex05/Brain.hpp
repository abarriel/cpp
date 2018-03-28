#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
    public:
        Brain(void);
        ~Brain(void);
        const Brain *identify(void) const;
    private:
        int qi;
        int stupidity;
};
#endif
