/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:22:06 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/22 13:22:07 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class   Fixed
{
    public:

    Fixed( void );
    Fixed( const Fixed& copy );
    ~Fixed();
    Fixed&   operator=(const Fixed& copy);
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

    private:

    int                value;
    static const int   fractionalBits = 8; 

};

#endif
