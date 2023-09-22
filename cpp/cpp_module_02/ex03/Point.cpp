#include "Point.hpp"

Point::Point( void ) : x(0), y(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Point::Point( const float _x, const float _y ) : x(_x), y(_y)
{
    std::cout << "Point Default constructor called" << std::endl;
}

Point::Point(const Point& cp) : x(0), y(0)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = cp;
}

Point::~Point()
{
    //std::cout << "Destructor called" << std::endl;
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
    (void) cp;
    return ( *this );
}
