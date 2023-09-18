#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    public:

    Fixed();
    Fixed( const Fixed& copy );
    Fixed( const int x );
    Fixed( const float x );
    ~Fixed();

    Fixed&  operator=(const Fixed& copy);
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;

    private:

    int                 value;
    static const int    fractionalBits = 8; 

};

std::ostream& operator<<(std::ostream& os, const Fixed& cp);

#endif