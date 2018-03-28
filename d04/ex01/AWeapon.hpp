#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon {
	public:
		/* Constructors - do not delete the default constructor (void) */
		AWeapon(void);

		/* override */
		AWeapon(AWeapon const & src);
		AWeapon& operator=(AWeapon const & rhs);
	
		/* Destructors */
		~AWeapon(void);
	private:
};

std::ostream& operator<<(std::ostream& out, AWeapon const &i);

#endif
