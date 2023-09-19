#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed( const int x ) : value( x << fractionalBits )
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float x ) : value( roundf( x * ( 1 << fractionalBits ) ) )
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
    os << cp.toFloat(); 
    return os;
}

float   Fixed::toFloat( void ) const
{
    return ( static_cast<float>(value) / ( 1 << fractionalBits ) );
}

int     Fixed::toInt( void ) const
{
    return ( value >> fractionalBits );
}