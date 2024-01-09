#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>

template <class T>
class   Array
{
    private:

    T   elem;

    public:

    Array( void );
    Array( unsigned int n ); //Creates an array of n elements initialized by default.
    //Tip: Try to compile int * a = new int(); then display *a.?????
    Array( const Array& a );
    Array&  operator=( const Array& a );

}

#endif