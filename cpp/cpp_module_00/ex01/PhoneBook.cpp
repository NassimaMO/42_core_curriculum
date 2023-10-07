/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:52 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/12 16:04:37 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* instance : repertoire */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>

PhoneBook::PhoneBook( void )
{
    this->m_total_numbers = 0;
}

PhoneBook::~PhoneBook( void )
{
}

void    PhoneBook::add( void )
{
    static int  num;

    this->m_contacts[ num  % 8 ].init( num % 8 );
    if (this->m_total_numbers < 8)
        this->m_total_numbers++;
    num++;
    return ;
}

void    PhoneBook::index( int index )
{
    this->m_contacts[index].display();
}

void PhoneBook::get_index( void )
{
    std::string index;
    std::string ValidNums( "01234567" );
    size_t      found;

    if (this->m_total_numbers == 0)
        return (void(std::cout << "Nevermind. You have no friends. Go outside and touch some grass." << std::endl));
    while (std::cin.good())
    {
        getline(std::cin, index);
        found = index.find_first_not_of(ValidNums);
        if (found != std::string::npos || atoi(index.c_str()) > this->m_total_numbers - 1)
            std::cout << "Not what I asked." << std::endl;
        else if (!index.empty())
        {                
            this->m_contacts[atoi(index.c_str())].display();
            break;
        }
    }
}

void    PhoneBook::search( void )
{
    int index = 0;

    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "|index     |first name|last name |nickname  |" << std::endl;
    while (index < this->m_total_numbers)
    {
        this->m_contacts[index].info( index );
        index++;
    }
    std::cout << " -------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Which contact do you want to display ?" << std::endl;
    this->get_index();
}