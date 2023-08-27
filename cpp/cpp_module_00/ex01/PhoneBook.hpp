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

    private:

    Contact contacts[8];
    void    start( void );
    void    add( void );
    void    search( void );
    void    index( int i );
    
};

#endif