#include <iostream>

template<typename T>
T const & max(T const & x, T const & y) { return ( (y >= x) ? y : x ); }
template<typename T>
T const & min(T const & x, T const & y) { return ( (y <= x) ? y : x ); }

template<typename T>
void swap(T& x, T & y) { 
	T tmp;

	tmp = y;
	y = x;
	x = tmp;
}


int main(void) {
	int i,i1,i2;
	float f,f1,f2;
	char c,c1,c2;

	i1 = 10;
	i2 = 5;
	f1 = 5.0;
	f2 = 6.0;
	c1 = 'a';
	c2 = 'b';
	
	std::cout << "1:" << i1 <<  " - 2:" << i2 << std::endl;
	swap(i1, i2);
	std::cout << "1:" << i1 <<  " - 2:" << i2 << std::endl << std::endl;

	std::cout << "1:" << f1 <<  " - 2:" << f2 << std::endl;
	swap(f1, f2);
	std::cout << "1:" << f1 <<  " - 2:" << f2 << std::endl << std::endl;

	std::cout << "1:" << c1 <<  " - 2:" << c2 << std::endl;
	swap(c1, c2);
	std::cout << "1:" << c1 <<  " - 2:" << c2 << std::endl << std::endl;

	i = max(1, 2);
	std::cout << i << std::endl;
	i = min(1, 2);
	std::cout << i << std::endl;

	f = max(1.5f, 2.5f);
	std::cout << f << std::endl;
	f = min(1.5f, 0.0f);
	std::cout << f << std::endl;

	c = max('a', 'b');
	std::cout << c << std::endl;
	c = min('a', 'b');
	std::cout << c << std::endl;
	return 0;
}
