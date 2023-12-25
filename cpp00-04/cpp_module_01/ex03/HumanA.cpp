/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:25:00 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:25:00 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string _name, Weapon &_weapon ) : weapon(_weapon), name(_name)
{
    std::cout << "HumanA \"" << name << "\" created." << std::endl;
}

HumanA::~HumanA( void )
{
    std::cout << "HumanA \"" << name << "\" destroyed." << std::endl;
}

void    HumanA::attack( void )
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}