#include <iostream>

class Awesome {
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) {  std::cout << x << std::endl; return; }

template< typename T>
void iter(T* array, size_t u, void(*func)(T const &)){
	for(size_t i = 0; i < u;i++) {
		func(array[i]);
	}
}

int main() {
char	tab_char[] = {"abcdef"};
	int		tab_int[] = {1, 2, 3, 4};

int tab[] = { 0, 1, 2, 3, 4 };
Awesome tab2[5];

iter( tab, 5, print);
iter(tab_char, 6, print);
iter(tab_int, 4, print);
iter( tab2, 5, print);

return 0;
}
