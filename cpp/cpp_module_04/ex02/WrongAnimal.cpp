#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal")
{
    std::cout << "WrongAnimal created." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& cp )
{
    *this = cp;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& cp)
{
    type = cp.type;
    return ( *this );
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destroyed." << std::endl;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "*WrongAnimal noise*" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
    return ( type );
}