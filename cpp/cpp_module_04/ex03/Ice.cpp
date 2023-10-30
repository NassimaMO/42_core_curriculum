#include "Ice.hpp"

Ice::Ice( void )
{
    type = "ice";
}

Ice::Ice( const Ice& cp )
{
    this = cp;
}

Ice::Ice& operator=( const Ice& cp )
{
    return (new Ice());
}

Ice::~Ice( void )
{
}

Ice::Ice* clone( void )
{
    return (new Ice());
}

Ice::void use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target->name << " *" << std::endl;
}

