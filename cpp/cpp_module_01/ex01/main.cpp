/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:41 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:24:41 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
    int N = 5;
    Zombie  *zoom = zombieHorde( N, "Christian" );

    for ( int i = 0; i < N; i++ )
        zoom[i].announce();
    delete [] zoom;
}