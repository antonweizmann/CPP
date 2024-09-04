#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class Array
{
	private:
		T* _data;		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& src);
		Array &operator=(const Array& src);
		~Array();
		unsigned int size() const;
		T &operator[](unsigned int n);
		const T &operator[](unsigned int n) const;

		class OutOfBounds: public std::exception
		{
			const char *what() const throw();
		};
};
# include "Array.tpp"
#endif
