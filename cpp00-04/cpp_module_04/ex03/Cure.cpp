#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
    std::cout << "Cure type AMateria created." << std::endl;
}

Cure::Cure( const Cure& cp ) : AMateria("cure")
{
    *this = cp;
}

Cure& Cure::operator=( const Cure& cp )
{
    ( void )cp;
    return ( *this );
}

Cure::~Cure( void )
{
    std::cout << "Cure type AMateria destroyed." << std::endl;
}

Cure* Cure::clone( void ) const
{
    std::cout << "Cloning Cure AMateria." << std::endl;
    return ( new Cure( *this ) );
}

void Cure::use( ICharacter& target )
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
