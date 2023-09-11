/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:44 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:42:26 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* instance : contacts */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string    Contact::get_input( std::string str )
{
    std::string input = "";

    while (true)
    {
        std::cout << str;
        std::getline(std::cin, input);
        if (!input.empty())
            break;
        std::cout << "naahhh come on, tell me." << std::endl;
    }
    return (input);
};

void    Contact::init( int index )
{
    this->m_first_name = this->get_input( "Enter your first name: ");
    this->m_last_name = this->get_input( "Enter your last name: " );
    this->m_nickname = this->get_input( "Enter your nickname: " );
    this->m_phone_number = this->get_input( "Enter your phone number: " );
    this->m_darkest_secret = this->get_input( "Enter your darkest secret: " );
    this->m_index = index;
    std::cout << "Ouuhhh spicyyy !! " << std::endl;
};

void    Contact::display( void )
{
    std::cout << "First name: " << this->m_first_name << std::endl;
    std::cout << "Last name: " << this->m_last_name << std::endl;
    std::cout << "Nickname: " << this->m_nickname << std::endl;
    std::cout << "Phone number: " << this->m_phone_number << std::endl;
    std::cout << "Darkest secret: " << this->m_darkest_secret << std::endl;
}

std::string Contact::cut_string( std::string str)
{
    if (str.length() > 10)
        return (str.erase(9, str.length()) + ".");
    return (str);
}

void    Contact::info( int index )
{
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << this->cut_string(this->m_first_name);
    std::cout << "|" << std::setw(10) << this->cut_string(this->m_last_name);
    std::cout << "|" << std::setw(10) << this->cut_string(this->m_nickname);
    std::cout << "|" << std::endl;
}