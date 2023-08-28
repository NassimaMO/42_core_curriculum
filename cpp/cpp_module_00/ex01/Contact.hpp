#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
    public:

    Contact( void );
    ~Contact( void );
    void        init( int index );
    void        display( void );
    void        info( int index );
    std::string get_input( std::string str );
    std::string cut_string( std::string str);

    private:
    
    std::string m_first_name;
    std::string m_last_name;
    std::string m_nickname;
    std::string m_phone_number;
    std::string m_darkest_secret;
    int         m_index;
};

#endif