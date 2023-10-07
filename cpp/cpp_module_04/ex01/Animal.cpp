#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) : type("Animal")
{
    std::cout << "Animal created." << std::endl;
}

Animal::Animal( const Animal& cp )
{
    *this = cp;
}

Animal& Animal::operator=( const Animal& cp)
{
    if (this != &cp)
    {
        type = cp.type;
    }
    return ( *this );
}

Animal::~Animal( void )
{
    std::cout << "Animal destroyed." << std::endl;
}

void Animal::makeSound( void ) const
{
    std::cout << "*Animal noise*" << std::endl;
}

std::string Animal::getType( void ) const
{
    return ( type );
}