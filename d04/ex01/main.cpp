#include <iostream>
#include "AWeapon.hpp"
// #include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main(){
	PlasmaRifle pr;
	PowerFist pf;
	
	pr.attack();
	pf.attack();
	return 0;
}
