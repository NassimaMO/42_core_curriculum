#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    public:

    Fixed();
    Fixed( const Fixed& cp );
    Fixed( const int x );
    Fixed( const float x );
    ~Fixed();

    Fixed&  operator=(const Fixed& cp);
    int     operator>(const Fixed& cp);
    int     operator<(const Fixed& cp);
    int     operator>=(const Fixed& cp);
    int     operator<=(const Fixed& cp);
    int     operator==(const Fixed& cp);
    int     operator!=(const Fixed& cp);

    float     operator+(const Fixed& cp);
    float     operator-(const Fixed& cp);
    float     operator*(const Fixed& cp);
    float     operator/(const Fixed& cp);

    Fixed     operator--(void);
    Fixed     operator--(int x);
    Fixed     operator++(void);
    Fixed     operator++(int x);

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

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