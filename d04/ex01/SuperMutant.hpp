#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include <iostream>

class SuperMutant {
	public:
		/* Constructors - do not delete the default constructor (void) */
		SuperMutant(void);

		/* override */
		SuperMutant(SuperMutant const & src);
		SuperMutant& operator=(SuperMutant const & rhs);
	
		/* Destructors */
		~SuperMutant(void);
	private:
};

std::ostream& operator<<(std::ostream& out, SuperMutant const &i);

#endif
