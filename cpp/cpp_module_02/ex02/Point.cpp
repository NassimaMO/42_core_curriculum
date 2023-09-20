#include "Point.hpp"

Point::Point( void ) : x(0), y(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Point::Point( const float _x, const float _y ) : x(_x), y(_y)
{
    std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point& cp)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cp;
}

Point::~Point()
{
    std::cout << "Destructor called" << std::endl;
}

void    Point::setCoord( const Fixed& _x, const Fixed& _y )
{
    x = _x;
    y = _y;
}

const Fixed&    Point::getX( void ) const
{
    return ( this->x );
}

const Fixed&    Point::getY( void) const
{
    return ( this->y );
}

Point&   Point::operator=(const Point& cp)
{
    setCoord( cp.getX(), cp.getY() );
    return ( *this );
}
