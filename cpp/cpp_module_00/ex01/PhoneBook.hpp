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