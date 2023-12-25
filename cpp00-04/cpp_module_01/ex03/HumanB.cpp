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

HumanB::HumanB( std::string _name )
{
    this->name = _name;
    std::cout << "HumanB \"" << name << "\" created." << std::endl;
}

HumanB::~HumanB( void )
{
    std::cout << "HumanB \"" << name << "\" destroyed." << std::endl;
}

void    HumanB::attack( void )
{
    if (this->weapon->getType().empty())
        return (std::cout << this->name << " don't have any weapon therefore" << this->name << " may not attack." << std::endl, void());
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon( Weapon  &_weapon )
{
    this->weapon = &_weapon;
}