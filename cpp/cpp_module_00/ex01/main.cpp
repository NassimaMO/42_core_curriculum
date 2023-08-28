#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

void    start( void )
{
    std::cout << "Welcome to YOUR personal phonebook !!" << std::endl;
    std::cout << "You may ADD or even SEARCH for contacts ! WAOW !! Just say the word ! I mean write it." << std::endl;
    std::cout << "Once you're done, you can EXIT whenever you want !" << std::endl;
}

int main ( void )
{
    std::string input;
    PhoneBook The_PhoneBook;

    start();
    The_PhoneBook.index(-1);
    while (input.compare("EXIT"))
    {
        if (!input.compare("ADD"))
            The_PhoneBook.add();
        else if (!input.compare("SEARCH"))
            The_PhoneBook.search();
        else if (!input.empty())
            std::cout << "WHAT DO YOU EXACTLY EXPECT FROM MEEEEE ?!?!??" << std::endl;
        std::cout << "SO WHAT DO YOU WANT ? ------> " << std::flush;
        std::getline(std::cin, input);
    }
}