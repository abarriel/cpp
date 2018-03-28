#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include <iostream>

class PlasmaRifle {
	public:
		/* Constructors - do not delete the default constructor (void) */
		PlasmaRifle(void);

		/* override */
		PlasmaRifle(PlasmaRifle const & src);
		PlasmaRifle& operator=(PlasmaRifle const & rhs);
	
		/* Destructors */
		~PlasmaRifle(void);
	private:
};

std::ostream& operator<<(std::ostream& out, PlasmaRifle const &i);

#endif
