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

HumanA::HumanA( std::string name, Weapon &weapon ) : m_weapon(weapon), m_name(name)
{
    std::cout << "HumanA \"" << m_name << "\" created." << std::endl;
}

HumanA::~HumanA( void )
{
    std::cout << "HumanA \"" << m_name << "\" destroyed." << std::endl;
}

void    HumanA::attack( void )
{
    std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}