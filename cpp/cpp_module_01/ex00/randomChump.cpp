/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:28 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:24:29 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Crée un zombie, lui donne un nom et le fait se présenter. */

#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie  zoom( name );
    zoom.announce();
}