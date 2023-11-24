#include "Cure.hpp"

Cure::Cure( void )
{
    type = "cure";
}

Cure::Cure( const Cure& cp )
{
    *this = cp;
}

Cure& Cure::operator=( const Cure& cp )
{
    type = cp.type;
    return ( *this );
}

Cure::~Cure( void )
{
}

Cure* Cure::clone( void )
{
    return (new Cure());
}

void Cure::use( ICharacter& target )
{
    std::cout << "* heals " << target->name << "'s wounds *" << std::endl;
}
