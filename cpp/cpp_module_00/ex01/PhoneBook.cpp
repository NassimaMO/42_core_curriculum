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

    this->m_contacts[num].init(num);
    if (this->m_total_numbers < 8)
        this->m_total_numbers++;
    if (num < 7)
        num++;
    return ;
}

void    PhoneBook::index( int index )
{
    this->m_contacts[index].display();
}

void PhoneBook::get_index( void )
{
    int index;

    if (this->m_total_numbers == 0)
        return (void(std::cout << "Nevermind. You have no friends. Go outside and touch some grass." << std::endl));
    while (true)
    {
        std::cout << " - " << std::flush;
        std::cin >> index;
        if (std::cin.fail())
        {
            std::cout << "Not what I asked. Bye" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            break;
        }
        else if (index > this->m_total_numbers - 1)
            std::cout << "huuum look closely..." << std::endl;
        else if (index < 0 || index > 7)
            std::cout << "NO" << std::endl;
        else
        {
            this->m_contacts[index].display();
            std::cin.clear();
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
    std::cin.ignore();
}