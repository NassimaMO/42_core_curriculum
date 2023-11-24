#include "Ice.hpp"

Ice::Ice( void )
{
    type = "ice";
}

Ice::Ice( const Ice& cp )
{
    *this = cp;
}

Ice& Ice::operator=( const Ice& cp )
{
    type = cp.type;
    return ( *this );
}

Ice::~Ice( void )
{
}

Ice* Ice::clone( void )
{
    return (new Ice());
}

void Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target->name << " *" << std::endl;
}

