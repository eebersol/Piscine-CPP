# include <stdexcept>
# include <iostream>
# include <string>

template <typename T>
class Array {
	private:
		T				*_content;
		unsigned int	_size;

	public:
		Array<T>(): _content(new T[0]), _size(0) {}

		Array<T>(unsigned int n){
			_content =  new T[n];
			_size = n;
		}

		Array<T>( Array<T> const & src) {
			*this = src;
		}

		~Array<T>() {
			if (_content != nullptr) {
				delete [] _content;
			}
		}

		Array<T> &			operator=( Array<T> const & src ) {
			if (this == &src)
				return (*this);
			this->_content = new T[src.size()];
			this->_size = src.size();
			for (unsigned int i = 0; i < src.size(); i++) {
				this->_content[i] = src[i];
			}
			return (*this);
		}

		T &			operator[](unsigned int i) const {
			if (i >= _size ) {
				throw Array::OutOfLimit();
			}
			return _content[i];
		}

		class OutOfLimit: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "You are out of limits";
				}
		};

		unsigned int size() const {
			return _size;
		}
};