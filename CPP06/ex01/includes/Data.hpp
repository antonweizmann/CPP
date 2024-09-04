#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>
# include <string>

class Data
{
    public:
        int _data;
        //Constructers and Destructers
        Data(void);
        Data(const Data& src);
        Data &operator=(const Data &src);
        ~Data();

        //Getters and Setters
        //Functions

        //Execptions
};

#endif

