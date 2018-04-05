#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
#include <vector>
class span {
	private:
		span(void);
	protected:
		std::vector<int> _n;
		unsigned int N;
	public:
		span(unsigned int);
		void addNumber(int);
		int shortestSpan();
		int longestSpan();
		std::vector<int>& getN();
		/* override */
		span(span const & src);
		span& operator=(span const & rhs);

		/* Destructors */
		virtual ~span(void);
};

std::ostream& operator<<(std::ostream& out, span const &i);

#endif
