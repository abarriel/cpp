#include "Pony.hpp"

void ponyOnTheHeap(void) 
{
    Pony *pony = new Pony();
    Pony::PonyCount(); // should be 1;
    delete pony;
}

void ponyOnTheStack(void)
{
    Pony pony;
    Pony::PonyCount(); // should be 1;
}

int main(void)
{
    Pony::PonyCount(); // should be 0;

    ponyOnTheStack();
    ponyOnTheHeap();

    Pony::PonyCount(); // should be 0;
    return 0;
}
