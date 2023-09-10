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

    Harlette.complain( "DEBUG" );
    Harlette.complain( "INFO" );
    Harlette.complain( "WARNING" );
    Harlette.complain( "ERROR" );
    
    return (0);
}