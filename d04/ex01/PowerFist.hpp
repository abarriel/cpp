#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <iostream>

class PowerFist {
	public:
		/* Constructors - do not delete the default constructor (void) */
		PowerFist(void);

		/* override */
		PowerFist(PowerFist const & src);
		PowerFist& operator=(PowerFist const & rhs);
	
		/* Destructors */
		~PowerFist(void);
	private:
};

std::ostream& operator<<(std::ostream& out, PowerFist const &i);

#endif
