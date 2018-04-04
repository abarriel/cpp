#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};
//  reinterpret_cast.
void	*serialize(void) {
	static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	srand((unsigned)NULL);
	void *ret = ::operator new (sizeof(std::string) * 2 + sizeof(int));
	// reinterpret_cast<std::string>(*ret);
	std::string s1[8] = {};
	std::string s2[8] = {};
	int n;
	n = rand();
	for (int i = 0; i < 8; i++) {
		s1[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
		s2[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	return ret;
}

Data *deserialize(void *raw) {
	return reinterpret_cast<Data *>(raw);
}

int		main(void)
{
	void *raw;
	Data *data;

	raw = serialize();
	data = deserialize(raw);
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;
	return 0;
}
