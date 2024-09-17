# pragma once

# include "PmergeMe.hpp"
template <typename TContainer>
void print_container(TContainer &container)
{
    for (typename TContainer::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename TContainer>
void insert_sorted(TContainer &container, const typename TContainer::value_type &value)
{
    auto location = ft_binary_search(container, value);
    container.insert(location, value);
}

template <typename TContainer>
void PmergeMe<TContainer>::merge_sort(void (*sort_func)(TContainer &))
{
    std::cout << "Before:\t"; 
    print_container(_container);
    sort_func(_container);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::cout << "After:\t";
    print_container(_container);
    std::cout << "Time:\t" << std::chrono::duration_cast<std::chrono::microseconds>(end_time - _start_time).count() << "µs" << std::endl;
}

template <typename TContainer>
void split(TContainer &container, TContainer &sorted)
{
    if (container.size() == 0)
        throw std::runtime_error("Container is empty");
    auto it = container.begin();
    while (it != container.end())
    {  
        if (std::next(it) != container.end())
        {
            auto next_it = std::next(it);
            if (*it > *next_it)
            {
                insert_sorted(sorted, *it);
                it = container.erase(it);
            }
            else
            {
                insert_sorted(sorted, *next_it);
                it = container.erase(next_it);
            }
        }
        else
        {
            insert_sorted(sorted, *it);
            it = container.erase(it);
        // std::advance(it, 2);
        }
    }
}

template <typename TContainer>
typename TContainer::iterator ft_binary_search(TContainer &container, const typename TContainer::value_type &value)
{
    auto low = container.begin();
    auto high = container.end();
    while (low != high)
    {
        auto mid = low;
        std::advance(mid, std::distance(low, high) / 2);
        if (*mid < value)
            low = std::next(mid);
        else
            high = mid;
    }
    return  (low);
}


template <typename TContainer>
PmergeMe<TContainer>::PmergeMe(char **argv)
{
    std::cout << "PmergeMe input constructor called" << std::endl;
    if (argv[1] == NULL)
        throw std::runtime_error("Input empty");
    parse_input(argv);
  _start_time = std::chrono::high_resolution_clock::now();
 
    return ;
}


template <typename TContainer>
void PmergeMe<TContainer>::parse_input(char **argv)
{
    try {
        for (int i = 1; argv[i] != NULL; i++)
        {
            int tmp = std::stoi(argv[i]);
            if (tmp < 0)
                throw std::runtime_error("Input should only include positive numbers");
            // if (std::find(_container.begin(), _container.end(), tmp) != _container.end())
            //     throw std::runtime_error("Input should not include duplicate numbers");
            _container.push_back(tmp);
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "Invalid Input: " << e.what() << std::endl;
        exit(1);
    }
}

