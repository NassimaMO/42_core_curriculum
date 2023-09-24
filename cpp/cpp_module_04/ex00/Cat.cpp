#include "Cat.hpp"
#include <iostream>

Cat::Cat( void )
{
    type = "Cat";
    std::cout << "Cat created." << std::endl;
}

Cat::Cat( const Cat& cp )
{
    *this = cp;
}

Cat& Cat::operator=( const Cat& cp)
{
    if (this != &cp)
    {
        type = "Cat";
    }
    return ( *this );
}

Cat::~Cat( void )
{
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound( void ) const
{
    std::cout << "*Cat noise*" << std::endl;
}

std::string Cat::getType( void ) const
{
    return ( type );
}