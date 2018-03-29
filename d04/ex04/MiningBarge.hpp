#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP
# include <iostream>

class MiningBarge {
	private:
	protected:
	public:
		/* Constructors - do not delete the default constructor (void) */
		MiningBarge(void);

		/* function members (or methods) */

		/* override */
		MiningBarge(MiningBarge const & src);
		MiningBarge& operator=(MiningBarge const & rhs);

		/* Destructors */
		~MiningBarge(void);
};

std::ostream& operator<<(std::ostream& out, MiningBarge const &i);

#endif
