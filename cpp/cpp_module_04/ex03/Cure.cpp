#include "Cure.hpp"

Cure::Cure( void )
{
    type = "cure";
}

Cure::Cure( const Cure& cp )
{
    this = cp;
}

Cure::Cure& operator=( const Cure& cp )
{
    return (new Cure());
}

Cure::~Cure( void )
{
}

Cure::Cure* clone( void )
{
    return (new Cure());
}

Cure::void use( ICharacter& target )
{
    std::cout << "* heals " << target->name << "'s wounds *" << std::endl;
}
