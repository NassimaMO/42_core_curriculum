#include "easyfind.hpp"
#include <iostream>
#include <time.h>

const char* NotFound::what() const throw()
{
    return ( "Number not found." );
}

int main( void )
{
    std::vector < int > v;
    int            size = 10;
    time_t  t;
    srand(time(&t));

    for ( int i = 0; i < size; i++ )
        v.push_back( rand() % 10 );

    std::cout << "container: ";
    for ( std::vector< int >::const_iterator i = v.begin(); i != v.end(); i++ )
        std::cout << *i << ' ';

    std::cout << std::endl;
    try
    {
        std::cout << easyfind( v, 22 ) << std::endl;
    }
    catch ( std::exception &e )
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}