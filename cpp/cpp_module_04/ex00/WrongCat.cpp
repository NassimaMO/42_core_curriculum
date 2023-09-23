#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void )
{
    type = "WrongCat";
    std::cout << "WrongCat created." << std::endl;
}

WrongCat::WrongCat( const WrongCat& cp )
{
    *this = cp;
}

WrongCat& WrongCat::operator=( const WrongCat& cp)
{
    type = "WrongCat";
    return ( *this );
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destroyed." << std::endl;
}

/*void WrongCat::makeSound( void ) const
{
    std::cout << "*WrongCat noise*" << std::endl;
}*/

std::string WrongCat::getType( void ) const
{
    return ( type );
}