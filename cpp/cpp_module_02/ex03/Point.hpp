/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:24:54 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/22 13:24:56 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    const Fixed    getX( void ) const;
    const Fixed    getY( void) const;

    private:

    const Fixed x;
    const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
