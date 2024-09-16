#include "PmergeMe.hpp"

static void parse_input(char **argv)
{
    _start_time = std::chrono::high_resolution_clock::now();
    try {
        for (int i = 1; argv[i] != NULL; i++)
        {
            int tmp = std::stoi(argv[i]);
            if (tmp < 0)
                throw std::runtime_error("Input should only include positive numbers");
            if (std::find(_container.begin(), _container.end(), tmp) != _container.end())
                throw std::runtime_error("Input should not include duplicate numbers");
            _container.push_back(tmp);
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

// Default constructor
template <typename TContainer>
PmergeMe<TContainer>::PmergeMe(void)
{
    std::cout << "PmergeMe Default constructor called" << std::endl;
    return ;
}

template <typename TContainer>
PmergeMe<TContainer>::PmergeMe(char **argv)
{
    std::cout << "PmergeMe input constructor called" << std::endl;
    if (argv[1] == NULL)
        throw std::runtime_error("Input empty");
    parse_input(argv);
    return ;
}

// Copy constructor
template <typename TContainer>
PmergeMe<TContainer>::PmergeMe(const PmergeMe<TContainer> &src)
{
    std::cout << "PmergeMe Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
template <typename TContainer>
PmergeMe<TContainer> &PmergeMe<TContainer>::operator=(const PmergeMe<TContainer> &src)
{
    std::cout << "PmergeMe Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
template <typename TContainer>
PmergeMe<TContainer>::~PmergeMe(void)
{
    std::cout << "PmergeMe Destructor called" << std::endl;
    return ;
}

template <typename TContainer>
typename TContainer::iterator PmergeMe<TContainer>::binary_search(typename TContainer::iterator start, typename TContainer::iterator end, const typename TContainer::value_type &value)
{
    int low = 0;
    int high = end - start;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (start[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return  (start + low);
}

void deque_ford_johnson(std::deque<int> &container)
{
    std::deque<int> sorted;
    container.split(sorted);

}

void list_ford_johnson(std::list<int> &container)
{ 
    list.sort();
}
