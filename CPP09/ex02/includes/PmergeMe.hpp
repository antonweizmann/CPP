#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <chrono>
# include <deque>
# include <list>
# include <algorithm>
# include <iterator>

# define std::chrono::high_resolution_clock::now() time_now;
template <typename TContainer>
class PmergeMe
{
    private:
        TContainer _container;
        auto _start_time;
    public:
        //Constructers and Destructers
        PmergeMe(void) =  delete;
        PmergeMe(char **argv);
        PmergeMe(const PmergeMe& src)=  delete;
        PmergeMe &operator=(const PmergeMe &src)=  delete;
        ~PmergeMe() = default;

        //Getters and Setters

        //Functions
        typename TContainer::iterator binary_search(typename TContainer::iterator start, typename TContainer::iterator end, const typename TContainer::value_type &value)
        void split(TContainer &sorted)
        //Execptions
};
void deque_ford_johnson(std::deque<int> &deque);
void list_ford_johnson(std::list<int> &list);

#endif

