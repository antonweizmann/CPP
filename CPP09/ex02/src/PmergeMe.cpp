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

template <typename TContainer>
void PmergeMe<TContainer>::split(TContainer &sorted)
{
    int pair1 = 0;
    int pair2 = 0;
    if (_container.size() == 0)
        throw std::runtime_error("Container is empty");
    TContainer::iterator it = _container.begin();
    while (it <= _container.end() && it + 1 <= _container.end())
    {
        pair1 = _container.it;
        pair2 = _container.it + 1;
        if (pair1 > pair2)
        {
            sorted.insert(binary_search(sorted.begin(), sorted.end(), pair1), pair1);
            _container.erase(pair1);
        }
        else
        {
            sorted.insert(binary_search(sorted.begin(), sorted.end(), pair2), pair2);
            _container.erase(pair2);
        }
        it +=2;
    }
    if (it == _container.end())
        sorted.insert(binary_search(sorted.begin(), sorted.end(), _container[it]), _container[it]);
}

size_t PmergeMe<TContainer>::generateJacobsthal(void)
{
    static size_t jacobsthal1 = 0;
    static size_t jacobsthal2 = 1;
    
    return ();
}

void deque_ford_johnson(PmergeMe<std::deque<int>> &container)
{
    std::deque<int> sorted;
    container.split(sorted);
    if (sorted.size() == 0)
        throw std::runtime_error("Container is empty");
    sort(sorted, container);

}

void list_ford_johnson(std::list<int> &container)
{ 
    list.sort();
}
