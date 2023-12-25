/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <nmouslim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:26:55 by nmouslim          #+#    #+#             */
/*   Updated: 2023/09/10 17:26:56 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{

    public:

    PhoneBook( void );
    ~PhoneBook( void );
    void    add( void );
    void    search( void );
    void    index( int index );
    void    get_index( void );

    private:

    Contact m_contacts[8];
    int     m_total_numbers;

};

#endif