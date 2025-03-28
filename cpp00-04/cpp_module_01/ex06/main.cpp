/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:05 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/18 16:10:18 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( int argc, char **argv )
{
    Harl Harlette;

    if ( argc != 2 )
        return ( std::cout << "SAY SOMETHING" << std::endl, 1 );
    std::cout << std::endl;
    Harlette.complain( argv[1] );
    
    return ( 0 );
}