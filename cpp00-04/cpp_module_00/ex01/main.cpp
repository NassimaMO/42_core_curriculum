/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:50 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:26:50 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

void    start( void )
{
    std::cout << "Welcome to YOUR personal phonebook !!" << std::endl;
    std::cout << "You may ADD or SEARCH for contacts ! WAOW !! Just say the word ! I mean write it." << std::endl;
    std::cout << "Once you're done, you can EXIT whenever you want !" << std::endl;
}

int main ( void )
{
    std::string input;
    PhoneBook The_PhoneBook;

    start();
    while (std::cin.good() && input.compare("EXIT"))
    {
        
        if (!input.compare("ADD"))
            The_PhoneBook.add();
        else if (!input.compare("SEARCH"))
            The_PhoneBook.search();
        else if (!input.empty())
            std::cout << "WHAT EXACTLY DO YOU EXPECT FROM MEEEEE ?!?!??" << std::endl;
        if (std::cin.good())
            std::cout << "SO WHAT DO YOU WANT ? ------> " << std::flush;
        std::getline(std::cin, input);
    }
}