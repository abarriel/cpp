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
void	*serialize(void) {
	static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	void *ret = operator new(sizeof(int) + sizeof(std::string) * 2);
	bzero(ret, 20);
	for (int i = 0; i < 8; i++) reinterpret_cast<char*>(ret)[i]  = alphanum[rand() % (sizeof(alphanum) - 1)];
	reinterpret_cast<int*>(ret)[8] = rand();
	for (int i = 12; i < 20; i++) reinterpret_cast<char*>(ret)[i]  = alphanum[(rand() % (sizeof(alphanum) - 1))];
	return ret;
}

Data *deserialize(void *raw) {
	Data* data = new Data();
	for (int i = 0; i < 8; i++) data->s1.push_back(reinterpret_cast<char*>(raw)[i]);
	data->n = reinterpret_cast<int*>(raw)[8];
	for (int i = 12; i < 20; i++) data->s2.push_back(reinterpret_cast<char*>(raw)[i]);
	return data;
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
