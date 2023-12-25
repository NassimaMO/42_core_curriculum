/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:25:08 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:25:08 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class   HumanB
{
    public:

    HumanB( std::string _name );
    ~HumanB( void );
    void    attack( void );
    void    setWeapon( Weapon &_weapon );

    private:

    Weapon      *weapon;
    std::string name;
};

#endif