#ifndef IASTEROID_HPP
# define IASTEROID_HPP
# include <iostream>

class IAsteroid {
	public:
		virtual ~IAsteroid() {}
		virtual std::string beMined() const = 0;
// [...]
		virtual std::string getName() const = 0;
};

std::ostream& operator<<(std::ostream& out, IAsteroid const &i);

#endif
