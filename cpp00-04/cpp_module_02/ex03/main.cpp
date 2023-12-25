/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:24:31 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/22 13:53:41 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
    Point   ptOne( 1, 1 );
    Point   ptTwo( 1, 1 );
    Point   ptThree( 1, 1 );
    Point   point( 1, 1 );

    std::cout << bsp(ptOne, ptTwo, ptThree, point) << std::endl;
    return 0;
}
