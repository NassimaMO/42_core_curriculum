/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:05 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:26:06 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
    Harl Harlette;

    std::cout << std::endl;
    Harlette.complain( "DEBUG" );
    std::cout << std::endl;
    Harlette.complain( "INFO" );
    std::cout << std::endl;
    Harlette.complain( "WARNING" );
    std::cout << std::endl;
    Harlette.complain( "ERROR" );
    std::cout << std::endl;
    Harlette.complain( "huhuh" );
    std::cout << std::endl;
    
    return (0);
}