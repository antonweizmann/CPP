
#include "iter.hpp"

// #include <cctype>

// void ft_tolower(char &arr)
// {
// 	arr = std::tolower(arr);
// }

// void ft_toupper(const char &arr)
// {
// 	(void) arr;
// 	// arr = std::toupper(arr);
// }

// int main()
// {
// 	char a[] = {'A', 'B', 'C'};

// 	std::cout << "Original:" <<
// 	"\n\ta[0]: " << a[0] <<
// 	"\n\ta[1]: " << a[1] <<
// 	"\n\ta[2]: " << a[2] <<
// 	std::endl << std::endl;

// 	::iter(a, 3, ft_tolower);

// 	std::cout << "Changed:" <<
// 	"\n\ta[0]: " << a[0] <<
// 	"\n\ta[1]: " << a[1] <<
// 	"\n\ta[2]: " << a[2] <<
// 	std::endl << std::endl;

// 	::iter(a, 2, ft_toupper);

// 	std::cout << "Changed:" <<
// 	"\n\ta[0]: " << a[0] <<
// 	"\n\ta[1]: " << a[1] <<
// 	"\n\ta[2]: " << a[2] <<
// 	std::endl << std::endl;
// }

class Awesome
{
public:
    Awesome(void) : _n(42) { return; }
    int get( void ) const { return this->_n; }
private:
    int _n;
};

std::ostream& operator<<(std::ostream &o, Awesome const &rhs) { o << rhs.get(); return o; }

template<typename T>
void print( T const &x ) { std::cout << x << std::endl; return; }

int main()
{
    int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
    Awesome tab2[5];

    iter( tab, 5, print );
    iter( tab2, 5, print );

    return 0;
}
