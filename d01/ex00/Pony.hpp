#ifndef PONY_HPP
# define PONY_HPP
#include <iostream>

class Pony {
    public:
        Pony(void);
        ~Pony(void);
        static int PonyCount(void);
        void eatHoney(void);
        bool isStarving;
        void throwHoney(void);
    private:
        static int _totalPony;
};
#endif
