#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){};
		MutantStack(MutantStack const &src) : std::stack<T>(src){};
		MutantStack &operator=(MutantStack const &src){
			if (this != &src)
				std::stack<T>::operator=(src);
			return (*this);
		}
		~MutantStack(){};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin(){
			return (std::stack<T>::c.begin());
		};
		iterator end(){
			return (std::stack<T>::c.end());
		};
		reverse_iterator rbegin(){
			return (std::stack<T>::c.rbegin());
		};
		reverse_iterator rend(){
			return (std::stack<T>::c.rend());
		};
		const_iterator cbegin(){
			return (std::stack<T>::c.cbegin());
		};
		const_iterator cend(){
			return (std::stack<T>::c.cend());
		};
		const_reverse_iterator crbegin(){
			return (std::stack<T>::c.crbegin());
		};
		const_reverse_iterator crend(){
			return (std::stack<T>::c.crend());
		};
};

#endif
