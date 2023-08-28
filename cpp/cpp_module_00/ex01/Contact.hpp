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
    void        info( int i );
    std::string get_input( std::string str );
    std::string cut_string( std::string str);

    private:
    
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    int         index;
};

#endif