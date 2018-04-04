#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	switch (rand() % 3) {
		case 0: 
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return new A;
	}
}
void identify_from_pointer(Base *p) {
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if(a) std::cout << "A" << std::endl;
	if(b) std::cout << "B" << std::endl;
	if(c) std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
	} catch (std::bad_cast &a) {
		try {
			B &b = dynamic_cast<B&>(p);
			static_cast<void>(b);
			std::cout << "B" << std::endl;
		} catch (std::bad_cast &b) {
			try {
				C &c = dynamic_cast<C&>(p);
				static_cast<void>(c);
				std::cout << "C" << std::endl;
			} catch (std::bad_cast &a) {
				;
			}
		}		
	}
}
int main() {
	srand(time(NULL));
	Base *b;
	b = generate();
	identify_from_pointer(b);
	identify_from_reference(*b);
	return 0;
}
