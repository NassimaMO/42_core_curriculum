/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:25:16 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:25:16 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string _type )
{
    this->type = _type;
    std::cout << "Weapon of type \"" << type << "\" created." << std::endl;
}

Weapon::~Weapon( void )
{
    std::cout << "Weapon of type \"" << type << "\" destroyed." << std::endl;
}

const std::string&  Weapon::getType( void )
{
    return ( this->type );
}

void    Weapon::setType( std::string _type )
{
    this->type = _type;
}