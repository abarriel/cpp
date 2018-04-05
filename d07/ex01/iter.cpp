#include <iostream>
template<typename T>
void print( T const & x ) { std::cout << x << std::endl; return; }
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

iter( tab, 5, print);
iter(tab_char, 6, print);
iter(tab_int, 4, print);

return 0;
}
