/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:04:15 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/14 18:26:02 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
    Zombie zombieOne( "Bryan" );
    Zombie *zombieTwo;

    zombieOne.announce();
    zombieTwo = newZombie( "Jeff" );
    zombieTwo->announce();
    randomChump( "Alejandro" );
    zombieTwo->~Zombie();
}