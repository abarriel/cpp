#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include <iostream>

class RadScorpion {
	public:
		/* Constructors - do not delete the default constructor (void) */
		RadScorpion(void);

		/* override */
		RadScorpion(RadScorpion const & src);
		RadScorpion& operator=(RadScorpion const & rhs);
	
		/* Destructors */
		~RadScorpion(void);
	private:
};

std::ostream& operator<<(std::ostream& out, RadScorpion const &i);

#endif
