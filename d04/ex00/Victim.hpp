// Victim
#ifndef VICTIM_HPP
#define VICTIM_HPP
#include <iostream>

class Victim {
public:
    Victim(void); // Canonical constructor default (void!!!!!!)
    Victim(std::string name);
    Victim(Victim const & src); // Canonical
    ~Victim(void); // Canonical
    Victim& operator=(Victim const & rhs); // Canonical
    std::string getName(void) const;
private:
    std::string name;
};
std::ostream& operator<<(std::ostream& o, Victim const &i);
#endif
