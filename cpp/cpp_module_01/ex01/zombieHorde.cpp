/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:48 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:24:48 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde( int N, std::string name )
{
    Zombie *zoom;
    zoom = new Zombie[N];
    for ( int i = 0; i < N; i++ )
    {
        std::cout << i << " created." << std::endl;
        zoom[i].giveName( name );
    }
    std::cout << std::endl;
    return ( zoom );
}