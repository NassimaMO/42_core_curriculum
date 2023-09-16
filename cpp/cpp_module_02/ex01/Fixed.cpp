#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy ) : value(copy.value)
{
    std::cout << "Copy constructor called" << std::endl;
    setRawBits( copy.getRawBits() );
}

Fixed::Fixed( const int x )// : value(x)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float x )// : value(x)
{
    std::cout << "Float constructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& cp)
{
    //os << cp.toFloat();
    //os << cp.toInt();
    return os;
}

float   Fixed::toFloat( void ) const
{
/**/
}

int     Fixed::toInt( void ) const
{
/**/
}