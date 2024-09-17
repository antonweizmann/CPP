#include "PmergeMe.hpp"


size_t generateJacobsthal(int i)
{
    static size_t jacobsthal1 = 0;
    static size_t jacobsthal2 = 1;
    if (i == 0)
    {
        jacobsthal1 = 0;
        jacobsthal2 = 1;
    }
    size_t result = jacobsthal1 + 2 * jacobsthal2;
    jacobsthal1 = jacobsthal2;
    jacobsthal2 = result;
    return (result);
}

void deque_ford_johnson(std::deque<int> &container)
{
    std::deque<int> sorted;
    split(container, sorted);
    if (sorted.size() == 0)
        throw std::runtime_error("Container is empty");
    size_t jacobsthal = generateJacobsthal(0);
    for (size_t i = 0;(jacobsthal - i) < container.size(); i++)
    {
        auto jacobsthal_it = container.begin() + jacobsthal - i;
        insert_sorted(sorted, *jacobsthal_it);
        container.erase(jacobsthal_it);
        jacobsthal = generateJacobsthal(1);
    }
    for (auto it = container.begin(); it != container.end(); it++)
        insert_sorted(sorted, *it);
    container = sorted;
}

void list_ford_johnson(std::list<int> &container)
{ 
    std::list<int> sorted;
    split(container, sorted);
    if (sorted.size() == 0)
        throw std::runtime_error("Container is empty");
    size_t jacobsthal = generateJacobsthal(0);
    for (size_t i = 0;(jacobsthal - i) < container.size(); i++)
    {
        auto jacobsthal_it = container.begin();
        std::advance(jacobsthal_it, jacobsthal - i);
        insert_sorted(sorted, *jacobsthal_it);
        container.erase(jacobsthal_it);
        jacobsthal = generateJacobsthal(1);
    }
    for (auto it = container.begin(); it != container.end(); it++)
        insert_sorted(sorted, *it);
    container = sorted;
}
