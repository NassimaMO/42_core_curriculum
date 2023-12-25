/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:23 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:24:24 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Crée un zombie, lui donne un nom et le retourne afin qu’il puisse être utilisé en
dehors de la portée de la fonction. */

#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    return ( new Zombie ( name ) );
}
