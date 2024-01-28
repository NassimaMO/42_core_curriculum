#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <list>

template <typename T>
bool    easyfind( T& container, int n )
{
    if ( std::find( container.begin(), container.end(), n ) != container.end() )
        return ( true );
    return ( false );
}

#endif