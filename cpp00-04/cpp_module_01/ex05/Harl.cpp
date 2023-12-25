/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:00 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/18 16:05:15 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
    std::cout << "Harl created." << std::endl;
}
Harl::~Harl( void )
{
    std::cout << "Harl destroyed." << std::endl;
}

void    Harl::complain( std::string level )
{
    void		(Harl::*func_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string tab[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    int lvl = 0;

    while ( lvl < 4 )
    {
        if ( !level.compare( tab[lvl] ) )
        {
            std::cout << "[ " << tab[lvl] << " ]" << std::endl;
            (this->*func_ptr[lvl])();
            return;
        }
        lvl++;
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}