/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:24:36 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:24:37 by nmouslim         ###   ########.fr       */
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

    private:

    std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif