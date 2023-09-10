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

Weapon::Weapon( std::string type )
{
    this->m_type = type;
    std::cout << "Weapon of type \"" << m_type << "\" created." << std::endl;
}

Weapon::~Weapon( void )
{
    std::cout << "Weapon of type \"" << m_type << "\" destroyed." << std::endl;
}

const std::string&  Weapon::getType( void )
{
    return ( this->m_type );
}

void    Weapon::setType( std::string type )
{
    this->m_type = type;
}