#include "span.hpp"
#include <algorithm>
#include <ctime>
#include <vector>

struct Generator {
    Generator() : m_value( 0 ) { }
    int operator()() { return m_value++; }
    int m_value;
};
int main() {
	try {
	span a(2000);
	int i = 0;
    srand (time(NULL));
	while(i < 2000) {
		a.addNumber(rand());
		i++;
	}
	std::cout << a.shortestSpan() << std::endl;
	std::cout << a.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "not good range" << std::endl;
	}
}
