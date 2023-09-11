/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:02 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:26:03 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# define DEBUG 0
# define INFO 1
# define WARNING 2
# define ERROR 3

# include <string>
# include <iostream>

class   Harl
{
    public:

    Harl( void );
    ~Harl( void );
    void    complain( std::string level );

    private:

    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );

};

#endif