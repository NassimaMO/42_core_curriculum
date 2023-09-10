/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:25:05 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:25:05 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// do not necessarily have a weapon
#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
    this->m_name = name;
    std::cout << "HumanB \"" << m_name << "\" created." << std::endl;
}

HumanB::~HumanB( void )
{
    std::cout << "HumanB \"" << m_name << "\" destroyed." << std::endl;
}

void    HumanB::attack( void )
{
    if (this->m_weapon->getType().empty())
        return (std::cout << this->m_name << " don't have any weapon therefore" << this->m_name << " may not attack." << std::endl, void());
    std::cout << this->m_name << " attacks with their " << this->m_weapon->getType() << std::endl;
}

void    HumanB::setWeapon( Weapon  &weapon )
{
    this->m_weapon = &weapon;
}