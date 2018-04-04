#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

struct Data {
	std::string s1;
	int n;
	std::string s2;
};
//  reinterpret_cast.
void	*serialize(void) {
	static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string s1(8, 'x');
	std::string s2(8, 'x');
	void *ret = operator new (sizeof(int) + (sizeof(s1) * 2));	
	Data *r = reinterpret_cast<Data*>(ret);
	for (int i = 0; i < 8; i++) {
		s1[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
		s2[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	r->s1 = s1;
	r->s2 = s2;
	r->n = rand();
	return ret;
}

Data *deserialize(void *raw) {
	return reinterpret_cast<Data *>(raw);
}

int		main(void)
{
	void *raw;
	Data *data;

	srand((time)(NULL));
	raw = serialize();
	data = deserialize(raw);
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;
	return 0;
}
