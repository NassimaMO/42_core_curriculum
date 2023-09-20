#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class   Point
{
    public:

    Point( void );
    Point( const float _x, const float _y );
    Point( const Point& cp );
    Point&   operator=(const Point& cp);
    ~Point();

    void      setCoord( const Fixed& _x, const Fixed& _y );
    const Fixed&    getX( void ) const;
    const Fixed&    getY( void) const;

    private:

    const Fixed x;
    const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif