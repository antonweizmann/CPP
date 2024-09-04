#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _size(0), _data(NULL)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(new T[n])
{}

template <typename T>
Array<T>::Array(const Array& src) : _size(src._size), _data(new T[src._size])
{
	for (unsigned int i = 0; i < src._size; i++)
		_data[i] = src._data[i];
}


template <typename T>
Array<T>& Array<T>::operator=(const Array& src)
{
	if (!this == &src)
	{
		delete [] _data;
		_size = src._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < src._size; i++)
			_data[i] = src._data[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete [] _data;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw OutOfBounds();
	return _data[n];
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const
{
	if (n >= _size)
		throw OutOfBounds();
	return _data[n];
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return "Index out of bounds";
}
#endif
