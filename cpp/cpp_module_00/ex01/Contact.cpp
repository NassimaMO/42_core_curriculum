/* instance : contacts */

#include "Contact.hpp"

Contact::Contact(/* args */)
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
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (!input.empty())
            break;
        std::cin.clear();
        std::cout << "naahhh come on, tell me." << std::endl;
    }
    return (input);
};

void    Contact::init( int index )
{
    this->first_name = this->get_input( "Enter your first name: ");
    this->last_name = this->get_input( "Enter your last name: " );
    this->nickname = this->get_input( "Enter your nickname: " );
    this->phone_number = this->get_input( "Enter your phone number: " );
    this->darkest_secret = this->get_input( "Enter your darkest secret: " );
    this->index = index;
    std::cout << "Ouuhhh spicyyy !! " << std::endl;
};

void    Contact::display( void )
{
    std::cout << "First name: " << this->first_name << std::endl;
    std::cout << "Last name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone number: " << this->phone_number << std::endl;
    std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}

std::string Contact::cut_string( std::string str)
{
    if (str.length() > 10)
        return (str.erase(9, str.length()) + ".");
    return (str);
}

void    Contact::info( int i )
{
    std::cout << "|" << std::setw(10) << i << std::flush;
    std::cout << "|" << std::setw(10) << this->cut_string(this->first_name) << std::flush;
    std::cout << "|" << std::setw(10) << this->cut_string(this->last_name) << std::flush;
    std::cout << "|" << std::setw(10) << this->cut_string(this->nickname) << std::flush;
    std::cout << "|" << std::endl;
}