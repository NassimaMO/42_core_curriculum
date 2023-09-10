/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:25:20 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:25:20 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class   Weapon
{
    public:

    Weapon( std::string type );
    ~Weapon( void );
    const std::string&      getType( void );
    void                    setType( std::string type );

    private:

    std::string m_type;
};

#endif