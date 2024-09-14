#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <string>
# include <stack>
# include <sstream>
class RPN
{
    private:
        std::stack<std::string> _stack;
    public:
        //Constructers and Destructers
        RPN(void);
        RPN(std::string input);
        RPN(const RPN& src);
        RPN &operator=(const RPN &src);
        ~RPN();

        //Getters and Setters

        //Functions
        void calculate(int level);
        void check_input(const std::string &input);
        //Execptions
};

#endif

