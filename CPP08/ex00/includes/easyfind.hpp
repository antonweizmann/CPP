#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
class NotFoundExeption : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Not Found");
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator res;

	res = std::find(container.begin(), container.end(), n);
	if (res == container.end())
		throw NotFoundExeption();
	return res;
}
#endif
