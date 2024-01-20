#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <list>

class NotFound : public std::exception
{
    public:

    const char* what() const throw();
};

template <typename T>
bool    easyfind( T& container, int n )
{
    if ( std::find( container.begin(), container.end(), n ) != container.end() )
        return ( true );
    throw NotFound();
    return ( false );
}

#endif