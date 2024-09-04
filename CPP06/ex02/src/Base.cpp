#include "Base.hpp"

// Destructor
Base::~Base(void)
{
    std::cout << "Base Destructor called" << std::endl;
    return ;
}
int seed = 0;
Base *generate(void)
{
    srand(time(0) + seed++);
    int rnd = rand() % 3;
    // Generate and print a random number between 1 and 3
    std::cout << rnd << std::endl;
    switch (rnd)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return nullptr;
    }

}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "this class is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "this class is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "this class is C" << std::endl;
    else
        std::cout << "this class is not A, B or C" << std::endl;
}

void identify(Base& p)
{
    try {
        A& test = dynamic_cast<A&>(p);
        std::cout << "this class is A" << std::endl;
        (void)test;
        return;
    }   catch (const std::bad_cast&) {
    }
    try {
        B& test = dynamic_cast<B&>(p);
        std::cout << "this class is B" << std::endl;
        (void)test;
        return;
    }   catch (const std::bad_cast&) {
    }
    try {
        C& test = dynamic_cast<C&>(p);
        std::cout << "this class is C" << std::endl;
        (void)test;
        return;
    }   catch (const std::bad_cast&) {
    }
    std::cout << "this class is not A, B or C" << std::endl;
}
