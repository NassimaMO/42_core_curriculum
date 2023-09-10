/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:46 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:24:46 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class   Zombie
{
    public:

    Zombie( std::string name );
    Zombie ( void );
    ~Zombie ( void );
    void announce ( void );
    void giveName( std::string name );

    private:

    std::string m_name;
};

Zombie  *zombieHorde( int N, std::string name );

#endif