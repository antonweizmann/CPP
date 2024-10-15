#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <string>
# include "Data.hpp"
class Serializer
{
    public:
        //Constructers and Destructers

        //Getters and Setters
        Serializer(void) = delete;
        Serializer(const Serializer& src) = delete;
        Serializer &operator=(const Serializer &src) = delete;
        ~Serializer() = delete;

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

