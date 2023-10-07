/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:24:43 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/22 13:48:33 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(Fixed(0)), y(Fixed(0))
{
    //std::cout << "Default constructor called" << std::endl;
}

Point::Point( const float _x, const float _y ) : x(Fixed(_x)), y(Fixed(_y))
{
    //std::cout << "Point Default constructor called" << std::endl;
}

Point::Point(const Point& cp) : x(cp.x), y(cp.y)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
    //std::cout << "Destructor called" << std::endl;
}

const Fixed    Point::getX( void ) const
{
    return ( x );
}

const Fixed    Point::getY( void) const
{
    return ( y );
}

Point&   Point::operator=(const Point& cp)
{
    (void) cp;
    return ( *this );
}
