#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
    std::cout << "Ice type AMateria created." << std::endl;
}

Ice::Ice( const Ice& cp ) : AMateria("ice")
{
    *this = cp;
}

Ice& Ice::operator=( const Ice& cp )
{
    ( void )cp;
    return ( *this );
}

Ice::~Ice( void )
{
    std::cout << "Ice type AMateria destroyed." << std::endl;
}

Ice* Ice::clone( void ) const
{
    std::cout << "Cloning Ice AMateria." << std::endl;
    return ( new Ice( *this ) );
}

void Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

