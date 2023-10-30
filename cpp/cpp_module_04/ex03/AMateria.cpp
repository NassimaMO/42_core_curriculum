#include "AMateria.hpp"

AMateria::AMateria( std::string const & type )
{
    type = type;
}

AMateria::AMateria( const AMateria& cp )
{
    this = cp;
}

AMateria::AMateria& operator=( const AMateria& cp )
{
    type = cp->type;
}

Ice::~Ice( void )
{
}

AMateria::std::string const & getType( void ) const
{
    return (type);
}

AMateria::AMateria* clone( void )
{
    return (new AMateria(type));
}

AMateria::virtual void use( ICharacter& target )
{
    std::cout << "* Using AMateria on " << target->name << " *" << std::endl;
}