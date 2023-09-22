#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& cp )
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = cp;
}

Fixed::Fixed( const int x ) : value( x << fractionalBits )
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float x ) : value( roundf( x * ( 1 << fractionalBits ) ) )
{
    std::cout << "Fixed Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& cp)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    setRawBits( cp.getRawBits() );
    return ( *this );
}

int     Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return ( value );
}

void    Fixed::setRawBits( int const raw )
{
    value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& cp)
{
    os << cp.toFloat(); 
    return ( os );
}

float   Fixed::toFloat( void ) const
{
    return ( static_cast<float>(value) / ( 1 << fractionalBits ) );
}

int     Fixed::toInt( void ) const
{
    return ( value >> fractionalBits );
}

bool     Fixed::operator>( const Fixed& cp ) const
{
    if ( this->toFloat() > cp.toFloat() )
        return ( 1 );
    return ( 0 );
}

bool     Fixed::operator<( const Fixed& cp ) const
{
    if ( this->toFloat() < cp.toFloat() )
        return ( 1 );
    return ( 0 );
}

bool     Fixed::operator>=( const Fixed& cp ) const
{
    if ( this->toFloat() >= cp.toFloat() )
        return ( 1 );
    return ( 0 );
}

bool     Fixed::operator<=( const Fixed& cp ) const
{
    if ( this->toFloat() <= cp.toFloat() )
        return ( 1 );
    return ( 0 );
}

bool     Fixed::operator==( const Fixed& cp ) const
{
    if ( this->toFloat() == cp.toFloat() )
        return ( 1 );
    return ( 0 );
}

bool     Fixed::operator!=( const Fixed& cp ) const
{
    if ( this->toFloat() != cp.toFloat() )
        return ( 1 );
    return ( 0 );
}

Fixed     Fixed::operator+( const Fixed& cp ) const
{
    return ( this->toFloat() + cp.toFloat() );
}

Fixed     Fixed::operator-( const Fixed& cp ) const
{
    return ( this->toFloat() - cp.toFloat() );
}

Fixed     Fixed::operator*( const Fixed& cp ) const
{
    return ( this->toFloat() * cp.toFloat() );
}

Fixed     Fixed::operator/( const Fixed& cp ) const
{
    return ( this->toFloat() / cp.toFloat() );
}

Fixed& Fixed::min( Fixed& a, Fixed& b )
{
    if ( a < b )
        return ( a );
    return ( b );
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b )
{
    if ( a.toFloat() < b.toFloat() )
        return ( a );
    return ( b );
}

Fixed& Fixed::max( Fixed& a, Fixed& b )
{
    if ( a > b )
        return ( a );
    return ( b );
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b )
{
    if ( a.toFloat() > b.toFloat() )
        return ( a );
    return ( b );
}

Fixed     Fixed::operator--( void )
{
    this->value--;
    return ( *this );
}

Fixed     Fixed::operator--( int x )
{
    Fixed   tmp(*this);

    this->value--;
    (void) x;
    return ( tmp );
}

Fixed     Fixed::operator++( void )
{
    this->value++;
    return ( *this );
}

Fixed     Fixed::operator++( int x )
{
    Fixed   tmp(*this);

    (void) x;
    this->value++;
    return ( tmp );
}