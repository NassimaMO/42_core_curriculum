#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy ) : value(copy.value)
{
    std::cout << "Copy constructor called" << std::endl;
    setRawBits( copy.getRawBits() );
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits( copy.getRawBits() );
    return *this;
}

int     Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return ( value );
}

void    Fixed::setRawBits( int const raw )
{
    value = raw;
}