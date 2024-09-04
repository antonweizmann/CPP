#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <string>
# include "Data.hpp"
class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer& src);
        Serializer &operator=(const Serializer &src);
        ~Serializer();
    public:
        //Constructers and Destructers

        //Getters and Setters

        //Functions
        static uintptr_t serialize(Data* ptr)
        {
            return reinterpret_cast<uintptr_t>(ptr);
        }
        static Data* deserialize(uintptr_t raw)
        {
            return reinterpret_cast<Data*>(raw);
        }
        //Execptions
};

#endif

