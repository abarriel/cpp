#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
template<typename T>
class Array {
	private:
		T *_array;
		unsigned int _size;
	public:
		Array<T>(void): _array(NULL), _size(0) { return ; }
		/* Constructors - do not delete the default constructor (void) */
		Array<T>(unsigned int n): _array(new T[n]()), _size(n) { return ;}
		/* override */
		Array<T>(Array<T> const & src) { *this = src; }
		Array<T>& operator=(Array<T> const & rhs) {
			if (this->_size != rhs.size()) {
				delete [] this->_array;
				this->_array = new T[rhs.size()]();
			}
			this->_size = rhs.size();
			for(unsigned int i = 0; i < this->_size; i++) {
				this->_array[i] = rhs[i];
			}
			return *this;
		}
		T& operator[](unsigned int idx) const {
			if(idx >= this->_size)
				throw std::exception();
			return this->_array[idx];
		}
	
		unsigned int size() const { return this->_size; }
		/* Destructors */
		virtual ~Array<T>(void) {return;}
};
// template<typename T>
// std::ostream& operator<<(std::ostream& out, Array< T > const &i);

#endif
