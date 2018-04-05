#include "span.hpp"
#include <algorithm>
#include <vector>
/* Constructors */
span::span(unsigned int n): N(n) {
	std::cout << "(span) default constructor called" << std::endl;
    return ;
}

void span::addNumber(int ne) {
	if (this->_n.size() == this->N)
		throw std::bad_exception();
	this->_n.push_back(ne);
	std::sort(this->_n.begin(), this->_n.end());
}

int span::shortestSpan() {
	if(this->_n.size() < 2)
		throw std::bad_exception();
	unsigned int small = -1;
	unsigned int tmp;
	for(std::vector<int>::iterator it = this->_n.begin(); it != this->_n.end(); ++it) {
		if ((it + 1) == this->_n.end())
			break;
		tmp = (*(it + 1) - *it);
		if(tmp < small)
			small =tmp;
	}
	return small;
}

std::vector<int>& span::getN() {
	return this->_n;
}

int span::longestSpan() {
	if(this->_n.size() < 2)
		throw std::bad_exception();
	return(*std::max_element(this->_n.begin(), this->_n.end()) -  *std::min_element(this->_n.begin(), this->_n.end()));
}

span& span::operator=(span const & rhs) {
	std::cout << "(span) assignation operator called";
    this->_n.assign(rhs._n.begin(), rhs._n.end());
	return *this;
}

std::ostream& operator<<(std::ostream& out, span const &i) {
	out << "(span) WARNING ! ADD A LOGIC <<" << std::endl;
	static_cast<void>(i);
	return out;
}

span::span(span const & src) {
	std::cout << "(span) copy constructor called" << std::endl;
	*this = src;
    return ;
}

/* Destructors */
span::~span(void) {
	std::cout << "(span) destructor span called" << std::endl;
    return ;
}
