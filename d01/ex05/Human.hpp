#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <iostream>
#include "Brain.hpp"

class Human {
    public:
        Human(void);
        ~Human(void);
        const Brain brain;
        const Brain	&getBrain(void) const;
        const Brain *identify(void) const;
};
#endif