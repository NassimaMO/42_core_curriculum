#include "AMateria.hpp"

AMateria::AMateria( std::string const & type )
{
    this->type = type;
}

AMateria::AMateria( const AMateria& cp )
{
    *this = cp;
}

AMateria& AMateria::operator=( const AMateria& cp )
{
    type = cp.type;
    return ( *this );
}

AMateria::~AMateria( void )
{
}

std::string const & AMateria::getType( void ) const
{
    return (type);
}

AMateria* AMateria::clone( void ) const
{
    /*return (new AMateria(*this));*/
}

void AMateria::use( ICharacter& target )
{
    std::cout << "* Using AMateria on " << target.getName() << " *" << std::endl;
}