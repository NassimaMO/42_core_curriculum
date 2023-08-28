/* instance : repertoire */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook( void )
{
}

PhoneBook::~PhoneBook( void )
{
}

void    PhoneBook::add( void )
{
    static int  num;

    this->contacts[num].init(num);
    if (this->total_numbers < 8)
        this->total_numbers++;
    if (num < 7)
        num++;
    return ;
}

void    PhoneBook::index( int index )
{
    if (index == -1)
        this->total_numbers = 0;
    else
        this->contacts[index].display();
}

void PhoneBook::get_index( void )
{
    int         num = -1;

    if (this->total_numbers == 0)
        return (void(std::cout << "Nevermind. You have no friends. Go outside and touch some grass." << std::endl));
    while (true)
    {
        std::cout << " - " << std::flush;
        //std::cin.ignore();
        std::cin >> num;
        std::cout << std::endl;
        if (num > this->total_numbers - 1)
            std::cout << "huuum look closely..." << std::endl;
        else if (num < 0 || num > 7)
            std::cout << "Not what I asked." << std::endl;
        else
        {
            this->contacts[num].display();
            break;
        }
        //std::cin.clear();
    }
}

void    PhoneBook::search( void )
{
    int i = 0;

    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "|index     |first name|last name |nickname  |" << std::endl;
    while (i < this->total_numbers)
    {
        this->contacts[i].info( i );
        i++;
    }
    std::cout << " -------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Which contact do you want to display ?" << std::endl;
    this->get_index();
}