/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:31 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:24:32 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
    this->m_name = name;
    std::cout << "Zombie " << this->m_name << " created." << std::endl;
}

Zombie::Zombie( void )
{
    /**/
}

Zombie::~Zombie( void )
{
    std::cout << "Zombie " << this->m_name << " destroyed." << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << this->m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}