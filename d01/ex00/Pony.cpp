#include <iostream>
#include "Pony.hpp"

int Pony::_totalPony = 0;

Pony::Pony(void) {
    std::cout << "Pony is here and he is starving! (called)" << std::endl;
    this->isStarving = true;
    Pony::_totalPony += 1;    
}

void Pony::eatHoney(void) {
    std::cout << "Pony eat honey and he won't starve" << std::endl;
    this->isStarving = false;
}

void Pony::throwHoney(void) {
    std::cout << "Pony doesn't feel well and he throw up" << std::endl;
    this->isStarving = true;
}

int Pony::PonyCount(void) {
    std::cout << Pony::_totalPony << " Pony in the hayfield" << std::endl;
    return Pony::_totalPony;
}

Pony::~Pony(void) {
    std::cout << "Pony is gone ! (delete)" << std::endl;
    Pony::_totalPony -= 1;
}