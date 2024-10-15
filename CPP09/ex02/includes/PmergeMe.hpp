#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <chrono>
# include <deque>
# include <list>
# include <algorithm>
# include <iterator>
# include <set>
template <typename TContainer>
class PmergeMe
{
    private:
        TContainer _container;
        std::chrono::time_point<std::chrono::high_resolution_clock> _start_time;
    public:
        //Constructers and Destructers
        PmergeMe(void) =  delete;
        PmergeMe(char **argv);
        PmergeMe(const PmergeMe& src)=  delete;
        PmergeMe &operator=(const PmergeMe &src)=  delete;
        ~PmergeMe() = default;

        //Getters and Setters

        //Functions
        void parse_input(char **argv);
        void merge_sort(void (*sort_func)(TContainer &));
        //Execptions
};


template <typename TContainer>
typename TContainer::iterator ft_binary_search(TContainer &container, const typename TContainer::value_type &value);

template <typename TContainer>
void split(TContainer &container, TContainer &sorted);

template <typename TContainer>
void insert_sorted(TContainer &container, const typename TContainer::value_type &value);

template <typename TContainer>
void print_container(TContainer &container);

size_t generateJacobsthal(void);
void deque_ford_johnson(std::deque<int> &container);
void list_ford_johnson(std::list<int> &container);

# include "PmergeMe.tpp"
#endif

