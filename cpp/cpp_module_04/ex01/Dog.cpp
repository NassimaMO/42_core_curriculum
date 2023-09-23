#include "Dog.hpp"
#include <iostream>

Dog::Dog( void )
{
    type = "Dog";
    std::cout << "Dog created." << std::endl;
}

Dog::Dog( const Dog& cp )
{
    *this = cp;
}

Dog& Dog::operator=( const Dog& cp)
{
    type = "Dog";
    return ( *this );
}

Dog::~Dog( void )
{
    std::cout << "Dog destroyed." << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "*Dog noise*" << std::endl;
}

std::string Dog::getType( void ) const
{
    return ( type );
}