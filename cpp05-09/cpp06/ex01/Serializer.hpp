#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct  Data
{
    int num;
};

class   Serializer
{
    public:

    Serializer( void );
    Serializer( const Serializer& s );
    Serializer&         operator=( const Serializer& s );
    ~Serializer();

    /*It takes a pointer and converts it to the unsigned integer type uintptr_t*/
    static uintptr_t    serialize(Data* ptr);
    /*It takes an unsigned integer parameter and converts it to a pointer to Data.*/
    static Data*        deserialize(uintptr_t raw);

    virtual void        toNotInitialize( void ) = 0;
};

#endif